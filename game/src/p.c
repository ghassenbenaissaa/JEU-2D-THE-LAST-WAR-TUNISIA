#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "headerpartage.h"


void initialiser_background1p(background *b)
{
//****************************music******************************
        Mix_Music  *music2;
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    	{
        	printf("%s", Mix_GetError());
    	}
	music2 = Mix_LoadMUS("../Background/map1.mp3");
//**************************************************************************	
	Mix_PlayMusic(music2,-1) ;
        b->calque_background=NULL;
	b->calque_background=IMG_Load("masque.png");
	b->afficher_background=NULL;
	b->afficher_background=IMG_Load("background.png");
	b->pos_background2.x=0;
	b->pos_background2.y=0;
	b->pos_background2.h=1020;
	b->pos_background2.w=960;
        b->pos_background.x=0;
        b->pos_background.y=0;
        b->pos_background.w=960;
        b->pos_background.h=1020;
 

}

void afficherBackp(background b,SDL_Surface *ecran)
{	
	SDL_BlitSurface(b.afficher_background,&b.pos_background,ecran,&b.pos_background2);    
}


//****************************background2****************************
void initialiser_background2p(background *b2)
{
 
        b2->calque_background2=NULL;
	b2->calque_background2=IMG_Load("masque2.png");
	b2->afficher_background2=NULL;
	b2->afficher_background2=IMG_Load("background2.png");
	b2->pos_background20.x=0;
	b2->pos_background20.y=0;
	b2->pos_background22.x=960;
	b2->pos_background22.y=0;
	b2->pos_background22.h=1020;
	b2->pos_background22.w=960;
        b2->pos_background20.x=0;
        b2->pos_background20.y=0;
        b2->pos_background20.w=960;
        b2->pos_background20.h=1020;

}

void afficherBack2p(background b2,SDL_Surface *ecran)
{	
        SDL_BlitSurface(b2.afficher_background2,&b2.pos_background20,ecran,&b2.pos_background22);
}
