#include "../includes/ShipManager.h"


ShipManager::ShipManager(int shipsAmount, std::vector<int>sizes){
    for (int i = 0; i < shipsAmount; i++){
        ships.emplace_back(std::make_shared<Ship>(sizes[i]));
    }
}

void ShipManager::updateShips(){
    for (auto &ship : ships){
        ship->updateStatus();
    }
}

void ShipManager::printShips(){
    this->updateShips();
    for (auto &ship : ships){
        ship->printShip();
    }
}

std::vector<std::shared_ptr<Ship>> ShipManager::getShips(){
    return ships;
}