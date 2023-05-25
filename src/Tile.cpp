#include "Tile.h"


//Initialize a tile.
tile::tile(std::string name, int id)
    : name(std::move(name)), id(id) {}