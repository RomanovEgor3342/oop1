#include <iostream>
#include <vector>


#include "includes/Ship.h"
#include "includes/ShipManager.h"
#include "includes/GameField.h"


// using namespace std;

// int generateRandomNumber(int min, int max) {
//     // Создаем генератор случайных чисел с использованием текущего времени в качестве семени
//     static std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
    
//     // Создаем равномерное распределение для диапазона [min, max]
//     std::uniform_int_distribution<> distribution(min, max);
    
//     // Генерируем и возвращаем случайное число
//     return distribution(gen);
// }

int main(){
    GameField field(10, 10);
    GameField enemyField(10, 10);

    ShipManager manager(10, std::vector<int>{1, 1,1, 1, 2,2, 2, 3,3, 4});
    ShipManager botManager(10, std::vector<int>{1, 1,1, 1, 2,2, 2, 3,3, 4});

    std::vector<std::shared_ptr<Ship>> ships = manager.getShips();
    std::vector<std::shared_ptr<Ship>> botShips = botManager.getShips();

    for (auto &ship : ships){
        field.placeShipOnRandCoords(ship);
    }

    // int a = 0;
    // for (int i = 0; i < 1000000000; i++){
    //     a +=1;
    // }
    for (auto &ship : botShips){
        enemyField.placeShipOnRandCoords(ship);
    }

    // for (int i = 0; i < 10; i++){
    //     field.placeShipOnCoords();
    //     enemyField.placeShipOnCoords()
    // }


    // field.placeShipOnCoords(ships[0], Coordinates{3, }, Orientation::Horizontal);
    // int min = 1;
    // int max = 100;

    // for (int i =0; i < 10; i++){
    //     std::cout << "Случайное число в диапазоне [" << min << ", " << max << "]: " << generateRandomNumber(min, max) << std::endl;
    // }
    field.printField();

    // enemyField.damagePoint(Coordinates {3, 5});

    enemyField.printField();

    // auto now =;

    // Преобразуем в миллисекунды


    // std::cout << " " << timeInMillis << std::endl;

    return 0;
}



