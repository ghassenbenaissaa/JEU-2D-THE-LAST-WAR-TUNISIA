#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "headerpartage.h"


int partage(int argc, char *argv[])
{
    SDL_Surface *ecran=NULL,*trait=NULL;
    int co,co2,i,j;
    background b,b2;
    int c;
    
    SDL_Rect p_trait;
    Mix_Music *music2=NULL;
    hero evan ;
    evan.farm=0;
    hero evan2 ;
	evan2.farm2=0;
    p_trait.x=largeur/2;
    p_trait.y=0;

    SDL_Init(SDL_INIT_VIDEO);
    ecran=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    initialiser_background1p(&b);
    initialiser_background2p(&b2);
   // initialiser_joueur1(&j1);
    initialiser_evanp( &evan);
    initialiser_evan2p( &evan2);
   // initialiser_joueur2(&j2);
    trait = IMG_Load("trait.png");
    SDL_BlitSurface(trait,NULL,ecran,&p_trait);
    SDL_Flip(ecran);
///////
   
    int continuer = 1;
    SDL_Event event;

    while(continuer)
    {
    afficherBackp(b,ecran);
    afficherBack2p(b2,ecran);
    afficher_evanp(evan,ecran);
			evan.farm=animation_persop(evan);
			afficher_evan2p(evan2,ecran);
			evan2.farm2=animation_perso2p(evan2);

	//**IMEN
	//SDL_BlitSurface(evan.afficher_hero[2],NULL,ecran,&(evan.pos_hero2)); 												
       	c=collisionPPp(b.calque_background,evan.afficher_hero[evan.farm],evan.pos_hero2,b.pos_background);
	scrollingp(&evan,&b,co);
SDL_Flip(ecran);
evan.mouvment= mouvmentp(evan,&event);
c=collisionPP2p(b.calque_background,evan2.afficher_hero2[evan2.farm2],evan.pos_hero22,b.pos_background);
	scrollingp(&evan2,&b2,co2);
SDL_Flip(ecran);
evan2.mouvment2= mouvment2p(evan2,&event);
		//****GH
  //  SDL_BlitSurface(j1.p[1],NULL,ecran,&j1.pp);
   // SDL_BlitSurface(j2.p[1],NULL,ecran,&j2.pp);
   // SDL_BlitSurface(trait,NULL,ecran,&p_trait);
    //SDL_Flip(ecran);
//evan2.farm2=animation_perso2(evan2);
	//evan.mouvment= mouvment(evan,&event);
         initialiser_evanp(&evan);
	initialiser_evan2p(&evan2);

        SDL_WaitEvent(&event);
        switch(event.type)
        {
    case SDL_QUIT:
        continuer=0;
        break;
        case SDL_KEYDOWN :			
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE :
                continuer = 0;
                break;
            }
            break;
        }

    }

}
