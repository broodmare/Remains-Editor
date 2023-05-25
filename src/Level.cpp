#include <string>
#include <utility>
#include <vector>

#include "Level.h"
#include "Room.h"


//Initialize a level.
//Add the weird asterisk because we don't know some details about the room yet.
level::level(std::string name, std::vector<room*> rooms)
: name(std::move(name)), rooms(std::move(rooms)) {}