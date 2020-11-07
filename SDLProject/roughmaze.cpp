#include "SDL.h"
#include "SDL_mixer.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>  
#include <vector>
#include <list>
using namespace std;

//declare 2d bool vector for maze
vector < vector < int > > maze;
int px; // player x position: lower goes left, higher goes right
int py; // player y position: lower goes up, higher goes down
int ax; // ai's x position
int ay; // ai's y position
int previous = 1; // previous direction moved by AI, 1 up, ,2 down, 3 left, 4 right
int wx; // x endpoint
int wy; // y endpoint
int n = 40;
int xn = 70;
bool win = false;
bool awin = false;
bool quit = false;
SDL_Event event;
SDL_Rect gridrect[40][70];
SDL_Rect hgridrect[3][3];

void up();
void down();
void left();
void right();
void aimove();
void aleft();
void aup();
void aright();
void adown();
void generatemaze(const int size, const int xsize); // spent a lot of time on this before deciding to just use an open source one
void eventhandler();
int intro();

void eventhandler() {
	SDL_PollEvent(&event);
	bool move = false;
	if (event.type == SDL_QUIT) quit = true;
	// keydown is any key has been pressed
	else if (event.type == SDL_KEYDOWN) {
		//SDL_Delay(130);
		if (event.key.keysym.sym == SDLK_UP) {
			up();
			move = true;
		}
		else if (event.key.keysym.sym == SDLK_RIGHT) {
			right();
			move = true;
		}
		else if (event.key.keysym.sym == SDLK_LEFT) {
			left();
			move = true;
		}
		else if (event.key.keysym.sym == SDLK_DOWN) {
			down();
			move = true;
		}
		if (move == true) {
			if (px == wx and py == wy) win = true;
			else aimove();
			if (ax == wx && ay == wy) awin = true;
		}
	}
}

int intro() {
	SDL_PollEvent(&event);
	// keydown is any key has been pressed
	if (event.type == SDL_KEYDOWN) {
		SDL_Delay(300);
		if (event.key.keysym.sym == SDLK_1) return 1;
		else if (event.key.keysym.sym == SDLK_2) return 2;

	}
	return 0;
}


int main(int argc, char* argv[])
{

	generatemaze(n, xn);
	int i;
	int j;

	// find random start point
	for (i = n - 1; i >= 0; i--) {
		for (j = 0; j < xn; j++) {
			if (maze[i][j] == 1) {
				px = j;
				ax = j;
				py = i;
				ay = i;
				break;
			}
		}
		if (maze[i][j] == 1) break;
	}

	// random win point. 
	for (i = 0; i < n; i++) {
		for (j = xn-1; j >= 0; j--) {
			if (maze[i][j] == 1) {
				wx = j;
				wy = i;
				if (maze[i][j] == 1) break;
			}
		}
		if (maze[i][j] == 1) break;
	}
	
	//start here for sdlinit
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Mix_Music *bgsound = Mix_LoadMUS("ham.mp3");
	SDL_Window *window = SDL_CreateWindow("Maze Runner", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1400, 800, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Rect instructrect = { 0,0,500,500};
	SDL_Surface *instruct = SDL_LoadBMP("intro.bmp");
	SDL_Texture *instructtexture = SDL_CreateTextureFromSurface(renderer, instruct);

	int mode = 0;
	while (mode == 0) {
		SDL_RenderCopy(renderer, instructtexture, NULL, &instructrect);
		SDL_RenderPresent(renderer);
		mode = intro();
	}

	if (mode == 1) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < xn; j++) {
				gridrect[i][j] = { 20 * j, i * 20, 20, 20 };
			}
		}
	}
	else {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				hgridrect[i][j] = { 0 + 200 * j, 0 + 200 * i, 200, 200 };
			}
		}
	}

	SDL_Surface *wall = SDL_LoadBMP("brickwall.bmp");
	SDL_Surface *path = SDL_LoadBMP("grass.bmp");
	SDL_Surface *player = SDL_LoadBMP("player.bmp");
	SDL_Surface *ai = SDL_LoadBMP("ai.bmp");
	SDL_Surface *goal = SDL_LoadBMP("goal.bmp");
	SDL_Surface *pwin = SDL_LoadBMP("win.bmp");
	SDL_Surface *cpuwin = SDL_LoadBMP("lose.bmp");

	SDL_Texture *walltexture = SDL_CreateTextureFromSurface(renderer, wall);
	SDL_Texture *pathtexture = SDL_CreateTextureFromSurface(renderer, path);
	SDL_Texture *playertexture = SDL_CreateTextureFromSurface(renderer, player);
	SDL_Texture *aitexture = SDL_CreateTextureFromSurface(renderer, ai);
	SDL_Texture *goaltexture = SDL_CreateTextureFromSurface(renderer, goal);
	SDL_Texture *pwintexture = SDL_CreateTextureFromSurface(renderer, pwin);
	SDL_Texture *cpuwintexture = SDL_CreateTextureFromSurface(renderer, cpuwin);
	Mix_PlayMusic(bgsound, -1);


	if (mode == 1) {
		do {
			// inside the loop clear the screen and display the map again to start
			for (i = 0; i < n; i++) {
				for (j = 0; j < xn; j++) {
					if (maze[i][j] == 1) SDL_RenderCopy(renderer, pathtexture, NULL, &gridrect[i][j]);
					else SDL_RenderCopy(renderer, walltexture, NULL, &gridrect[i][j]);
				}
			}

			if (px == ax && py == ay) SDL_RenderCopy(renderer, playertexture, NULL, &gridrect[py][px]);
			else {
				SDL_RenderCopy(renderer, playertexture, NULL, &gridrect[py][px]);
				SDL_RenderCopy(renderer, aitexture, NULL, &gridrect[ay][ax]);
			}

			SDL_RenderCopy(renderer, goaltexture, NULL, &gridrect[wy][wx]);
			SDL_RenderPresent(renderer);
			eventhandler();
			SDL_RenderClear(renderer);

		} // end do while loop
		while (win == false && awin == false && quit == false);
	}
	else if (mode == 2) {
		do {
			// inside the loop clear the screen and display the map again to start
			for (i = py-1; i <= py+1; i++) {
				for (j = px-1; j <= px+1; j++) {
					if (i >= 0 && i < n && maze[i][j] == 1) SDL_RenderCopy(renderer, pathtexture, NULL, &hgridrect[i - (py - 1)][j - (px - 1)]);
					else if (i >= 0 && i < n && maze[i][j] == 0) SDL_RenderCopy(renderer, walltexture, NULL, &hgridrect[i - (py - 1)][j - (px - 1)]);
					if (ay == i && ax == j && (ay != py || ax != px)) SDL_RenderCopy(renderer, aitexture, NULL, &hgridrect[i - (py - 1)][j - (px - 1)]);
					if (wy == i && wx == j) SDL_RenderCopy(renderer, goaltexture, NULL, &hgridrect[i - (py - 1)][j - (px - 1)]);
				}
			}

			SDL_RenderCopy(renderer, playertexture, NULL, &hgridrect[1][1]);
			cout << endl;

			SDL_RenderPresent(renderer);
			eventhandler();
			SDL_RenderClear(renderer);

		} while (win == false && awin == false && quit == false);
	}
	// outside the loop make sure to tell the player they won
	if (win) SDL_RenderCopy(renderer, pwintexture, NULL, &instructrect);
	else if (awin) SDL_RenderCopy(renderer, cpuwintexture, NULL, &instructrect);
	SDL_RenderPresent(renderer);
	SDL_Delay(5000);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_FreeMusic(bgsound);
	SDL_Quit();
	return 0;
} // end main


void up() // function that moves the player in the up direction
{
	if (py - 1 >= 0 && maze[py - 1][px] == 1) {
		//	if (y == ay && x == ax) maze[y][x] = 'A';
		//	else maze[y][x] = '#';
		//	maze[y-1][x] = 'X';
		py = py - 1;
	}

}

void down() // function that moves the player in the down direction
{
	if (py + 1 < n && maze[py + 1][px] == 1) {
		//	if (y == ay && x == ax) maze[y][x] = 'A';
		//	else maze[y][x] = '#';
		//	maze[y+1][x] = 'X';
		py = py + 1;
	}

}

void left() // function that moves the player in the left direction
{
	if (px - 1 >= 0 && maze[py][px - 1] == 1) {
		//	if (y == ay && x == ax) maze[y][x] = 'A';
		//	else maze[y][x] = '#';
		//	maze[y][x-1] = 'X';
		px = px - 1;
	}

}

void right() // function that moves the player in the right direction
{
	if (px + 1 < xn && maze[py][px + 1] == 1) {
		//	if (y == ay && x == ax) maze[y][x] = 'A';
		//	else maze[y][x] = '#';
		//	maze[y][x+1] = 'X';
		px = px + 1;
	}
}

// moves opponent using hug left wall strategy
void aimove() {
	// hug left wall is dependent on the previous direction moved by the opponent	
	if (previous == 1) { // up
		if (ax - 1 >= 0 && maze[ay][ax - 1] == 1) aleft();
		else if (ay - 1 >= 0 && maze[ay - 1][ax] == 1) aup();
		else if (ax + 1 < xn && maze[ay][ax + 1] == 1) aright();
		else adown();
	}
	else if (previous == 2) { // down
		if (ax + 1 < xn && maze[ay][ax + 1] == 1) aright();
		else if (ay + 1 < n && maze[ay + 1][ax] == 1) adown();
		else if (ax - 1 >= 0 && maze[ay][ax - 1] == 1) aleft();
		else aup();
		;
	}
	else if (previous == 3) { // left
		if (ay + 1 < n && maze[ay + 1][ax] == 1) adown();
		else if (ax - 1 >= 0 && maze[ay][ax - 1] == 1) aleft();
		else if (ay - 1 >= 0 && maze[ay - 1][ax] == 1) aup();
		else aright();

	}
	else { // right
		if (ay - 1 >= 0 && maze[ay - 1][ax] == 1) aup();
		else if (ax + 1 < xn && maze[ay][ax + 1] == 1) aright();
		else if (ay + 1 < n && maze[ay + 1][ax] == 1) adown();
		else aleft();
	}
	/*
		if (maze[ay][ax-1] != '-' && maze[ay][ax-1] != '|')
		else if (maze[ay-1][ax] != '-' && maze[ay-1][ax] != '|')
		else if (maze[ay][ax+1] != '-' && maze[ay][ax+1] != '|')
		else (maze[ay+1][ax] != '-' && maze[ay+1][ax] != '|')
	*/
}

void aleft() {
	//	if(maze[ay][ax] == 'A')maze[ay][ax] = '#';
	//	if (maze[ay][ax-1] == '#') maze[ay][ax-1] = 'A';
	ax = ax - 1;
	previous = 3;
}
void aup() {
	//	if(maze[ay][ax] == 'A')maze[ay][ax] = '#';
	//	if (maze[ay-1][ax] == '#') maze[ay-1][ax] = 'A';
	ay = ay - 1;
	previous = 1;
}
void aright() {
	//	if(maze[ay][ax] == 'A')maze[ay][ax] = '#';
	//	if (maze[ay][ax+1] == '#') maze[ay][ax+1] = 'A';
	ax = ax + 1;
	previous = 4;
}
void adown() {
	//	if(maze[ay][ax] == 'A')maze[ay][ax] = '#';
	//	if (maze[ay+1][ax] == '#') maze[ay+1][ax] = 'A';
	ay = ay + 1;
	previous = 2;
}

void generatemaze(const int size, const int xsize) {

	srand(time(0));

	const int maze_size_x = xsize;
	const int maze_size_y = size;

	list < pair < int, int> > drillers;

	maze.resize(maze_size_y+1);
	for (size_t y = 0; y < maze_size_y; y++)
		maze[y].resize(maze_size_x+1);

	for (size_t x = 0; x < maze_size_x; x++)
		for (size_t y = 0; y < maze_size_y; y++)
			maze[y][x] = 0;

	drillers.push_back(make_pair(maze_size_x / 2, maze_size_y / 2));
	while (drillers.size() > 0)
	{
		list < pair < int, int> >::iterator m, _m, temp;
		m = drillers.begin();
		_m = drillers.end();
		while (m != _m)
		{
			bool remove_driller = false;
			switch (rand() % 4)
			{
			case 0:
				(*m).second -= 2;
				if ((*m).second < 0 || maze[(*m).second][(*m).first])
				{
					remove_driller = true;
					break;
				}
				maze[(*m).second + 1][(*m).first] = 1;
				break;
			case 1:
				(*m).second += 2;
				if ((*m).second >= maze_size_y || maze[(*m).second][(*m).first])
				{
					remove_driller = true;
					break;
				}
				maze[(*m).second - 1][(*m).first] = 1;
				break;
			case 2:
				(*m).first -= 2;
				if ((*m).first < 0 || maze[(*m).second][(*m).first])
				{
					remove_driller = true;
					break;
				}
				maze[(*m).second][(*m).first + 1] = 1;
				break;
			case 3:
				(*m).first += 2;
				if ((*m).first >= maze_size_x || maze[(*m).second][(*m).first])
				{
					remove_driller = true;
					break;
				}
				maze[(*m).second][(*m).first - 1] = 1;
				break;
			}
			if (remove_driller)
				m = drillers.erase(m);
			else
			{
				drillers.push_back(make_pair((*m).first, (*m).second));
				drillers.push_back(make_pair((*m).first, (*m).second));

				maze[(*m).second][(*m).first] = 1;
				++m;
			}
		}
	}

}
