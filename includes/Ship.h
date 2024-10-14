#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include <iomanip>
#include <iostream>
#include "Point.h" // Заголовочный файл для класса Point
#include "Structures.h"

// using namespace std;

class Ship {
private:
    // int length;
    Coordinates headPosition; // Предположим, что это правильное название
    Orientation orientation;
    std::vector<std::shared_ptr<ShipSegment>> segments;
    ShipStatus status;
    // int Id;

public:
    Ship(int size);

    bool isDestroyed();
    void setPosition(Coordinates coords);
    void changeOrientation(Orientation newOrientation);
    void updateStatus();
    std::shared_ptr<ShipSegment> getSegment(unsigned int index);
    int getLength();

    void printShip();
};

#endif