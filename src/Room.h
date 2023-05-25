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


	//Define functions to get info.
	const std::string& getName() const;
	const std::pair<int, int>& getCoordinates() const;
	const std::vector<tile*>& getTiles() const;

	//Define functions to set info.
	void setName(const std::string& name);
	void setCoordinates(const std::pair<int, int>& coordinates);
	void setTiles(const std::vector<tile*>& tiles);
};