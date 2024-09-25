#ifndef SHIPMANAGER_H
#define SHIPMANAGER_H

#include <vector>
#include <iostream>
#include "Ship.h"

using namespace std;

class ShipManager{
private:

    vector<Ship> ships;

public:
    // ShipManager(int shipsAmount, vector<int> lengths);

    // void addShip(shared_ptr<Ship> &newShip);
    // void attackShipByCoordiantes(Coordinates coords);

    void setDamageToSegment(Coordinates coords);




};

#endif