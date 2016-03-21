#include "game.h"
SDL_Rect baseclass::coord;

game::game()														
{

	SDL_Init(SDL_INIT_EVERYTHING);											//Inicijuojam visas SDL bibliotekos komandas
	screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32,SDL_SWSURFACE);	//Inicijuojam ekrana
	block=load_image("blocks.bmp");												
	background=load_image("bc.bmp");
	ene=load_image ("enemy.bmp");
	player1=new player(load_image("player.bmp"));

	baseclass::coord.x=baseclass::coord.y=camera.x=camera.y=0;			
	baseclass::coord.w=camera.w=SCREEN_WIDTH;
	baseclass::coord.h=camera.h=SCREEN_HEIGHT;
	direction[0]=direction[1]=0;
	running=true;				//Judejimo busena
	pabaiga.x=0;				//Pabaigos langelio dydis
	pabaiga.y=0;
	pabaiga.w=50;
	pabaiga.h=50;
}

game::~game()								//Destruktorius
{
	SDL_FreeSurface (block);				//Atlaisviname atminti
	SDL_FreeSurface(background);
	delete player1;							//Sunaikiname veikeja

	for(int i=0;i<enemies.size();i++)		//Sunaikinam priesus
		delete enemies[i];	

	SDL_Quit();								//Baigiam zaidima
}

SDL_Surface* game::load_image(const char* filename)			//Paveikslelio uzkrovimo metodas
{
	SDL_Surface* tmp=SDL_LoadBMP(filename);					
	SDL_Surface* tmp2=SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	return tmp2;
}

void game::handleEvents()
{
	SDL_Event event;						//Mygtuku paspaudimu nuskaitymas
	while (SDL_PollEvent(&event))
	{
		switch	(event.type)
		{
		case SDL_QUIT:
			running=false;
			return;
		case SDL_KEYDOWN:					//Nuskaitome zemyn rodykles paspaudima
			switch(event.key.keysym.sym)
			{
			
			case SDLK_RIGHT:
				direction[1]=1;
				player1->setMoving(1);
				break;	
			case SDLK_SPACE:
				player1->suolis();
				break;
			}
			break;
		}
	}
}

void game::loadmap(const char *filename)
{
	std::ifstream in(filename);		//Nuskaitome mapp faila
	if (!in.is_open())		//Tikrinama, ar pavyko atidaryti map faila
	{
		std::cout<<"Problema"<<std::endl;
		return;
	}
	int width,height;
	in >> width;				//Nuskaitome zemelapio ploti ir ilgi
	in >> height;
	int current;
	for (int i=0;i<height;i++)		//Einame per visa faila ir tikriname, kokie lageliai turi buti dedami
	{
		std::vector<int>vec;
		for (int j=0;j<width;j++)
		{
			if (in.eof())
			{
				std::cout<<"End"<<std::endl;
				return;
			}
			in >> current;
			if(current==-1)			//Tikriname ar pozicija zemelapyje yra prieso pozicija
			{
				enemies.push_back(new enemy(ene,j*50,i*50));
				vec.push_back(0);
			}
			else 
			{
			if (current>=0 && current<=7)		//Tikriname ar kiti blokeliai
			{
				if (current==3)				//Tikriname ar pabaigos blokas
				{
					pabaiga.x=j*50;			//Nustatome pabaigos bloki koordinates
					pabaiga.y=i*50;
				}
				vec.push_back(current);	
			}
			else
			{
				vec.push_back(0);
			}
			}
		}
		map.push_back(vec);
	}
	
	in.close();
	
}

void game::rodytimap()
{
	int start=(baseclass::coord.x-(baseclass::coord.x%baseclass::TILE_SIZE))/baseclass::TILE_SIZE;
	int end=(baseclass::coord.x+baseclass::coord.w+(baseclass::TILE_SIZE-(baseclass::coord.x+baseclass::coord.w)%baseclass::TILE_SIZE))/baseclass::TILE_SIZE;
	if (start<0)
		start=0;
	if(end>map[0].size())
		end=map[0].size();
	for (int i=0;i<map.size();i++)
		for (int j=0;j<map[0].size();j++)
			if (map[i][j]!=0)
			{
				SDL_Rect blockrect={(map[i][j]-1)*baseclass::TILE_SIZE,0,baseclass::TILE_SIZE,baseclass::TILE_SIZE};	//Suskaiciuojame blokelio pozicijas
				SDL_Rect destrect={j*baseclass::TILE_SIZE-baseclass::coord.x,i*50};
				SDL_BlitSurface (block,&blockrect,screen,&destrect);									//Blokeliu isvedimas

			}
}

void game::start()
{
	Uint32 start;
	loadmap ("map.map");
	while (running)			//Kol programa veikia...
	{
		start=SDL_GetTicks();		//Pradedam skaiciuoti laika
		handleEvents();

		if (direction[1])				//Paspaudus rokyle...
		{
			player1->setDirection('r');		//Nustatoma kryptis
			if (player1->getRect()->x <200)
			{
				player1->setXvel(1);		//Judinam veikeja	
			}
			else
			{
				player1->setXvel(0);		
				camera.x++;
				baseclass::coord.x+=4;
			}
			if(camera.x>=2000-SCREEN_WIDTH)
			{
				camera.x=0;						//Pasiekus lygio gala, kamera nustoja judeti
			}
		}
		else 
		{
			player1->setXvel(0);
		}



		player1->judejimas(map);


		for (int j=0;j<enemies.size();j++)
		{
			SDL_Rect tmprect={enemies[j]->getRect()->x-baseclass::coord.x,enemies[j]->getRect()->y,40,40};
			if(collision(&tmprect,player1->getRect()))
			{
				if (player1->getRect()->y+player1->getRect()->h >= enemies[j]->getRect()->y && player1->getRect()->y+player1->getRect()->h <= enemies[j]->getRect()->y+10)
				{
					player1->NustatytiGyvybes(player1->gyvybes()-1);			//Mazinam givybes kai ivyksta colisionas
				}
			}
		}



		SDL_BlitSurface(background,&camera,screen,NULL);		//Isvedam galine uzsklanda
		rodytimap();										
		player1->rodyti(screen);					//Isvedam veikeja
	
		for (int i=0;i<enemies.size();i++)
		{
			enemies[i]->rodyti(screen);			//Isvedam priesus
		}

		SDL_Flip(screen);
		SDL_Rect tmprect={pabaiga.x-coord.x,pabaiga.y,50,50};

		//Zaidimas baigiasi, kai veikejo remelio koordinates palieka ekrana, kai sumazeja prarandama gyvybe arba pasiekiamas pergales blokelis
		if (player1->gyvybes()<=0 || player1->getRect()->y >= screen->h || collision(player1->getRect(), &tmprect))	
		{
			running=false;
			
		}


		if (1000/30>(SDL_GetTicks()-start))						//Nustatome zaidimo kadrus per sekunde
			SDL_Delay(1000/30-(SDL_GetTicks()-start));
	}
}