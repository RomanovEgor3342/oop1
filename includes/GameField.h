#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "Structures.h"
#include "Ship.h"
#include "Point.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <stdexcept>
// #include <ctime>
#include <chrono>

// using namespace std;

class GameField{
private:
    int width;
    int height;
    std::vector<std::vector<Point>> field;
    void checkCoordsValidity(Coordinates coords);
    // std::mt19937 gen;
public:
    GameField(int rows, int columns) noexcept;
    void placeShipOnCoords(std::shared_ptr<Ship> &ship, Coordinates coords, Orientation orint, bool useDebug = true);
    void placeShipOnRandCoords(std::shared_ptr<Ship> &ship) noexcept;
    void damagePoint(Coordinates coords);
    void printField() noexcept;

};

#endif