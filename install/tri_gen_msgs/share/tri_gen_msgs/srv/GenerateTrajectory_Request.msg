# Service for generating a trajectory between a start and goal state,
# given dynamic and geometric constraints.

State start # initial state
State goal # goal state
float64 dt # trajectory sampling time step (in seconds)
float64 phi_min
float64 phi_max
float64 omega_phi_min
float64 omega_phi_max
float64 v_min
float64 v_max
float64 a_min
float64 a_max
