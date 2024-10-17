#include "../includes/ShipManager.h"


ShipManager::ShipManager(int shipsAmount, std::vector<ShipLengths> sizes) noexcept{
    for (int i = 0; i < shipsAmount; i++){
        ships.emplace_back(std::make_shared<Ship>(sizes[i]));
    }
}

void ShipManager::updateShips() noexcept{
    for (auto &ship : ships){
        ship->updateStatus();
    }
}

void ShipManager::printShips() noexcept{
    this->updateShips();
    for (auto &ship : ships){
        ship->printShip();
    }
}

std::vector<std::shared_ptr<Ship>> ShipManager::getShips() noexcept{
    this->updateShips();
    return ships;
}