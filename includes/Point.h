#ifndef POINT_H
#define POINT_H

#include <memory>
#include "Structures.h"

class Point {
private:
    PointStates state;
    Coordinates position;
    std::unique_ptr<ShipSegment> shipSegPtr;

public:
    Point(PointStates state, Coordinates coords);
    void changeState(PointStates newState);
    void setCoordinates(Coordinates newCoords);
    PointStates getPointState();
    Coordinates getPosition();
};

#endif