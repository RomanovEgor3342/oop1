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
    vector<Point> shipSegments;
    ShipStatus status;
    // int Id;

public:
    Ship(int len, Orientation orint, int headX, int headY);

    PointStates getSegmentStatus(Coordinates coords);
    Coordinates getHeadCoordinates();
    Orientation getOrientation();

    bool isDestroyed();
    int getLength();

    void damageSegment(Coordinates coords);
    void printShip();
};

#endif