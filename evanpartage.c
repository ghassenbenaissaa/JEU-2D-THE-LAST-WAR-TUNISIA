#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"headerpartage.h"

void initialiser_evanp(hero *evan)
{		
		evan->afficher_hero[0]=NULL;
		evan->afficher_hero[1]=NULL;
		evan->afficher_hero[2]=NULL;
		evan->afficher_hero[3]=NULL;
		evan->afficher_hero[4]=NULL;
		evan->afficher_hero[5]=NULL;
		evan->afficher_hero[6]=NULL;
		evan->afficher_hero[7]=NULL;
		evan->afficher_hero[8]=NULL;

		evan->afficher_herod[0]=NULL;
		evan->afficher_herod[1]=NULL;
		evan->afficher_herod[2]=NULL;
		evan->afficher_herod[3]=NULL;
		evan->afficher_herod[4]=NULL;
		evan->afficher_herod[5]=NULL;
		evan->afficher_herod[6]=NULL;
		evan->afficher_herod[7]=NULL;
		evan->afficher_herod[8]=NULL;



		evan->afficher_hero[0]=IMG_Load("1.png");
		evan->afficher_hero[1]=IMG_Load("2.png");
		evan->afficher_hero[2]=IMG_Load("3.png");
		evan->afficher_hero[3]=IMG_Load("4.png");
		evan->afficher_hero[4]=IMG_Load("5.png");
		evan->afficher_hero[5]=IMG_Load("6.png");
		evan->afficher_hero[6]=IMG_Load("7.png");
		evan->afficher_hero[7]=IMG_Load("8.png");
		evan->afficher_hero[8]=IMG_Load("9.png");

	
		evan->afficher_herod[0]=IMG_Load("10.png");
		evan->afficher_herod[1]=IMG_Load("11.png");
		evan->afficher_herod[2]=IMG_Load("12.png");
		evan->afficher_herod[3]=IMG_Load("13.png");
		evan->afficher_herod[4]=IMG_Load("14.png");
		evan->afficher_herod[5]=IMG_Load("15.png");
		evan->afficher_herod[6]=IMG_Load("16.png");
		evan->afficher_herod[7]=IMG_Load("55.png");
		evan->afficher_herod[8]=IMG_Load("57.png");
			
	
	
		
	evan->heromoved=0;
	evan->farm=0;
	evan->pos_hero2.x=120;
	evan->pos_hero2.y=680;

}
void afficher_evanp(hero evan,SDL_Surface *ecran){
        if (evan.mouvment==9)
SDL_BlitSurface(evan.afficher_hero[1],NULL,ecran,&(evan.pos_hero2));
	if (evan.mouvment==1)
		SDL_BlitSurface(evan.afficher_hero[evan.farm],NULL,ecran,&(evan.pos_hero2));
	if (evan.mouvment==2)
		SDL_BlitSurface(evan.afficher_herod[evan.farm],NULL,ecran,&(evan.pos_hero2));
	if (evan.mouvment==3)
		SDL_BlitSurface(evan.afficher_herod[7],NULL,ecran,&(evan.pos_hero2));
if (evan.mouvment==4)
		SDL_BlitSurface(evan.afficher_herod[8],NULL,ecran,&(evan.pos_hero2));
}


//***********************************background2*******************************



void initialiser_evan2p(hero *evan2)
{		
		evan2->afficher_hero2[0]=NULL;
		evan2->afficher_hero2[1]=NULL;
		evan2->afficher_hero2[2]=NULL;
		evan2->afficher_hero2[3]=NULL;
		evan2->afficher_hero2[4]=NULL;
		evan2->afficher_hero2[5]=NULL;
		evan2->afficher_hero2[6]=NULL;
		evan2->afficher_hero2[7]=NULL;
		evan2->afficher_hero2[8]=NULL;

		evan2->afficher_herod2[0]=NULL;
		evan2->afficher_herod2[1]=NULL;
		evan2->afficher_herod2[2]=NULL;
		evan2->afficher_herod2[3]=NULL;
		evan2->afficher_herod2[4]=NULL;
		evan2->afficher_herod2[5]=NULL;
		evan2->afficher_herod2[6]=NULL;
		evan2->afficher_herod2[7]=NULL;
		evan2->afficher_herod2[8]=NULL;



		evan2->afficher_hero2[0]=IMG_Load("1.png");
		evan2->afficher_hero2[1]=IMG_Load("2.png");
		evan2->afficher_hero2[2]=IMG_Load("3.png");
		evan2->afficher_hero2[3]=IMG_Load("4.png");
		evan2->afficher_hero2[4]=IMG_Load("5.png");
		evan2->afficher_hero2[5]=IMG_Load("6.png");
		evan2->afficher_hero2[6]=IMG_Load("7.png");
		evan2->afficher_hero2[7]=IMG_Load("8.png");
		evan2->afficher_hero2[8]=IMG_Load("9.png");

	
		evan2->afficher_herod2[0]=IMG_Load("10.png");
		evan2->afficher_herod2[1]=IMG_Load("11.png");
		evan2->afficher_herod2[2]=IMG_Load("12.png");
		evan2->afficher_herod2[3]=IMG_Load("13.png");
		evan2->afficher_herod2[4]=IMG_Load("14.png");
		evan2->afficher_herod2[5]=IMG_Load("15.png");
		evan2->afficher_herod2[6]=IMG_Load("16.png");
		evan2->afficher_herod2[7]=IMG_Load("55.png");
		evan2->afficher_herod2[8]=IMG_Load("57.png");
			
	
	
		

	


evan2->farm2=0;
	
	evan2->heromoved2=0;
	evan2->pos_hero22.x=1250;
	evan2->pos_hero22.y=680;



}
void afficher_evan2p(hero evan2,SDL_Surface *ecran){
        if (evan2.mouvment2==9)
SDL_BlitSurface(evan2.afficher_hero2[1],NULL,ecran,&(evan2.pos_hero22));
	if (evan2.mouvment2==1)
		SDL_BlitSurface(evan2.afficher_hero2[evan2.farm2],NULL,ecran,&(evan2.pos_hero22));
	if (evan2.mouvment2==2)
		SDL_BlitSurface(evan2.afficher_herod2[evan2.farm2],NULL,ecran,&(evan2.pos_hero22));
	if (evan2.mouvment2==3)
		SDL_BlitSurface(evan2.afficher_herod2[7],NULL,ecran,&(evan2.pos_hero22));
if (evan2.mouvment2==4)
		SDL_BlitSurface(evan2.afficher_herod2[8],NULL,ecran,&(evan2.pos_hero22));
}



