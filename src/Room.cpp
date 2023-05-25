#include <string>
#include <vector>

#include "Room.h"
#include "Tile.h"


	//Initialize a room.
	room::room(std::string name, std::pair<int, int> coordinates, std::vector<tile*> tiles)
    : name(std::move(name)), coordinates(coordinates), tiles(std::move(tiles)) {}

