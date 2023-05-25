#pragma once


class tile;


class room
{
	private:
	std::string name;
	std::pair<int, int> coordinates;
	std::vector<tile*> tiles;

	//Room initializer. Defines what a room has and initializes it.
	public:
		room(std::string name, std::pair<int, int> coordinates, std::vector<tile*> tiles);


};