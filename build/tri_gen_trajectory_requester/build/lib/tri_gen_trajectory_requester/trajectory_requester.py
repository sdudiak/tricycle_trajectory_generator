import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rclpy.duration import Duration

from tri_gen_msgs.srv import GenerateTrajectory
from tri_gen_msgs.msg import State

class TrajectoryRequester(Node):
    def __init__(self):
        super().__init__('trajectory_requester')
        self.declare_parameters('', [
            ('start.x', 0.0), ('start.y', 0.0), ('start.theta', 0.0),
            ('start.phi', 0.0), ('start.omega_phi', 0.0), ('start.v', 0.0),
            ('goal.x', 0.0), ('goal.y', 0.0), ('goal.theta', 0.0),
            ('goal.phi', 0.0), ('goal.omega_phi', 0.0), ('goal.v', 0.0),
            ('dt', 0.1),
            ('phi_min', -0.5), ('phi_max', 0.5),
            ('omega_phi_min', -1.0), ('omega_phi_max', 1.0),
            ('v_min', -1.0), ('v_max', 1.0),
            ('a_min', -1.0), ('a_max', 1.0)
        ])

        self.cli = self.create_client(GenerateTrajectory, 'generate_trajectory')
        while not self.cli.wait_for_service(timeout_sec=2.0):
            self.get_logger().info('Waiting for service...')

        self.send_request()

    def build_state(self, prefix):
        state = State()
        state.x = self.get_parameter(f"{prefix}.x").value
        state.y = self.get_parameter(f"{prefix}.y").value
        state.theta = self.get_parameter(f"{prefix}.theta").value
        state.phi = self.get_parameter(f"{prefix}.phi").value
        state.omega_phi = self.get_parameter(f"{prefix}.omega_phi").value
        state.v = self.get_parameter(f"{prefix}.v").value
        state.stamp_from_start = Duration(seconds=0).to_msg()
        return state

    def send_request(self):
        request = GenerateTrajectory.Request()
        request.start = self.build_state('start')
        request.goal = self.build_state('goal')
        request.dt = self.get_parameter('dt').value
        request.phi_min = self.get_parameter('phi_min').value
        request.phi_max = self.get_parameter('phi_max').value
        request.omega_phi_min = self.get_parameter('omega_phi_min').value
        request.omega_phi_max = self.get_parameter('omega_phi_max').value
        request.v_min = self.get_parameter('v_min').value
        request.v_max = self.get_parameter('v_max').value
        request.a_min = self.get_parameter('a_min').value
        request.a_max = self.get_parameter('a_max').value

        future = self.cli.call_async(request)
        future.add_done_callback(self.callback)

    def callback(self, future):
        try:
            response = future.result()
            self.get_logger().info(f"Success: {response.success}")
            self.get_logger().info(f"Message: {response.message}")
            self.get_logger().info(f"Generation time ms: {response.generation_time_ms}")

            
    
            if response.success:
                self.get_logger().info(f"Received {len(response.trajectory.states)} states and {len(response.trajectory.controls)} controls.")
    
                print("\nTrajectory States:")
                for i, state in enumerate(response.trajectory.states):
                    print(f"  [{i}] t={state.stamp_from_start.sec + state.stamp_from_start.nanosec * 1e-9:.2f}s | "
                          f"x={state.x:.2f}, y={state.y:.2f}, theta={state.theta:.2f}, "
                          f"phi={state.phi:.2f}, omega_phi={state.omega_phi:.2f}, v={state.v:.2f}")
    
                print("\nTrajectory Controls:")
                for i, control in enumerate(response.trajectory.controls):
                    duration = control.duration.sec + control.duration.nanosec * 1e-9
                    print(f"  [{i}] duration={duration:.2f}s | "
                          f"omega_phi={control.omega_phi:.2f}, a={control.a:.2f}")
    
        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")
        finally:
            rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    node = TrajectoryRequester()
    rclpy.spin(node)

if __name__ == '__main__':
    main()
