#pragma once
#include<stdbool.h>
#include<SDL2/SDL.h>
#include<stdint.h>
#include<stdio.h>
#include"Doge_SDL.h"

#define CELLLEN 4
#define GRIDXMAX (XMAX / CELLLEN)
#define GRIDYMAX (YMAX / CELLLEN)

uint grid[GRIDXMAX][GRIDYMAX]={};

Color getColor(uint val)
{
  const static Color colorVals[10] = {
    {0,     0,    0},
    {255,   0,    0},
    {0,   255,    0},
    {0,     0,  255},
    {255, 128,    0},
    {128, 255,    0},
    {0,   255,  128},
    {0,   128,  255},
    {128,   0,  255},
    {255,   0,  128}
  };
  return colorVals[val%10];
}

void drawCell(uint x, uint y)
{
  setColor(getColor(grid[x][y]));
  fillRect(x*CELLLEN,y*CELLLEN,x*CELLLEN+CELLLEN,y*CELLLEN+CELLLEN);
}

void drawGrid()
{
  for(uint y = 0; y < GRIDYMAX; y++) {
    for(uint x = 0; x < GRIDXMAX; x++) {
      drawCell(x, y);
    }
  }
  drawFrame();
}

void topplePile(uint x, uint y)
{
    grid[x][y]-=4;
    grid[x-1][y]++;
    grid[x+1][y]++;
    grid[x][y-1]++;
    grid[x][y+1]++;
}

void toppleGrid()
{
  for(uint y = 1; y < GRIDYMAX-1; y++) {
    for(uint x = 1; x < GRIDXMAX-1; x++) {
      if(grid[x][y]>4){
        topplePile(x, y);
      }
    }
  }
  drawGrid();
}
