#include "../includes/Point.h"


Point::Point(PointStates state, Coordinates coords) noexcept
    : state(state), position(coords), shipSegPtr(nullptr){};

Point::Point(const Point &other) noexcept 
    : state(other.state), position(other.position){
        if (other.shipSegPtr) {
            shipSegPtr = std::make_shared<ShipSegment>(*other.shipSegPtr);
        } else {
            shipSegPtr = nullptr;
        }
    }


void Point::changeState(PointStates newState) noexcept{
    state = newState;
}

PointStates Point::getPointState() noexcept{
    return state;
}
void Point::setPtrOnSegment(std::shared_ptr<ShipSegment> segment) noexcept{
    shipSegPtr = segment;
}

void Point::changeShipSegmentByPtr(ShipStatus newState) noexcept{
    shipSegPtr->status = newState;
}
