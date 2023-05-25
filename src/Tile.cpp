#include "Tile.h"


//Initialize a tile.
tile::tile(std::string name, int id)
    : name(std::move(name)), id(id) {}

//Methods to retrieve information about a room.
const std::string& tile::getName() const
{
    return name;
}

int tile::getId() const
{
    return id;
}

//Methods to set information about a room.
void tile::setName(const std::string& name)
{
    this->name = name;
}
void tile::setId(const int id)
{
    this->id = id;
}

