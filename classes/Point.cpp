#include "../includes/Point.h"


Point::Point(PointStates state, Coordinates coords){
    this->state = state;
    this->position = coords;
}

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
