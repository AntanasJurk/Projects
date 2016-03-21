#include <SDL.h>
#include <iostream>
#include <vector>
#include "base.h"
#ifndef PLAYER_H
#define PLAYER_H

//Veikejo klase
class player:baseclass			//Si klase naudos base klaseje esancia colision fja
{
	SDL_Rect box;				//Zaidimo veikejo remelis
	SDL_Surface* image;			//Isskiriamas pavirsius paveiksleliui
	int xvel, yvel;				//Veikejo judejimas 
	SDL_Rect clips[2];			//Animacijos klipai
	bool ground;				//Zemes kintamasis
	bool jump;					//Suolio kintamasis
	char direction;				//Judejimo kryptis
	double kadras;				//Animacijos kadrai
	bool moving;				//Judejimo busena
	int health;					//Gyvybes
public:
	player(SDL_Surface *img);		//Konstruktorius
	~player();						//Destruktorius
	SDL_Rect *getRect();		
	void setXvel(int vel);			//Velosity
	int getXvel();
	void judejimas(const std::vector<std::vector<int> >& map);		//Judejimo metodas
	void rodyti(SDL_Surface* screen);								//Atvaizdavmo metodas
	void suolis();									//Suolio metodas
	void setMoving (bool);							
	void setDirection(char);						
	char getDirection();
	int gyvybes ();
	void NustatytiGyvybes (int);

};
#endif