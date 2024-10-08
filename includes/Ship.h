#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include <iostream>
#include "Point.h" // Заголовочный файл для класса Point
#include "Structures.h"

using namespace std;

class Ship {
private:
    int length;
    Coordinates head; // Предположим, что это правильное название
    Orientation orientation;
    vector<ShipSegment> segments;
    ShipStatus status;
    // int Id;

public:
    Ship(int size, Orientation orint, Coordinates headPosition);

    

    // PointStates getSegmentStatus(Coordinates coords);
    // Coordinates getHeadCoordinates();
    // Orientation getOrientation();

    // bool isDestroyed();
    // int getLength();

    // void damageSegment(Coordinates coords);
    // void printShip();
};

#endif