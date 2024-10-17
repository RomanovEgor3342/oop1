#ifndef POINT_H
#define POINT_H

#include <memory>
#include <iostream>
#include "Structures.h"

class Point {
private:
    PointStates state;
    Coordinates position;
    std::shared_ptr<ShipSegment> shipSegPtr;

public:
    Point(PointStates state, Coordinates coords) noexcept;
    Point(const Point &other) noexcept;
    ~Point () noexcept {};

    void changeState(PointStates newState) noexcept;
    // void setCoordinates(Coordinates newCoords);
    PointStates getPointState() noexcept;
    // Coordinates getPosition();
    void setPtrOnSegment(std::shared_ptr<ShipSegment> segment) noexcept;
    void changeShipSegmentByPtr(ShipStatus newState) noexcept;

    // void printPoint();
};

#endif