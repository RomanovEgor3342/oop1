#include "../includes/Ship.h"

// Ship::Ship(int size, Orientation orint, Coordinates headPositionPosition) 
//     : length(size), orientation(orint), headPosition(headPositionPosition){
//         for (int i = 0; i < size; i++){
//             segments.emplace_back(
//                 (orientation == Orientation::Vertical) ?
//                 Coordinates{headPosition.x, headPosition.y + i} :
//                 Coordinates{headPosition.x + i, headPosition.y},
//                 ShipStatus::Intact
//             );
//         }
//     };



Ship::Ship(int size):
    headPosition(Coordinates{0, 0}), orientation(Orientation::Horizontal),
    status(ShipStatus::Intact){
        for (int i = 0; i < size; ++i) {
            ShipSegment segment(Coordinates{0, 0}, ShipStatus::Intact);
            segments.push_back(std::make_shared<ShipSegment>(segment));
        }
    };


bool Ship::isDestroyed(){
    for (auto &seg : segments){
        if (seg->status != ShipStatus::Destroyed) {
            return false;
        }
    }
    return true;
}

int Ship::getLength(){
    return segments.size();
}

void Ship::changeOrientation(Orientation newOrientation){
    // this->orientation = newOrientation;
    if (orientation != newOrientation) {
        this->orientation = newOrientation;
        setPosition(this->headPosition);
    }
}
void Ship::setPosition(Coordinates coords){
    this->headPosition = coords;
    for (int i = 0; i < segments.size(); i++){
        segments[i]->coords = (orientation == Orientation::Vertical) 
            ? Coordinates{coords.x, coords.y + i} 
            : Coordinates{coords.x + i, coords.y};
        }
}

std::shared_ptr<ShipSegment> Ship::getSegment(unsigned int index){
    if (index < segments.size()){
        return segments[index];
    } 
    std::cout << "Incorrect segment index " << index << '\n';
    return nullptr;
}


void Ship::updateStatus(){
    if (this->isDestroyed()){
        this->status = ShipStatus::Destroyed;
        return;
    }

    for (auto &seg : segments){
        if (seg->status != ShipStatus::Intact){
            this->status = ShipStatus::Damaged;
            return;
        }
    }
}

void Ship::printShip(){

    int colWidth = 15;

    std::cout << "---------Ship params----------" << "\n";
    
    std::cout << std::left << std::setw(colWidth) << "Length" 
         << std::setw(colWidth) << segments.size() << "\n";

    std::cout << std::left << std::setw(colWidth) << "Status" 
         << std::setw(colWidth) 
         << ((status == ShipStatus::Intact) ? "Intact"
            : (status == ShipStatus::Destroyed) ? "Destroyed" : "Dameged") << "\n";

    std::cout << std::left << std::setw(colWidth) << "Orientation" 
         << std::setw(colWidth) 
         << ((orientation == Orientation::Vertical) ? "Vertical" : "Horizontal") << "\n";

    std::cout << std::left << std::setw(colWidth) << "Position" 
         << "(" << headPosition.x << "; " << headPosition.y << ")" << "\n";

    // std::cout << std::left << std::setw(colWidth) << "Segment" 
    //      << std::setw(colWidth) << "Coordinates" << "\n";
    // std::cout << std::string(2 * colWidth, '-') << "\n";

    // for (size_t i = 0; i < segments.size(); ++i) {
    //     std::cout << std::left << std::setw(colWidth) << ("Segment ") 
    //          << '{' << segments[i]->coords.x << ", " << segments[i]->coords.y << "}" << "\n";
    // }

    std::cout << std::string(2 * colWidth, '_') << "\n\n";  
}
