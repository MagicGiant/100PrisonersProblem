#include <iostream>
#include <vector>
#include <ostream>
#include <ctime>
#include <cstdlib>

//---------
// Константы кторые надо менять при запуске
const int MAX_BOXES = 100;
const int MAX_ATTEMPTS = 99;
const int SIMULATION_ITERATIONS = 100000;

//---------
class box{
public:
    // Номер коробки
    int box_id;
    // Номер внутри коробки
    int box_number;

    box(int box_id, int box_number){
        this->box_id = box_id;
        this->box_number = box_number;
    }

    bool try_open(int prison_number){
        return box_number == prison_number;
    }

    friend std::ostream& operator<<(std::ostream& os, const box& b);
};

std::ostream& operator<<(std::ostream& os, const box& b){
    os << b.box_number;
    return os;
}

//---------
//генерирует набор случайных неповторяющихся чисел
std::vector<int> generate_non_repeating_numbers(int count){
    std::vector<int> numbers(count, 0);
    for (unsigned i = 0; i < count; ++i)
    {
        unsigned j = rand() % (i + 1);
        numbers[i] = numbers[j];
        numbers[j] = i;
    }
    return numbers;
}
//---------
//генеринует коробки случайным образом
std::vector<box> generate_random_boxes(){
    std::vector<int> box_numbers = generate_non_repeating_numbers(MAX_BOXES);
    std::vector<box> boxes;
    for(int i = 0; i < MAX_BOXES; i++){
        boxes.push_back(box(i, box_numbers[i]));
    }
    return boxes;
}
//---------
// функции для открытия коробки один раз. Тоесть заключенный заходит в комнату
// и либо правильно открывает коробку, либо неправильно за MAX_ATTEMPTS попыток

// это при открытии случаным образом
bool try_open_with_random_boxes(std::vector<box>& boxes, int prison_number){
    std::vector<int> attempts = generate_non_repeating_numbers(MAX_ATTEMPTS);
    for(int i = 0; i < MAX_ATTEMPTS; i++){
        if (boxes[attempts[i]].try_open(prison_number)){
            return true;
        }
    }
    return false;
}

// это при открытии со специальным алгоритмом
bool try_open_with_algorithm(std::vector<box>& boxes, int prison_number){
    int current_box_number = prison_number;

    for(int i = 0; i < MAX_ATTEMPTS; i++){
        if (boxes[current_box_number].try_open(prison_number)){
            return true;
        }
        current_box_number = boxes[current_box_number].box_number;
    }
    return false;
}
//---------

//Сама симуляция, которая возвращает нам шансы заключенных
//при использовании разных стратегий
template<typename Try_algorithm>
double box_opening_simulation(Try_algorithm algorithm){

    int successful_iterations = 0;
    

    for (int i = 0; i < SIMULATION_ITERATIONS; i++){

        std::vector<box> boxes = generate_random_boxes();
        bool flag = true;
        for (int j = 0; j < MAX_BOXES; j++)
        {
            if (!algorithm(boxes, j)){
                flag = false;
                break;
            }
        }
        
        if (flag){
            successful_iterations++;
        }
    }
    return (double)successful_iterations / SIMULATION_ITERATIONS;
}

int main()
{
    srand((unsigned)time(0));

    std::cout << "Algorithm: random algorithm" << std::endl;
    std::cout << box_opening_simulation(try_open_with_random_boxes) << std::endl;
    std::cout << "Algorithm: special algorithm" << std::endl;
    std::cout << box_opening_simulation(try_open_with_algorithm);
    return 0;
}