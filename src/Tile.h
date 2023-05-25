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


	//Define functions to get info.
	const std::string& getName() const;
	int getId() const;

	//Define functions to set info.
	void setName(const std::string& name);
	void setId(int id);

};
