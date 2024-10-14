#include "../includes/Point.h"


Point::Point(PointStates state, Coordinates coords)
    : state(state), position(coords), shipSegPtr(nullptr){};

void Point::changeState(PointStates newState) {
    state = newState;
}
// void Point::setCoordinates(Coordinates newCoords){
//     this->position = newCoords;
// }

PointStates Point::getPointState(){
    return state;
}
void Point::setPtrOnSegment(std::shared_ptr<ShipSegment> segment) {
    shipSegPtr = segment;
}

void Point::changeShipSegmentByPtr(ShipStatus newState){
    shipSegPtr->status = newState;
}
// Coordinates Point::getPosition(){
//     return position;

// }
