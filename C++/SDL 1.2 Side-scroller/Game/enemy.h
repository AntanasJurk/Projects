#include <SDL.h>
#include <vector>
#include <iostream>
#include "base.h"
#ifndef ENEMY_H
#define ENEMY_H

//Prieso klase
class enemy:baseclass			//Si klase naudos base klaseje esancia colision fja
{
	SDL_Rect box;
	SDL_Surface *image;			//Prieso paveikslelis
	bool ground;				//Prieso su zeme busena
	SDL_Rect clips;				//Kadrai
	double kadras;				//Dabartinis kadras
public:
	enemy (SDL_Surface*, int x, int y);
	void judejimas(std::vector<std::vector<int> >&);
	void rodyti (SDL_Surface*);
	SDL_Rect *getRect();
};
#endif