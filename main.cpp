#include <iostream>
#include <vector>

#include "includes/Point.h"
#include "includes/Ship.h"
#include "includes/ShipManager.h"
#include "includes/GameField.h"

int main(){
    GameField field(10, 10);
    GameField enemyField(10, 10);

    ShipManager manager(4, std::vector<ShipLengths>{ONE, ONE, FOUR, FOUR});
    // ShipManager manager(3, std::vector<int>{1, 1, 4});
    // ShipManager botManager(10, std::vector<int>{1, 1,1, 1, 2,2, 2, 3,3, 4});

    std::vector<std::shared_ptr<Ship>> ships = manager.getShips();
    // std::vector<std::shared_ptr<Ship>> botShips = botManager.getShips();

    for (auto &ship : ships){
        field.placeShipOnRandCoords(ship);
    }

    // GameField newField = std::move(field);
    field.printField();
    // newField.printField();

    // Point point(PointStates::Attacked, Coordinates{2,2});
    // Point newPoint(point);

    // point.printPoint();
    // newPoint.printPoint();


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
    // field.printField();

    // enemyField.damagePoint(Coordinates {3, 5});

    // enemyField.printField();

    // auto now =;

    // Преобразуем в миллисекунды


    // std::cout << " " << timeInMillis << std::endl;

    return 0;
}



