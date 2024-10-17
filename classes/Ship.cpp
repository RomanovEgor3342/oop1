#include "../includes/Ship.h"

Ship::Ship(ShipLengths size) noexcept:
    headPosition(Coordinates{0, 0}), orientation(Orientation::Horizontal),
    status(ShipStatus::Intact){
        for (int i = 0; i < static_cast<int>(size); ++i) {
            segments.push_back(
                std::make_shared<ShipSegment>(
                    ShipSegment{
                        Coordinates{0, 0}, 
                        ShipStatus::Intact
                    }
                )
            );
        }
    };


bool Ship::isDestroyed() noexcept{
    for (auto &seg : segments){
        if (seg->status != ShipStatus::Destroyed) {
            return false;
        }
    }
    return true;
}

int Ship::getLength() noexcept{
    return segments.size();
}

void Ship::changeOrientation(Orientation newOrientation) noexcept{
    if (orientation != newOrientation) {
        this->orientation = newOrientation;
        setPosition(this->headPosition);
    }
}
void Ship::setPosition(Coordinates coords){

    if (coords.x < 0 || coords.y < 0){
        throw std::out_of_range("Incorrect coordinates");
    }

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
    throw std::runtime_error("Incorrect segment index");
}

void Ship::updateStatus() noexcept{
    
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

void Ship::printShip() noexcept{

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

    std::cout << std::string(2 * colWidth, '_') << "\n\n";  
}
