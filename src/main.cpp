// CanterCore.cpp : Defines the entry point for the application.

#include "main.h"


using namespace std;

//Define the window and OpenGL
SDL_Surface* screen = nullptr;
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

int screenWidth = 1280;
int screenHeight = 720;




//Main Loop
int main()
{

	//Create the window and output logs.
	SDL_Init(SDL_INIT_VIDEO);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL window failed to initialize.\n";
		SDL_GetError();
	}
	else
	{
		std::cout << "SDL window created.\n";
	}


	//Creates the window and SDL renderer..
	 window = SDL_CreateWindow("Remains Editor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	 renderer =  SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	 //Initialize a screen that can be modified.
	 screen = SDL_GetWindowSurface(window);



	 ////////////////////////////////////////////////////////////



	 //What to do while the game is running.
	bool running = true;
	while (running)
	{
		//Event listener to grab any user input.
		SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {

			GridPan(event);
			GridZoom(event);
        	RenderGrid(event);
			GetData(event);
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}


	}

	//Destroy everything manually just in case and then quit.
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}