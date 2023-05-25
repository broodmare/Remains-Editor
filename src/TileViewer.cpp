#include "TileViewer.h"

extern SDL_Surface* screen;
extern SDL_Window* window;
extern SDL_Renderer* renderer;






//Tile Variables
int TileWidth = 40;
int TileHeight = 40;

//Grid Variables
int GridWidth = 3;
int GridHeight = 3;

int x = 0, x2 = 0, x3 = 0, x4 = 0;
int y = 0, y2 = 0, y3 = 0, y4 = 0;

//Panning Variables.
int EndPanX = 0;
int EndPanY = 0;
int StartPanX = 0;
int StartPanY = 0;
static bool panning = false;









//Moving the camera around.
void GridPan(const SDL_Event& event)
{
	//Mouse location.
	int mouseX,mouseY;
	//Grab the mouse location (not sure why here).
	SDL_GetMouseState(&mouseX, &mouseY);


    //MOUSE DOWN EVENTS
    if (event.type == SDL_MOUSEBUTTONDOWN) 
	{

		// Left mouse click.
		if (event.button.button == SDL_BUTTON_LEFT) 
		{
			std::cout << "#################\n";
			std::cout << "LMB Pressed at screen-space ("<< mouseX <<", "<< mouseY <<").\n";
			std::cout << "LMB Pressed at world-space ("<<  -EndPanX + mouseX <<", "<< EndPanY - mouseY <<").\n";
		}

        // Right mouse click.
    	if (event.button.button == SDL_BUTTON_RIGHT) 
		{
			//Enable panning on right mouse down. Set panning start location to mouse location.
			SDL_GetMouseState(&mouseX, &mouseY);
			StartPanX = mouseX;
            StartPanY = mouseY;
            panning = true;

			
            std::cout << "Panning: True.\n";
			std::cout << "#################\n";
			std::cout << "RMB Pressed at screen-space ("<< mouseX <<", "<< mouseY <<").\n";
			std::cout << "RMB Pressed at world-space ("<<  -EndPanX + mouseX <<", "<< EndPanY - mouseY <<").\n";
		}
    }


	//MOUSE UP EVENTS
	if (event.type == SDL_MOUSEBUTTONUP) 
	{
        // Right mouse button event. 
        if (event.button.button == SDL_BUTTON_RIGHT) 
		{
			//Disable panning on right mouse up.
            panning = false;
            std::cout << "Panning: False.\n";
        }
    }

	//MOUSE MOVEMENT EVENTS
	if (event.type == SDL_MOUSEMOTION)
	{
		if (panning == true)
		{
			//Move the grid relative to the mouse.
			EndPanX += (mouseX - StartPanX);
	        EndPanY += (mouseY - StartPanY);

			//Reset the panning start location to the current mouse location.
			SDL_GetMouseState(&mouseX, &mouseY);
	        StartPanX = mouseX;
	        StartPanY = mouseY;
		}
	}
}




//Zooming the camera.
void GridZoom(const SDL_Event& event)
{
	//Checking for mousewheel events.
	if(event.type == SDL_MOUSEWHEEL)
	{

		//Scrolling up events.
        if(event.wheel.y > 0) 
        {
			TileWidth++;
			TileHeight++;
        }

		//Scrolling down events.
		if(event.wheel.y < 0 && TileHeight > 3 && TileWidth > 3) 
        {
			TileWidth--;
			TileHeight--;
        }
	}
}



void RenderGrid(const SDL_Event& event)
{
	//Set the background color, Literally colors the entire screen
	SDL_SetRenderDrawColor(renderer, 69, 77, 84, 255);
	SDL_RenderClear(renderer);

	//Set the drawing color to white.
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);


	//Draw a box. Move right 40 pixels. Repeat i times (Number of columns). Reset x. Move down 40 pixels. Repeat j times (Number of rows).
	//Vertical Rows
	for (int j = 0; j < GridHeight; j++)
	{
		//Horizontal Rows
		for (int i = 0; i < GridWidth; i++)
		{






			//Green lines | mirrored. 1
			SDL_SetRenderDrawColor(renderer, 50, 255, 50, 255);
			SDL_RenderDrawLine(renderer,x2 + EndPanX, y2 + EndPanY, x2 + TileWidth + EndPanX,y2 + EndPanY);
			SDL_RenderDrawLine(renderer,x2 + EndPanX, y2 + TileHeight + EndPanY,x2 + TileWidth + EndPanX,y2 + TileHeight + EndPanY);

			SDL_RenderDrawLine(renderer,x2 + EndPanX,y2 + EndPanY,x2 + EndPanX,y2 + TileHeight + EndPanY);
			SDL_RenderDrawLine(renderer,x2 + TileWidth + EndPanX,y2 + EndPanY,x2 + TileWidth + EndPanX,y2 + TileHeight + EndPanY);


			//Yellow lines | mirror-flipped. 2
			SDL_SetRenderDrawColor(renderer, 255, 255, 128,255);
			SDL_RenderDrawLine(renderer,x4 + EndPanX,y4 + EndPanY,x4 + TileWidth + EndPanX,y4 + EndPanY);
			SDL_RenderDrawLine(renderer,x4 + EndPanX, y4 + TileHeight + EndPanY,x4 + TileWidth + EndPanX,y4 + TileHeight + EndPanY);

			SDL_RenderDrawLine(renderer,x4 + EndPanX,y4 + EndPanY,x4 + EndPanX,y4 + TileHeight + EndPanY);
			SDL_RenderDrawLine(renderer,x4 + TileWidth + EndPanX,y4 + EndPanY,x4 + TileWidth + EndPanX,y4 + TileHeight + EndPanY);


			//Red lines | flipped. 3
			SDL_SetRenderDrawColor(renderer, 255, 50,50, 255);
			SDL_RenderDrawLine(renderer,x3 + EndPanX,y3 + EndPanY,x3 + TileWidth + EndPanX,y3 + EndPanY);
			SDL_RenderDrawLine(renderer,x3 + EndPanX, y3 + TileHeight + EndPanY,x3 + TileWidth + EndPanX,y3 + TileHeight + EndPanY);

			SDL_RenderDrawLine(renderer,x3 + EndPanX,y3 + EndPanY,x3 + EndPanX,y3 + TileHeight + EndPanY);
			SDL_RenderDrawLine(renderer,x3 + TileWidth + EndPanX,y3 + EndPanY,x3 + TileWidth + EndPanX,y3 + TileHeight + EndPanY);


			//Blue lines | Normal 4
			SDL_SetRenderDrawColor(renderer, 128, 128, 255, 255);
			SDL_RenderDrawLine(renderer,x + EndPanX,y + EndPanY,x + TileWidth + EndPanX,y + EndPanY);
			SDL_RenderDrawLine(renderer,x + EndPanX, y + TileHeight + EndPanY,x + TileWidth + EndPanX,y + TileHeight + EndPanY);

			SDL_RenderDrawLine(renderer,x + EndPanX,y + EndPanY,x + EndPanX,y + TileHeight + EndPanY);
			SDL_RenderDrawLine(renderer,x + TileWidth + EndPanX,y + EndPanY,x + TileWidth + EndPanX,y + TileHeight + EndPanY);


			//move to the right to prepare to make the next square.
			x = x + TileWidth;
			x2 = x2 - TileWidth;
			x3 = x3 - TileWidth;
			x4 = x4 + TileWidth;
		}
		//Reset the position like a typewriter and move down a row.
		//Initial horizontal offset
		x = 0;
		x2 = -TileWidth;
		x3 = -TileWidth;
		x4 = 0;

		//Move the current Y down.
		y = y + TileHeight;
		y2 = y2 - TileHeight;
		y3 = y3 + TileHeight;
		y4 = y4 - TileHeight;
	}

	y = 0;
	y2 = -TileHeight;
	y3 = 0;
	y4 = -TileHeight;

	//Check world space for starting grids

	if (event.key.keysym.sym == SDLK_g)
	{
	std::cout << "#################\n";
	std::cout << "Normal grid start point ("<< x <<", "<< y <<").\n";
	std::cout << "Flipped grid start point ("<< x4 <<", "<< y4 <<").\n";
	std::cout << "Mirrored grid start point ("<< x3 <<", "<< y3 <<").\n";
	std::cout << "Mirror-Flipped grid start point ("<< x2 <<", "<< y2 <<").\n";
	}


	//update the window at the end of the loop by swapping the buffer I think?
	SDL_RenderPresent(renderer);
}