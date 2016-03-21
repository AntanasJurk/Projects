#include <SDL.h>
#ifndef BASE_H
#define BASE_H
//Susidurimo klase
class baseclass
{
	public:
	static SDL_Rect coord;					
	static const int TILE_SIZE=50;						//Langelio plotas

protected:
	bool collision(SDL_Rect *rec1, SDL_Rect *rect2);	//Lietimosi fja, kuri grazins T arba N, priklausomai ar iviko susidurimas tarp diveju keturkampiu
};
#endif