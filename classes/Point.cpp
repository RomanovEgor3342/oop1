#include "../includes/Point.h"


Point::Point(PointStates state, Coordinates coords)
    : state(state), position(coords), shipSegPtr(nullptr){};

void Point::changeState(PointStates newState) {
    state = newState;
}
void Point::setCoordinates(Coordinates newCoords){
    this->position = newCoords;
}

PointStates Point::getPointState(){
    return state;
}

Coordinates Point::getPosition(){
    return position;
}
