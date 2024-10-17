#ifndef SHIPMANAGER_H
#define SHIPMANAGER_H

#include <vector>
#include <iostream>
#include "Ship.h"


class ShipManager{
private:
    std::vector<std::shared_ptr<Ship>> ships;
    void updateShips() noexcept;

public:
    ShipManager(int shipsAmount, std::vector<ShipLengths> sizes) noexcept;
    ~ShipManager() noexcept {};

    std::vector<std::shared_ptr<Ship>> getShips() noexcept;
    void printShips() noexcept;

};

#endif