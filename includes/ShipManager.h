#ifndef SHIPMANAGER_H
#define SHIPMANAGER_H

#include <vector>
#include <iostream>
#include "Ship.h"

// using namespace std;

class ShipManager{
private:

    std::vector<std::shared_ptr<Ship>> ships;
    void updateShips();

public:
    ShipManager(int shipsAmount, std::vector<int> sizes);

    std::vector<std::shared_ptr<Ship>> getShips();
    void printShips();



};

#endif