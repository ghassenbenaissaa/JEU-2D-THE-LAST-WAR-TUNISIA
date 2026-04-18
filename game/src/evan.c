#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header.h"

void initialiser_evan(hero *evan)
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
			
	
	
evan->afficher_vie[0]=IMG_Load("vie0.png");
		evan->afficher_vie[1]=IMG_Load("vie1.png");
		evan->afficher_vie[2]=IMG_Load("vie2.png");
		evan->afficher_vie[3]=IMG_Load("vie3.png");
	
	evan->vie=3;

	evan->farm=0;
	evan->hit=0;


	evan->pos_vie.y=0;
	evan->pos_vie.x=0;
	evan->heromoved=0;
	
	evan->pos_hero2.x=120;
	evan->pos_hero2.y=680;



}
void afficher_evan(hero evan,SDL_Surface *ecran){
        if (evan.mouvment==9)
SDL_BlitSurface(evan.afficher_hero[8],NULL,ecran,&(evan.pos_hero2));
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



void initialiser_evan2(hero *evan2)
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



		evan2->afficher_hero2[0]=IMG_Load("a1.png");
		evan2->afficher_hero2[1]=IMG_Load("a2.png");
		evan2->afficher_hero2[2]=IMG_Load("a3.png");
		evan2->afficher_hero2[3]=IMG_Load("a4.png");
		evan2->afficher_hero2[4]=IMG_Load("a5.png");
		evan2->afficher_hero2[5]=IMG_Load("a6.png");
		evan2->afficher_hero2[6]=IMG_Load("a7.png");
		evan2->afficher_hero2[7]=IMG_Load("a8.png");
		evan2->afficher_hero2[8]=IMG_Load("a9.png");

	
		evan2->afficher_herod2[0]=IMG_Load("a10.png");
		evan2->afficher_herod2[1]=IMG_Load("a11.png");
		evan2->afficher_herod2[2]=IMG_Load("a12.png");
		evan2->afficher_herod2[3]=IMG_Load("a13.png");
		evan2->afficher_herod2[4]=IMG_Load("a14.png");
		evan2->afficher_herod2[5]=IMG_Load("a15.png");
		evan2->afficher_herod2[6]=IMG_Load("a16.png");
		evan2->afficher_herod2[7]=IMG_Load("a55.png");
		evan2->afficher_herod2[8]=IMG_Load("a57.png");
			
	
	
		evan2->afficher_vie2[0]=IMG_Load("vie0.png");
		evan2->afficher_vie2[1]=IMG_Load("vie1.png");
		evan2->afficher_vie2[2]=IMG_Load("vie2.png");
		evan2->afficher_vie2[3]=IMG_Load("vie3.png");
	
	evan2->vie2=3;

	evan2->farm2=0;
	evan2->hit2=0;


	evan2->pos_vie2.y=0;
	evan2->pos_vie2.x=0;
	evan2->heromoved2=0;
	
	evan2->pos_hero22.x=120;
	evan2->pos_hero22.y=680;



}
void afficher_evan2(hero evan2,SDL_Surface *ecran){
        if (evan2.mouvment2==9)
SDL_BlitSurface(evan2.afficher_hero2[8],NULL,ecran,&(evan2.pos_hero22));
	if (evan2.mouvment2==1)
		SDL_BlitSurface(evan2.afficher_hero2[evan2.farm2],NULL,ecran,&(evan2.pos_hero22));
	if (evan2.mouvment2==2)
		SDL_BlitSurface(evan2.afficher_herod2[evan2.farm2],NULL,ecran,&(evan2.pos_hero22));
	if (evan2.mouvment2==3)
		SDL_BlitSurface(evan2.afficher_herod2[7],NULL,ecran,&(evan2.pos_hero22));
if (evan2.mouvment2==4)
		SDL_BlitSurface(evan2.afficher_herod2[8],NULL,ecran,&(evan2.pos_hero22));
}








//***********************************background3*******************************
void initialiser_evan3(hero *evan3)

{
	evan3->afficher_hero3[0]=NULL;
		evan3->afficher_hero3[1]=NULL;
		evan3->afficher_hero3[2]=NULL;
		evan3->afficher_hero3[3]=NULL;
		evan3->afficher_hero3[4]=NULL;
		evan3->afficher_hero3[5]=NULL;
		evan3->afficher_hero3[6]=NULL;
		evan3->afficher_hero3[7]=NULL;
		evan3->afficher_hero3[8]=NULL;

		evan3->afficher_herod3[0]=NULL;
		evan3->afficher_herod3[1]=NULL;
		evan3->afficher_herod3[2]=NULL;
		evan3->afficher_herod3[3]=NULL;
		evan3->afficher_herod3[4]=NULL;
		evan3->afficher_herod3[5]=NULL;
		evan3->afficher_herod3[6]=NULL;
		evan3->afficher_herod3[7]=NULL;
		evan3->afficher_herod3[8]=NULL;



		evan3->afficher_hero3[0]=IMG_Load("a1.png");
		evan3->afficher_hero3[1]=IMG_Load("a2.png");
		evan3->afficher_hero3[2]=IMG_Load("a3.png");
		evan3->afficher_hero3[3]=IMG_Load("a4.png");
		evan3->afficher_hero3[4]=IMG_Load("a5.png");
		evan3->afficher_hero3[5]=IMG_Load("a6.png");
		evan3->afficher_hero3[6]=IMG_Load("a7.png");
		evan3->afficher_hero3[7]=IMG_Load("a8.png");
		evan3->afficher_hero3[8]=IMG_Load("a9.png");

	
		evan3->afficher_herod3[0]=IMG_Load("a10.png");
		evan3->afficher_herod3[1]=IMG_Load("a11.png");
		evan3->afficher_herod3[2]=IMG_Load("a12.png");
		evan3->afficher_herod3[3]=IMG_Load("a13.png");
		evan3->afficher_herod3[4]=IMG_Load("a14.png");
		evan3->afficher_herod3[5]=IMG_Load("a15.png");
		evan3->afficher_herod3[6]=IMG_Load("a16.png");
		evan3->afficher_herod3[7]=IMG_Load("a55.png");
		evan3->afficher_herod3[8]=IMG_Load("a57.png");
		


		evan3->pos_hero23.x=260;
		evan3->pos_hero23.y=810;
		evan3->farm3=0;
	
	
evan3->afficher_vie3[0]=IMG_Load("vie0.png");
		evan3->afficher_vie3[1]=IMG_Load("vie1.png");
		evan3->afficher_vie3[2]=IMG_Load("vie2.png");
		evan3->afficher_vie3[3]=IMG_Load("vie3.png");
	
	evan3->vie3=3;

	
	evan3->hit3=0;


	evan3->pos_vie3.y=0;
	evan3->pos_vie3.x=0;
	evan3->heromoved3=0;

}

void afficher_evan3(hero evan3,SDL_Surface *ecran){
        if (evan3.mouvment3==9)
SDL_BlitSurface(evan3.afficher_hero3[8],NULL,ecran,&(evan3.pos_hero23));
	if (evan3.mouvment3==1)
		SDL_BlitSurface(evan3.afficher_hero3[evan3.farm3],NULL,ecran,&(evan3.pos_hero23));
	if (evan3.mouvment3==2)
		SDL_BlitSurface(evan3.afficher_herod3[evan3.farm3],NULL,ecran,&(evan3.pos_hero23));
	if (evan3.mouvment3==3)
		SDL_BlitSurface(evan3.afficher_herod3[7],NULL,ecran,&(evan3.pos_hero23));
if (evan3.mouvment3==4)
		SDL_BlitSurface(evan3.afficher_herod3[8],NULL,ecran,&(evan3.pos_hero23));
}

