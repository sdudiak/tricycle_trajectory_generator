# tricycle_trajectory_generator

## Description

This repository contains the code for evaluating the trajectory generation for a tricycle vehicle. It contains the following packages:
- `tri_gen_msgs` - containing necessary ROS2 interfaces
- `tri_gen_trajectory_requester` - containing a simple node used for requesting a trajectory
- `tri_gen_trajectory_generator` - containing a node responsible for trajectory generation based on solving an NLP problem

## Usage
After downloading this repository, build and run the docker container:
``` bash
cd tricycle_trajectory_generator/docker
docker compose build
docker compose up
```
You should see a running rviz window. To select trajectory parameters use the `trajectory_request.yaml` file. When the parameters are selected, in a separate terminal run:

```
docker exec -t tricycle_trajectory_generator /request_trajectory.sh
```

In rviz:

- **Red** arrow is the goal state
- **Yellow** arrow is the start state
- **Green** represent the vechicle's position and orientation
- **Blue** arrow represents the wheel's orientation

## Self assesment

1. Które aspekty zadania były dla Ciebie najtrudniejsze i dlaczego?

    Poprawne sformułowanie problemu optymalizacyjnego w casadi. Poświęciłem temu zdecydowanie najwięcej czasu. Nie znalazłem dobrej dokumentacji do C++ i sztuczna inteligencja równierz nie była zbyt pomocna.

2. Jakich narzędzi i technik użyłeś i jak wpłynęły na rozwiązanie?

    Narzędziem którego używałem zdecydowanie najwięcej jest biblioteka casadi. Dzięki temu aplikację łatwo było rozłożyć na część ROS'ową która jest odpowiedzialna za komunikację, i część faktycznego generowania trajektorii, która jest od ROS'a prawie zupełnie niezależna. 
3. Jak testowałeś poprawność swojej trajektorii?
    Poprawność mojej trajektorii nie jest sprawdzana przez żadną "zewnętrzną" aplikację - obecnie zakładam że rozwiązanie problemu NLP spełnia zadane ograniczenia. Przy większej ilości czasu można byłoby dodać `trajectory_checker` który iteracyjnie sprawdza czy stany i sterowania spełniają założenia, oraz `goal_checker`, który sprawdza czy końcowy stan znajduje się w pewnym marginesie błędu od celu.
4.  Czy wszystkie ograniczenia kinematyczne zostały zachowane? Jak to werykowałeś?
    Ograniczenia kinematyczne są zapewniane przez `trajectory_generator.cpp line:166`. Ten fragment kodu zapewnia, że kolejne kroki generowanej trajektorii zachowują się zgodnie z modelem kinematycznym zadanym z zadaniu. 
5. Czy istnieją przypadki, w których Twój generator nie zadziała? Jakie?
    Zależy jak zdefiniujemy "nie działa". Rzadko zdarza się, że podane parametry wywołają rzucenie wyjątku przez generator. Często jednak zdarza się, że robot nie osiąga w pełni zadanego stanu na końcu. Jest to spowodowane:
        
    - Funkcją kosztu użytą w NLP. Żeby uprościć zadanie, najważniejsze są pozycje x oraz y. Orientacja robota ma mniejszy koszt, więc nie zawsze zostanie osiągana. Końcowa prędkość oraz orientacja koła w ogóle nie są brane pod uwagę. Łatwo można to zmienić.
    - Liczba kroków `N`. Ze względu na rozwiązywanie problemu ze stałym krokiem, ilość kroków jakie wykonuje generator jest bardzo istotna. Obecnie jest ona estymowana na podstawie maksymalnej prędkości, dt, oraz dystansu do celu. Jeżeli jedak wybierzemy bardzo daleki cel i ustawimy niskie maksymalne przyspieszenie, robot może nigdy nie osiągnąć maksymalnej prędkośći a tym samym celu. Lepsza metoda dobierania liczby kroków lub metoda ze zmienną długością kroku mogłyby rozwiązać ten problem 
6. Jeśli miałbyś kolejne 2 dni, co byś usprawnił?
Zdecydowanie dodałbym metodę gdzie czas danego sterowania może się zmieniać. Szkic tej metody jest obecny w kodzie źródłowym, ale nie zdążyłem go dokończyć. Dodałbym równierz parametryzację głównego node'a. Obecnie wszystkie wartości są wpisane na sztywno. Dodanie pliku `config.yaml` na pewno pomogłoby z testowaniem (można by łatwo zmieniać parametry optymalizatora, funkcji kosztu etc.). Kolejną rzeczą do dodania są testy jednostkowe. Ostatecznie można równierz dodać bardziej ogólną klasę bazową `TrajectoryGenerator`, która pozwoliłaby na łatwe wykorzystanie innych metod do generowania trajektorii (np. Hybrid A*)

7. Czy coś Cię zaskoczyło podczas pracy nad tym zadaniem?
Byłem bardzo pozytywnie zaskoczony tym jak szybko działa casadi. Spodziewałem się dużo dłuższego czasu obliczeń. Rzeczą która na początku trochę "zbiła mnie z tropu" był fakt, że w modelu kinematycznym robota prędkość liniowa nie była uwzględniona jako zmienna stanu. Przez niedoczytanie postaci sterowania, założyłem że sterujemy bezpośrednio prędkością i że robot osiąga ją momentalnie po zadaniu. To równierz doprowadziło do komplikacji podczas dodawania ograniczeń na przyspieszenie w NLP. Na szczęście poprawienie tej pomyłki nie było zbyt trudne.