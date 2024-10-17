#ifndef SHIP_H
#define SHIP_H

#include <vector>
#include <iomanip>
#include <iostream>
#include "Point.h" 
#include "Structures.h"


class Ship {
private:
    Coordinates headPosition;
    Orientation orientation;
    std::vector<std::shared_ptr<ShipSegment>> segments;
    ShipStatus status;


public:
    Ship(ShipLengths size) noexcept;
    ~Ship() noexcept {};

    void changeOrientation(Orientation newOrientation) noexcept;
    void updateStatus() noexcept;
    void printShip() noexcept;

    bool isDestroyed() noexcept; 
    int getLength() noexcept;
    
    void setPosition(Coordinates coords);
    std::shared_ptr<ShipSegment> getSegment(unsigned int index);

};

#endif