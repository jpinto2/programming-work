#include "SDL.h"
#include <stdio.h>

bool quit = false;
void Destroy();
SDL_Event event;
SDL_Window *window;
SDL_Renderer *renderer;

SDL_Surface *brick;
SDL_Surface *ball;
SDL_Surface *bk;
SDL_Surface *bat;

SDL_Texture *bricktexture;
SDL_Texture *balltexture;
SDL_Texture *bktexture;
SDL_Texture *battexture;

int ballx = 200;
int bally = 200;
int bvx = 1;
int bvy = 1;

int bkh = 600;
int bkw = 800;
int brickw = 80;
int brickh = 35;
int bkmin = 0;
int batx = bkw / 2;
int baty = bkh - 30;
//3 rows, 5 columns
SDL_Rect brickrect[3][7];
SDL_Rect ballrect;
int delete_brick_count = 0;
int no_of_bricks = 21;

void initializebrick() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 7; j++)
			brickrect[i][j] = { 100 * j + 50, i*50 + 50, brickw, brickh };
}

void eventhandler() {
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT) quit = true;
	// keydown is any key has been pressed
	else if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_LEFT && batx > 0) batx = batx - 2;
		else if (event.key.keysym.sym == SDLK_RIGHT && batx < bkw-60) batx = batx + 2;
	}
}

void gameOver() {
	SDL_Surface *go = SDL_LoadBMP("gover.bmp");
	SDL_Texture *gotexture = SDL_CreateTextureFromSurface(renderer, go);
	SDL_Rect gorect = { 0,0,bkw,bkh };
	SDL_RenderCopy(renderer, gotexture, NULL, &gorect);
	SDL_RenderPresent(renderer);
	SDL_Delay(20000);
	Destroy();
	SDL_Quit();
	quit = true;



}
void moveball() {
	ballx = ballx + bvx;
	bally = bally + bvy;
}
void ballcollision() {
	// 20 is the width of the ball itself
	if (ballx < bkmin || ballx > bkw - 20) bvx = -bvx;
	// 30 is it's height
	if (bally < bkmin) bvy = -bvy;
	if (bally > bkh + 60) {
		gameOver();
	}
	int scale = 20;
	if (bally + scale >= baty && bally + scale <= baty + 30 && ballx + scale >= batx && ballx + scale <= batx + 60) bvy = -bvy;
}

bool collisiondetect(SDL_Rect rect1, SDL_Rect rect2) {
	if (rect1.x > rect2.x + rect2.w) return false;
	if (rect1.x + rect1.w < rect2.x) return false;
	if (rect1.y > rect2.y + rect2.h) return false;
	if (rect1.y + rect1.h < rect2.y) return false;
	return true; // there is collision

}

void brickcollision() {
	bool a;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 7; j++) {
			a = collisiondetect(brickrect[i][j], ballrect);
			if (a == true) {
				brickrect[i][j].x = 3000;
				bvy = -bvy;
				delete_brick_count++;
			}
		}
	}
}

void Destroy() {
	SDL_DestroyTexture(battexture);
	SDL_DestroyTexture(bricktexture);
	SDL_DestroyTexture(bktexture);
	SDL_DestroyTexture(balltexture);

	SDL_FreeSurface(bat);
	SDL_FreeSurface(brick);
	SDL_FreeSurface(bk);
	SDL_FreeSurface(ball);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
void winning() {
	SDL_Surface *win = SDL_LoadBMP("win.bmp");
	SDL_Texture *wintexture = SDL_CreateTextureFromSurface(renderer, win);
	SDL_Rect winrect = { 250,200,350,350 };
	SDL_RenderCopy(renderer, wintexture, NULL, &winrect);
	SDL_RenderPresent(renderer);
	SDL_Delay(10000);
	Destroy();
	SDL_Quit();
	quit = true;

}

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	// first 2 parameters are the position of the window, third is width of window, fourth is height
	window = SDL_CreateWindow("The Ball", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0); 
	renderer = SDL_CreateRenderer(window, -1, 0);

	
	SDL_Rect bkrect = { 0, 0, 800, 600 };
	initializebrick();
	ball = SDL_LoadBMP("ball.bmp");
	bk = SDL_LoadBMP("bk.bmp");
	bat = SDL_LoadBMP("bat.bmp");
	brick = SDL_LoadBMP("brick.bmp");
	balltexture = SDL_CreateTextureFromSurface(renderer, ball);
	bktexture = SDL_CreateTextureFromSurface(renderer, bk);
	battexture = SDL_CreateTextureFromSurface(renderer, bat);
	bricktexture = SDL_CreateTextureFromSurface(renderer, brick);
	SDL_RenderCopy(renderer, bktexture, NULL, &bkrect);
	
	while (!quit) {
		eventhandler();
		ballrect = { ballx, bally, 20, 30 };
		SDL_Rect batrect = { batx, baty, 60, 30 };
		moveball();
		ballcollision();
		brickcollision();
		if (delete_brick_count == no_of_bricks) {
			winning();
		}

		SDL_RenderCopy(renderer, bktexture, NULL, &bkrect);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 7; j++)
				SDL_RenderCopy(renderer, bricktexture, NULL, &brickrect[i][j]);
		SDL_RenderCopy(renderer, balltexture, NULL, &ballrect);
		SDL_RenderCopy(renderer, battexture, NULL, &batrect);
		SDL_RenderPresent(renderer);
		SDL_Delay(2);
		SDL_RenderClear(renderer);
	}

	// SDL_Delay(9000); // window lasts 6 seconds
	// SDL_DestroyWindow(window);
	Destroy();
	SDL_Quit();
	return 0;
}
