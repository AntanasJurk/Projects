#include "enemy.h"

enemy::enemy(SDL_Surface *img,int x, int y)
{
	//Prieso remelio sukurimas, 
	image=img;	
	box.x=x;
	box.y=y;
	box.w=image->w/2;
	box.h=image->h;
	ground=0;
	clips.x=0;
	clips.y=0;
	clips.w=clips.h=50;
	
	kadras=0.0;
}

void enemy::rodyti(SDL_Surface *screen)
{
	//Prieso paveikslelio isvedimas i ekrana
	//Uint32 color=SDL_MapRGB(screen->format,0x00,0x80,0x00);
	SDL_SetColorKey(image,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0x00,0xff,0xff));
	SDL_Rect tmp={box.x-coord.x,box.y,40,40};
	SDL_BlitSurface (image,&clips,screen,&tmp);
}

SDL_Rect* enemy ::getRect()
{
	//Grazinamos veikejo remelio dydis
	return &box;
}
