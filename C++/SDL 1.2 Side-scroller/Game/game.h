#include <iostream>
#include <fstream>
#include <vector>
#include <SDL.h>
#include "base.h"
#include "player.h"
#include "enemy.h"
#ifndef GAME_H
#define GAME_H

class game:public baseclass					//Paveldim is baseclass lietimosi funkcija
{
	SDL_Surface *screen,*background,*block,*ene;	//Isskiriamas pavirsius paveiksleliui
	SDL_Rect camera;
	std::vector<std::vector<int> >map;		//Dvidimensinis vektorius zemelapiui laikyti
	std::vector<enemy*> enemies;			//Vektorius priesu pozicijoms
	bool running;							//Tikrinam, ar veikia programa
	static const int SCREEN_WIDTH=640;		//Ekrano dydis
	static const int SCREEN_HEIGHT=480;
	player* player1;						
	bool direction[2];						//Judejimo kryptys
	SDL_Rect pabaiga;						//Pabaigos koordinates

	SDL_Surface *load_image(const char* filename);	//Piesineliu isvedimo funckija
	void loadmap(const char *filename);		//Zemelapio uzkrovimas
	void rodytimap();						//Zemelapio isvedimas
	void handleEvents();					//Paspaudimu nuskaitymas


public:
	game();			//Konstruktorius
	~game();		//Destruktorius
	void start();
};
#endif