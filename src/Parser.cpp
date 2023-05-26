
#include "Parser.h"

std::string fileName;
std::string roomString;

bool loading = false;

void GetData(const SDL_Event& event)
{


	if (event.key.keysym.sym == SDLK_h && loading == false)
	{
		loading = true;
		std::cout << "H key pressed.\n";
		

		std::cout << "Current path is " << std::filesystem::current_path() << '\n';
		std::cout << "File to open: ";
		std::cin >> fileName;
		std::cout << fileName << " selected.\n";

		std::ifstream roomData(fileName);
		if (roomData.is_open()) 
		{

			std::cout << fileName << " opened successfully.\n";
			//Create a buffer to place file data.
			std::stringstream buffer;
			//Load the file into buffer.
			buffer << roomData.rdbuf();
			//Create a string and import buffer data.
			roomString = buffer.str();

			loading = false;
		}
		else 
		{
			std::cout << "File failed to open.\n";
			loading = false;
		}
	}



	if (event.key.keysym.sym == SDLK_j && loading == false)
	{
		std::cout << "J key pressed.\n";

		if (!roomString.empty())
		{
			std::cout << "Debug: \n" << roomString << "\n";
		}
		else
		{
			std::cout << "No room loaded.\n";
		}
	}
	
}