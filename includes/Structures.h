#ifndef STRUCTURES_H
#define STRUCTURES_H

enum class PointStates {
    Empty,
    Ship,
    DamagedShip,
    DestroyedShip,
    Unknown,
};

enum class Orientation{
    Vertical,
    Hotizontal
};

enum class ShipStatus{
    Intact,
    Damaged,
    Destroyed
};

struct Coordinates{
    int x;
    int y;

    bool operator==(const Coordinates &other) const {
        return x == other.x && y == other.y;
    }
};
#endif