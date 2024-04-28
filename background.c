#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header.h"


void initBack(background *b)
{

	Mix_Music  *music;
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    	{
        	printf("%s", Mix_GetError());
    	}
	music = Mix_LoadMUS("../Background/map1.mp3");	
	Mix_PlayMusic(music,-1) ;

    char ch[50];
    int i,j;
    char chh[50];


	    for(j=1; j<14; j++)
    {
        sprintf(ch,"../Background/porte/%d.png",j);
        b->porte[j]=IMG_Load(ch);
    }
    for(i=1; i<14; i++)
    {
        sprintf(chh,"../Background/owl/%d.png",i);
        b->owl[i]=IMG_Load(chh);
    }

	b->calque_background=NULL;
	b->calque_background=IMG_Load("masque4.png");
	b->afficher_background=NULL;
	b->afficher_background=IMG_Load("map1.png");
	b->aff=NULL;
	b->aff=IMG_Load("map.png");
	b->pos_background.x=0;
	b->pos_background.y=0;
	b->pos_background2.x=0;
	b->pos_background2.y=0;
	b->pos_background2.h=1020;
	b->pos_background2.w=1920;
	b->port.x=  0 ;
        b->port.y=  0 ;
        b->owll.x=  0 ;
        b->owll.y=  0 ;
}


void afficherBack(background b,SDL_Surface *ecran)
{	
	SDL_BlitSurface(b.afficher_background,&(b.pos_background2),ecran,&(b.pos_background));
}


void animerBackground (background *b,SDL_Surface *ecran)
{   
    int j;
    char ch[50];
    int i;
    char chh[50];
     SDL_BlitSurface(b->aff,NULL,ecran,&(b->port));
    for(j=1; j<14; j++)
    {
        SDL_BlitSurface( b->porte[j], NULL,ecran,&(b->port));
        SDL_Flip(ecran);
        SDL_Delay(120);
        SDL_BlitSurface( b->owl[j], NULL,ecran,&(b->owll));
        SDL_Flip(ecran);
        SDL_Delay(130);
    }
    SDL_Delay(2000);
    for(j=1; j<14; j++)
    {
        SDL_BlitSurface( b->owl[j], NULL,ecran,&(b->owll));
        SDL_Flip(ecran);
        SDL_Delay(130);
    }

}
//***********************************background2*******************************
void initBack2(background *b2)
{

	Mix_Music  *music2;
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    	{
        	printf("%s", Mix_GetError());
    	}
	music2 = Mix_LoadMUS("../Background/map12.mp3");	
	Mix_PlayMusic(music2,-1) ;

    char ch2[50];
    int i,j;
    char chh2[50];


	    for(j=1; j<10; j++)
    {
        sprintf(ch2,"../Background/dhaw/%d.png",j);
        b2->porte2[j]=IMG_Load(ch2);
    }
    for(i=1; i<12; i++)
    {
        sprintf(chh2,"../Background/owl2/%d.png",i);
        b2->owl2[i]=IMG_Load(chh2);
    }

	b2->calque_background2=NULL;
	b2->calque_background2=IMG_Load("masque2.png");
	b2->afficher_background2=NULL;
	b2->afficher_background2=IMG_Load("map12.png");
	b2->aff2=NULL;
	b2->aff2=IMG_Load("map2.png");
	b2->pos_background20.x=0;
	b2->pos_background20.y=0;
	b2->pos_background22.x=0;
	b2->pos_background22.y=0;
	b2->pos_background22.h=1020;
	b2->pos_background22.w=1920;
	b2->port2.x=  0 ;
        b2->port2.y=  0 ;
        b2->owll2.x=  0 ;
        b2->owll2.y=  0 ;
}


void afficherBack2(background b2,SDL_Surface *ecran)
{	
	SDL_BlitSurface(b2.afficher_background2,&(b2.pos_background22),ecran,&(b2.pos_background20));
}


void animerBackground2(background *b2,SDL_Surface *ecran)
{   
    int j;
    char ch2[50];
    int i;
    char chh2[50];
     SDL_BlitSurface(b2->aff2,NULL,ecran,&(b2->port2));
    for(j=1; j<10; j++)
    {
        SDL_BlitSurface( b2->porte2[j], NULL,ecran,&(b2->port2));
        SDL_Flip(ecran);
        SDL_Delay(130);      
    }
SDL_Delay(1000);
SDL_BlitSurface(b2->aff2,NULL,ecran,&(b2->port2));
    for(j=1; j<12; j++)
    {
        SDL_BlitSurface( b2->owl2[j], NULL,ecran,&(b2->owll2));
        SDL_Flip(ecran);
        SDL_Delay(130);
    }
SDL_Delay(2000);
    for(j=1; j<12; j++)
    {
        SDL_BlitSurface( b2->owl2[j], NULL,ecran,&(b2->owll2));
        SDL_Flip(ecran);
        SDL_Delay(130);
    }


}


//***********************************background3*******************************


void initBack3(background *b3)
{

	Mix_Music  *music3;
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    	{
        	printf("%s", Mix_GetError());
    	}
	music3 = Mix_LoadMUS("../Background/map13.mp3");	
	Mix_PlayMusic(music3,-1) ;

    char ch3[50];
    int i,j;
    char chh3[50];


	    for(j=1; j<14; j++)
    {
        sprintf(ch3,"../Background/porte3/%d.png",j);
        b3->porte3[j]=IMG_Load(ch3);
    }
    for(i=1; i<14; i++)
    {
        sprintf(chh3,"../Background/owl3/%d.png",i);
        b3->owl3[i]=IMG_Load(chh3);
    }

	b3->calque_background3=NULL;
	b3->calque_background3=IMG_Load("masque3.png");
	b3->afficher_background3=NULL;
	b3->afficher_background3=IMG_Load("map13.png");
	b3->aff3=NULL;
	b3->aff3=IMG_Load("map3.png");
	b3->pos_background3.x=0;
	b3->pos_background3.y=0;
	b3->pos_background23.x=0;
	b3->pos_background23.y=0;
	b3->pos_background23.h=1020;
	b3->pos_background23.w=1920;
	b3->port3.x=  0 ;
        b3->port3.y=  0 ;
        b3->owll3.x=  0 ;
        b3->owll3.y=  0 ;
}

void afficherBack3(background b3,SDL_Surface *ecran)
{	
	SDL_BlitSurface(b3.afficher_background3,&(b3.pos_background23),ecran,&(b3.pos_background3));
}


void animerBackground3(background *b3,SDL_Surface *ecran)
{   
    int j;
    char ch3[50];
    int i;
    char chh3[50];
     SDL_BlitSurface(b3->aff3,NULL,ecran,&(b3->port3));
    for(j=1; j<14; j++)
    {
        SDL_BlitSurface( b3->porte3[j], NULL,ecran,&(b3->port3));
        SDL_Flip(ecran);
        SDL_Delay(120);
        SDL_BlitSurface( b3->owl3[j], NULL,ecran,&(b3->owll3));
        SDL_Flip(ecran);
        SDL_Delay(130);
    }
    SDL_Delay(2000);
    for(j=1; j<14; j++)
    {
        SDL_BlitSurface( b3->owl3[j], NULL,ecran,&(b3->owll3));
        SDL_Flip(ecran);
        SDL_Delay(130);
    }


}



