#pragma once

class room;

class level
{

	private:

		std::string name;
		//Define a level as an array of rooms.
	    std::vector<room*> rooms;


	public:
		level(std::vector<room*> rooms)
		    : rooms(std::move(rooms)) {}
		level(std::string name, std::vector<room*> rooms);



	//Define functions to get info.
	const std::string& getName() const;
	const std::vector<room*>& getRooms() const;

	//Define functions to set info.
	void setName(const std::string& name);
	void setRooms(const std::vector<room*>& rooms);

};