#include "../includes/GameField.h"

GameField::GameField(int rows, int columns) noexcept:
    width(columns), height(rows){
        field.resize(height);

        for (int y = 0; y < height; ++y) {
            field[y].reserve(width);
            for (int x = 0; x < width; ++x) {
                field[y].emplace_back(PointStates::Unknown, Coordinates{x, y});
            }
        }
    }

GameField::GameField(const GameField &other) noexcept:
    width(other.width), height(other.height), field(other.field) {
    field.resize(height);
    for (int y = 0; y < height; ++y) {
        field[y].reserve(width);
        for (int x = 0; x < width; ++x) {
            field[y][x] = Point(other.field[y][x]);
        }
    }
}

GameField& GameField::operator=(const GameField& other) noexcept {
    if (this != &other) {
        width = other.width;
        height = other.height;
        field.resize(height);
        for (int y = 0; y < height; ++y) {
            field[y].reserve(width);
            for (int x = 0; x < width; ++x) {
                field[y][x] = Point(other.field[y][x]);
            }
        }
    }
    return *this;
}

GameField::GameField(GameField&& other) noexcept: height(other.height), width(other.width), field(std::move(other.field)) {
    other.height = 0;
    other.width = 0;
}

GameField& GameField::operator=(GameField&& other) noexcept{
    if (this != &other) {
        height = other.height;
        width = other.width;
        field = std::move(other.field);
        other.height = 0;
        other.width = 0;
    }
    return *this;
}

void GameField::checkCoordsValidity(Coordinates coords){
    if ((coords.x < 0 || coords.y < 0) || (coords.x >= width || coords.y >= height)){
        throw std::out_of_range("Incorrect coordinates");
        // return false;
    }
    // return true;
}

void GameField::printField() noexcept{
    std::cout<<"\n   ";
    for (int i = 0; i < width; i++){
        std::cout << (char)('A' + i)<<' ';
    }
    // r += 1;
    std::cout <<"\n  ";
    for (int i = 0; i < width; i++){
        std::cout << "--";
    }

    std::cout <<'\n';
    for (int x = 0; x < width; x++){
        std::cout << x << "| ";

        for (int y = 0; y < height; y++){
            switch (field[y][x].getPointState())
            {
            case PointStates::Ship:
                std::cout<< "\033[32m" <<"% "<< "\033[0m";
                break;
            case PointStates::DamagedShip:
                std::cout << "\033[33m" <<"\033[44m" << "# " << "\033[0m";
                break;

            case PointStates::DestroyedShip:
                std::cout << "\033[31m" << "X " << "\033[0m";
                break;
            case PointStates::Attacked:
                std::cout << "\033[35m" << "* " << "\033[0m";
                break;
            case PointStates::Unknown:
            default:
                std::cout  <<"+ " ;
                break;
            }
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

void GameField::placeShipOnCoords(
    std::shared_ptr<Ship> &ship,
    Coordinates coords,
    Orientation orint,
    bool useDebug
) {
    int length = ship->getLength();
    ship->changeOrientation(orint);

    try {
        checkCoordsValidity(coords);
    }
    catch(const std::exception& e) {
        throw;
    }
    
    int xStart = (coords.x > 0) ? coords.x - 1 : coords.x;
    int yStart = (coords.y > 0) ? coords.y - 1 : coords.y;

    int xEnd = (orint == Orientation::Vertical)
        ? ((coords.x  == width - 1) ? coords.x+1 : coords.x + 2)
        : ((coords.x + length != width) ? coords.x + length + 1 : coords.x + length);

    int yEnd = (orint == Orientation::Vertical)
        ? ((coords.y + length != height) ? coords.y + length + 1 : coords.y + length)
        : ((coords.y == height - 1) ? coords.y+1 : coords.y + 2);

    if (xEnd > width || yEnd > height){
        throw std::out_of_range("x or y is too big");
    }

    for (int x = xStart; x < xEnd; x++){
        for (int y = yStart; y < yEnd; y++){
            if (field[x][y].getPointState() == PointStates::Ship){
                throw std::runtime_error("place is unavalable");
            }
        }
    }

    for (int i = 0; i < length; i++){
        int x = (orint == Orientation::Vertical) ? coords.x : coords.x + i;
        int y = (orint == Orientation::Vertical) ? coords.y + i : coords.y;
        
        field[x][y].changeState(PointStates::Ship);
        field[x][y].setPtrOnSegment(ship->getSegment(i));
    }
    
    ship->setPosition(Coordinates{coords.x, coords.y});
}


void GameField::placeShipOnRandCoords(std::shared_ptr<Ship> &ship) noexcept{
    auto duration =  std::chrono::high_resolution_clock::now().time_since_epoch(); // Получаем длительность с начала эпохи
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    unsigned int timeInMillis = static_cast<unsigned int>(milliseconds);

    std::mt19937 gen(static_cast<unsigned int>(static_cast<unsigned int>(milliseconds)));    

    bool isShipPlaced = false;
    std::uniform_int_distribution<> dist(0, width+height);

    int rand_x = (int)(dist(gen) % width);
    int rand_y = (int)(dist(gen) % height);
    bool rand_ort = (int)(dist(gen)) % 2 == 0;

    while(!isShipPlaced){
        try {
            placeShipOnCoords(
                ship,
                Coordinates{rand_x, rand_y},
                ((rand_ort) ? Orientation::Horizontal : Orientation::Vertical),
                false
            );
            isShipPlaced = true;
        } catch (std::exception& e) {
            rand_x = (int)(dist(gen) % width);
            rand_y = (int)(dist(gen) % height);
            rand_ort = (int)(dist(gen)) % 2 == 0;
        } 
        
    }

}


void GameField::damagePoint(Coordinates coords){

    try {
        checkCoordsValidity(coords);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    PointStates oldState = field[coords.x][coords.y].getPointState();
    switch (oldState)
    {
    case PointStates::Ship:
        field[coords.x][coords.y].changeShipSegmentByPtr(ShipStatus::Damaged);
        field[coords.x][coords.y].changeState(PointStates::DamagedShip);
        break;

    case PointStates::DamagedShip:
        field[coords.x][coords.y].changeShipSegmentByPtr(ShipStatus::Destroyed);
        field[coords.x][coords.y].changeState(PointStates::DestroyedShip);
        break;
    
    case PointStates::Unknown:
    case PointStates::Empty:
        field[coords.x][coords.y].changeState(PointStates::Attacked);

    default:
        std::cout << "miss or ship here was already beaten\n";
        break;
    }
}
