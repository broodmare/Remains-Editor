#include <string>
#include <utility>
#include <vector>

#include "Level.h"
#include "Room.h"


//Initialize a level.
//Add the weird asterisk because we don't know some details about the room yet.
level::level(std::string name, std::vector<room*> rooms)
: name(std::move(name)), rooms(std::move(rooms)) {}


//Methods to retrieve information about a level.
const std::string& level::getName() const
{
    return name;
}
const std::vector<room*>& level::getRooms() const
{
    return rooms;
}

//Methods to set information about a level.
void level::setName(const std::string& name)
{
    this->name = name;
}
void level::setRooms(const std::vector<room*>& rooms)
{
    this->rooms = rooms;
}