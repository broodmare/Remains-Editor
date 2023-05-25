#pragma once

#include <string>


class tile
{
	private:
	std::string name;
	int id;

	//tile initializer. Defines what a tile has and initializes it.
	public:
		tile(std::string name, int id); 

};
