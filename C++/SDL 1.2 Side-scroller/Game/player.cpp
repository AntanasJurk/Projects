#include "player.h"

player::player(SDL_Surface* img)
{
	image=img;
	box.x=200;		//Pradines koordinates;
	box.y=300;
	box.w=50;
	box.h=100;
	xvel=0;
	yvel=0;
	for(int i=0;i<2;i++)
	{
		clips[i].x=i*50;			//Animacijos kadru remeliu dydziai
		clips[i].y=0;
		clips[i].w=clips[i].h=50;
	}
	ground=0;
	jump=0;

	kadras=0.0;
	moving=0;					//Judejimo busena
	health=1;					//Pradines veikejo gyvybes
}

player::~player()
{
	SDL_FreeSurface(image);
}

SDL_Rect* player::getRect()
{
	return &box;			
}

int player::getXvel()
{
	return xvel;
}
void player::setXvel(int vel)
{
	xvel=vel;
}

void player::rodyti(SDL_Surface* screen)
{
	//Uint32 color=SDL_MapRGB(screen->format,0x00,0x80,0x00);								//Spalvos sukurimas
	SDL_SetColorKey(image,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0x00,0xff,0xff));	//Veikejo fono spalvos panaikinimas
	SDL_BlitSurface (image, &clips[(int)(kadras+0.5)],screen,&box);						//Veikejo animacijos  isvedimas
}

void player::setMoving (bool b)
{
	moving=b;						//Judejimo busena
}

void player::setDirection(char c)
{
	if (c=='r'  && direction!=c)
	{
		direction=c;
		if (direction='r')
		{
			kadras=0.0;
		}
		else
		{
			kadras=0.0;
		}
	}
}

void player::judejimas(const std::vector<std::vector<int> >& map)
{
	
	int start=(baseclass::coord.x-(baseclass::coord.x%baseclass::TILE_SIZE))/baseclass::TILE_SIZE;
	int end=(baseclass::coord.x+baseclass::coord.w+(baseclass::TILE_SIZE-(baseclass::coord.x+baseclass::coord.w)%baseclass::TILE_SIZE))/baseclass::TILE_SIZE;

	if (start<0)
		start=0;

	if(end>map[0].size())
		end=map[0].size();

	bool nc=0;								//Lietimosi kintamasis, jei jis 0 lietimosi nera
	for (int i=0;i<map.size();i++)
		for (int j=start;j<end;j++)
		{
			if (map[i][j]==0)					
				continue;
			SDL_Rect destrect={j*50-baseclass::coord.x,i*50,50,50};			//Guname absoliuciaja koordinate
			if (collision(&box, &destrect))
			{
				nc=1;
				if(destrect.y >= box.y+box.h-11)						//Lietimasis su zeme
				{
					ground=1;
					yvel=0;												//Esant ant zemes, gravitacija issijungia
				}
				else if (destrect.y+destrect.h <=box.y+11)				//Lietimasis su lubomis
				{
					box.x++;
					yvel=5;										//Gravitacija
				}
				if (box.x+box.w>=destrect.x-5 && box.y+box.h>=destrect.y+6 && box.x+box.w<=destrect.x+20)		//Colision su kairiu sonu
				{
					xvel=0;
					box.x--;
				}
				else if (box.x<=destrect.x+destrect.w && box.y+box.h>=destrect.y+6)		//Colision su desiniu
				{
					xvel=0;
					box.x++;
				}
			}
		}

		if(!nc && !jump)			//Kuomet ore, gravitacija isijungia	
		{
			yvel=5;					//Kritimo greitis
		}
		if (jump && yvel<5)
		{
			yvel++;
		}
		else 
		{
			jump=0;
		}

	box.x+=xvel;
	box.y+=yvel;

	if (moving)			//Jei vyktas judejimas
	{
		kadras+=0.2;
		if(direction=='r' && kadras>=1.4)
		{
			kadras=0.0;
		}
		else if (direction=='l' && kadras>=3.4)
		{
			kadras=1.5;
		}
	}
}

void player::suolis()
{
	if (ground && !jump)		//Tikrinam ar ant zemes ir ar ne ore
	{
		jump=1;					//Suolis
		ground=0;
		yvel=-15;				//Suolio aukstis
		box.y-=5;
	}
}

int player::gyvybes()
{
	return health;	
}

void player::NustatytiGyvybes (int h)
{
	health=h;
}

char player::getDirection()
{
	return direction;
}