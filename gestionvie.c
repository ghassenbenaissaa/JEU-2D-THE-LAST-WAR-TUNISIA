#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header.h"
#include <time.h>
#include <unistd.h>

void affichiervie(hero evan, SDL_Surface *ecran){
	SDL_BlitSurface(evan.afficher_vie[evan.vie],NULL,ecran,&evan.pos_vie);
}
int gestionvie(hero *evan, SDL_Surface *ecran){
	
	
	if((evan->hit==1)&&(evan->vie!=0)){
		evan->vie--;
	affichiervie(*evan,ecran);
	SDL_Flip(ecran);
	usleep(1000000);
	evan->pos_hero2.x=120;
	evan->pos_hero2.y=0;
	
	}
	evan->hit=0;
	if (evan->vie==0)
	return 0;
	else return 1;

}


void affichiervie2(hero evan2, SDL_Surface *ecran){
	SDL_BlitSurface(evan2.afficher_vie2[evan2.vie2],NULL,ecran,&evan2.pos_vie2);
}
int gestionvie2(hero *evan2, SDL_Surface *ecran){
	
	
	if((evan2->hit2==1)&&(evan2->vie2!=0)){
		evan2->vie2--;
	affichiervie2(*evan2,ecran);
	SDL_Flip(ecran);
	usleep(1000000);
	evan2->pos_hero22.x=120;
	evan2->pos_hero22.y=0;
	
	}
	evan2->hit2=0;
	if (evan2->vie2==0)
	return 0;
	else return 1;

}




void affichiervie3(hero evan3, SDL_Surface *ecran){
	SDL_BlitSurface(evan3.afficher_vie3[evan3.vie3],NULL,ecran,&evan3.pos_vie3);
}
int gestionvie3(hero *evan3, SDL_Surface *ecran){
	
	
	if((evan3->hit3==1)&&(evan3->vie3!=0)){
		evan3->vie3--;
	affichiervie3(*evan3,ecran);
	SDL_Flip(ecran);
	usleep(1000000);
	evan3->pos_hero23.x=120;
	evan3->pos_hero23.y=0;
	
	}
	evan3->hit3=0;
	if (evan3->vie3==0)
	return 0;
	else return 1;

}
