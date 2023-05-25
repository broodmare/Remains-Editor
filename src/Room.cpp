#include <string>
#include <vector>

#include "Room.h"
#include "Tile.h"


//Initialize a room.
room::room(std::string name, std::pair<int, int> coordinates, std::vector<tile*> tiles)
: name(std::move(name)), coordinates(coordinates), tiles(std::move(tiles)) {}


//Methods to retrieve information about a room.
const std::string& room::getName() const
{
    return name;
}
const std::pair<int, int>& room::getCoordinates() const
{
    return coordinates;
}
const std::vector<tile*>& room::getTiles() const
{
    return tiles;
}

//Methods to set information about a room.
void room::setName(const std::string& name)
{
    this->name = name;
}

void room::setCoordinates(const std::pair<int, int>& coordinates)
{
    this->coordinates = coordinates;
}

void room::setTiles(const std::vector<tile*>& tiles)
{
    this->tiles = tiles;
}