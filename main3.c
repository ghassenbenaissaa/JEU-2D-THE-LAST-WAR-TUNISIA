#include <stdio.h>
#include "SDL/SDL.h"
#include <string.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include"header.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>
void main3()
{
	SDL_Surface *ecran =NULL,*gameover=NULL;
	SDL_Surface *porte[14],*owl[14];
	SDL_Rect back,port,owll ;
        SDL_Event event;
	int continuer =1;
	int coe;
	int c,i,j;
	background b;
	hero evan ;
	evan.farm=0;
	Mix_Music *music=NULL;
	minimap m;
	tempss temp ; 
	SDL_Color rouge = {255,255,255};
	char nomjoueur[30];
	char nomfich[50];
	int scoree,scoree2,scoree3;
	char nom[20],meilleurn[20];
	SDL_Surface *image_scr;

 	
//***************enigme3****************
	save s;
	SDL_Rect posperso,posennemi,poscam;
	SDL_Rect pos_hero23;
	int vies,temps,score;
	Enigme eee;
	int Game;

//*********************************ennemie*****************************
	Enemy e1;
	int stat;
	SDL_Surface  *coeur=NULL;
//*********************************ennemie2*****************************
	Enemy e2;
	int stat2;
	SDL_Surface  *coeur2=NULL;
//*********************************ennemie3*****************************
	Enemy e3;
	int stat3;
	SDL_Surface  *coeur3=NULL;
//***********************************background2*******************************
	SDL_Surface *porte2[10],*owl2[12];
	SDL_Rect back2,port2,owll2 ;
        SDL_Event event2;
	int coe2;
	int c2;
	background b2;
	hero evan2 ;
	evan2.farm2=0;
	Mix_Music *music2=NULL;
	minimap m2;
//***********************************background3*******************************
	SDL_Surface *porte3[14],*owl3[14];
	SDL_Rect back3,port3,owll3 ;
        SDL_Event event3;
	int coe3;
	int c3;
	background b3;
	hero evan3 ;
	evan3.farm3=0;
	Mix_Music *music3=NULL;
	minimap m3;	
//***************main****************************
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
  	SDL_Init(SDL_INIT_VIDEO);
  	ecran = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	temp=initialiser_temp (temp);   
	initBack3(&b3);
        initminimap3(&m3);
        initialiser_evan3(&evan3);
        gameover=IMG_Load("gameover.png");
        coeur3=IMG_Load("vie3.png");
        e3=InitEnemy3(e3,990,870);
        animerBackground3(&b3,ecran);
	scoree3=3;
	while(continuer)
        {
		temp.temp=TTF_RenderText_Blended(temp.police,temp.chaine,rouge);
		temp.tempactuel=SDL_GetTicks();
		if (temp.tempactuel- temp.tempprecedent >1000  )
			{
			temp.seconde1++;
			temp.tempprecedent= temp.tempactuel;
			}
		if (temp.seconde1>9)
			{
			temp.seconde1=0;
			temp.seconde2++;
			}
		if (temp.seconde2>=6)
			{
			temp.seconde2=0;
			temp.minute1++;
			}
		if (temp.minute1>=9)
			{
			temp.minute1=0;
			temp.minute2++;
			}
		if (temp.minute2>=6)
			{
			temp.minute2=0;
			temp.heur1++;
			}
		if (temp.heur1>=9)
			{
			temp.heur1=0;
			temp.heur2++;
			}
		sprintf(temp.chaine,"%d %d : %d %d ",temp.minute2,temp.minute1,temp.seconde2,temp.seconde1);
		SDL_BlitSurface(temp.temp,NULL,ecran,&temp.position_temp);
		SDL_Flip(ecran) ; 
		afficherBack3(b3,ecran);
		//afficherminimap3(m3,ecran);
			
		afficher_evan3(evan3,ecran);
		evan3.farm3=animation_perso3(evan3);
majminimap3 (&m3 ,ecran,evan3.mouvment3,c3,&evan3);	
		e3=MoveEnemy3(e3,evan3.pos_hero23,&stat3,evan3.heromoved3);
		e3=AnimateEnemy3(e3,stat3);
		AfficherEnemy3(e3,ecran);
		SDL_BlitSurface(coeur3,NULL,ecran,&b3.pos_background3);		
		c3=collisionPP3(b3.calque_background3,evan3.afficher_hero3[evan3.farm3],evan3.pos_hero23,b3.pos_background23);//.....
		scrolling3(&evan3,&b3,c3);
		if (c3==3){
			evan3.hit3=1;
m3.posminijoueur3.x=m3.posminijoueur3.x-50;}
			gestionvie3(&evan3,ecran);
			affichiervie3(evan3,ecran);
					
			SDL_Flip(ecran);
			evan3.mouvment3= mouvment3(evan3,&event3);	
			if (evan3.vie3==0)
			{
			SDL_BlitSurface(gameover,NULL,ecran,&b3.pos_background3);
			SDL_Flip(ecran);
	       initBack3(&b3);
    	       initialiser_evan3(&evan3);
initminimap3 (&m3);	

	                }
		if (evan3.pos_hero23.x==1560)	
 			{	
			Init_Enigmeee(&eee, "questions.txt", "reponses.txt" , "vraireponses.txt");       			
                        continuer=Play_Enigmeee(&eee,ecran,&Game);
			sauvegarder3 (scoree3,nom,"sauvegarde_lev3.txt",&evan3,temp);
  			}			
	SDL_Delay(20);	
	}
		if(Game)
			{ 
		printf("you win!!!");
                animerEnigme(porte,&port,ecran);
                update_save (&s, posperso, posennemi, poscam, vies, temps, score);
	        enregistrer (s);
			}
		else 
          	if (!Game)
			{	
		animerEnigmee(porte,&port,ecran);
		printf("you lost!!! %d ",Game);
		update_save (&s, posperso, posennemi, poscam, vies, temps, score);
	        enregistrer (s);          
			}
       		/*meilleur("score.txt",&scoree,meilleurn);
                SDL_BlitSurface(image_scr,NULL,ecran,NULL);
                affichermeilleur (ecran,scoree,meilleurn);*/  
                //Liberer(&m3);	
}
