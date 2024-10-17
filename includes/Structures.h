#ifndef STRUCTURES_H
#define STRUCTURES_H

enum class PointStates {
    Empty,
    Ship,
    DamagedShip,
    DestroyedShip,
    Unknown,
    Attacked
};

enum class Orientation{
    Vertical,
    Horizontal
};

enum class ShipStatus{
    Intact,
    Damaged,
    Destroyed
};

enum ShipLengths{
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4
};

struct Coordinates{
    int x;
    int y;

    bool operator==(const Coordinates &other) const {
        return x == other.x && y == other.y;
    }
};

struct ShipSegment{
    Coordinates coords;
    ShipStatus status;

};

#endif