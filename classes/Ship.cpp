#include "../includes/Ship.h"



Ship::Ship(int size, Orientation orint, Coordinates headPosition) 
    : length(size), orientation(orint), head(headPosition){
        for (int i = 0; i < size; i++){
            segments[i] = ShipSegment(
                (orientation == Orientation::Vertical) ?
                Coordinates{head.x, head.y + i} :
                Coordinates{head.x + i, head.y},
                ShipStatus::Intact
            );
        }
    };


// void Ship::damageSegment(Coordinates coords){
//     for (auto &segment : shipSegments) {
//         if (segment.getPosition() == coords){
//             switch (segment.getPointState())
//             {
//             case PointStates::Ship:
//                 segment.changeState(PointStates::DamagedShip);
//                 break;
//             case PointStates::DamagedShip:
//                 segment.changeState(PointStates::DestroyedShip);
//                 break;
            
//             default:
//                 break;
//             }
//         }   
//     }

// }

// void Ship::printShip(){
//     cout << "Ship params:" << "\n"
//          << "Length: " << length << "\n"
//          << "Status: " << ((status == ShipStatus::Intact) 
//                 ? "Intact"
//                 : (status == ShipStatus::Destroyed) 
//                 ? "Damaged"
//                 : "Destroyed") << "\n"
//          << "Orientation: " << ((orientation == Orientation::Vertical) 
//                 ? "Vertical"
//                 : "Horizontal") << "\n"
//          << "Position: " << "(" << head.x << "; " << head.y << ")\n";

// }

// PointStates Ship::getSegmentStatus(Coordinates coords) {

//     for (auto &segment : shipSegments){
//         if (segment.getPosition() == coords){
//             return segment.getPointState();
//         }
//     }
// }

// bool Ship::isDestroyed(){
//     for (auto &segment : shipSegments) {
//         if (segment.getPointState() != PointStates::DestroyedShip){
//             return false;
//         }
//     }

//     return true;
// }


// int Ship::getLength(){
//     return this->length;
// }

// Coordinates Ship::getHeadCoordinates(){
//     return this->head;
// }

// Orientation Ship::getOrientation(){
//     return this->orientation;
// }
