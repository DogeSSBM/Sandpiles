#pragma once
#include<stdbool.h>
#include<SDL2/SDL.h>
#include<stdint.h>
#include<stdio.h>

#define XMAX 640
#define YMAX 640
#define XMID (XMAX / 2)
#define YMID (YMAX / 2)

typedef uint8_t u8;

SDL_Window* window;
SDL_Renderer* renderer;

typedef struct{
	u8 r, g, b;
}Color;

typedef struct{
	int x, y;
}iCoord;

typedef struct{
	uint x, y;
}uCoord;

void delay(uint ms)
{
	SDL_Delay(ms);
}

void setRGB(u8 r, u8 g, u8 b)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
}

void setColor(Color c)
{
	setRGB(c.r, c.g, c.b);
}

void drawPixel(uint x, uint y)
{
	SDL_RenderDrawPoint(renderer, x, y);
}

void drawLine(uint x1, uint y1, uint x2, uint y2)
{
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void drawRect(uint x, uint y, uint xlen, uint ylen)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = xlen;
	rect.h = ylen;
	SDL_RenderDrawRect(renderer, &rect);
}

void fillRect(uint x, uint y, uint xlen, uint ylen)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = xlen;
	rect.h = ylen;
	SDL_RenderFillRect(renderer, &rect);
}

void drawFrame()
{
	SDL_RenderPresent(renderer);
}

void init()
{
	if(SDL_Init(SDL_INIT_VIDEO)<0){
		printf("SDL borked! Error: %s\n", SDL_GetError());
		// Destroy renderer
		SDL_DestroyRenderer(renderer);
		// Destroy window
		SDL_DestroyWindow( window );
		// Quit SDL subsystems
		SDL_Quit();
	}
	else{
		//Create window
		SDL_CreateWindowAndRenderer(XMAX, YMAX, 0,
			&window, &renderer);
		setRGB(0, 0, 0);
		fillRect(0, 0, XMAX, YMAX);
		drawFrame();
	}
}
