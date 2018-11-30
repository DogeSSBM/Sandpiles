#include<stdbool.h>
#include<SDL2/SDL.h>
#include<stdint.h>
#include<stdio.h>
#include"Doge_SDL.h"
#include"grid.h"

int main()
{
	init();
	grid[GRIDXMAX/2][GRIDYMAX/2]=0xffffu;
	while(1){
		toppleGrid();
		//delay(10);
	}
	return 0;
}
