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

void main1()
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
	save s;
	SDL_Rect posperso,posennemi,poscam;
SDL_Rect pos_hero2;
	int vies,temps,score;
	Enigme e;
tempss temp ; 
SDL_Color rouge = {255,255,255};
char nomjoueur[30];
char nomfich[50];
int scoree;
char nom[20],meilleurn[20];
SDL_Surface *image_scr;
/*printf("\n\n\n         ---------------------------------\n");
    printf("        |         ENTER YOUR NAME       |\n");
    printf("         ---------------------------------\n");
printf("\n");
printf("             ->");
scanf("%s",nom);

printf("\n\n\n         ---------------------------------\n");*/
 	
//*********************************ennemie*****************************
Enemy e1;
int stat;
SDL_Surface  *coeur=NULL;
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
initBack(&b);
   initminimap(&m);
   initialiser_evan(&evan);

 gameover=IMG_Load("gameover.png");
coeur=	IMG_Load("vie3.png");
e1=InitEnemy(e1,990,700);
   animerBackground (&b,ecran);
	int Game;

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
			afficherBack(b,ecran);
			//afficherminimap(m,ecran);
			afficher_evan(evan,ecran);
			evan.farm=animation_perso(evan);
majminimap (&m ,ecran,evan.mouvment,c,&evan);	
e1=MoveEnemy(e1,evan.pos_hero2,&stat,evan.heromoved);
			e1=AnimateEnemy(e1,stat);
			 AfficherEnemy(e1,ecran);
                        SDL_BlitSurface(coeur,NULL,ecran,&b.pos_background);
		c=collisionPP(b.calque_background,evan.afficher_hero[evan.farm],evan.pos_hero2,b.pos_background2);//.....
                        scrolling(&evan,&b,c);
                        if (c==3)
{
			evan.hit=1;
			m.posminijoueur.x=m.posminijoueur.x-50;
}
			gestionvie(&evan,ecran);
			affichiervie(evan,ecran);
                        		
			SDL_Flip(ecran);
			evan.mouvment= mouvment(evan,&event);	
                        if (evan.vie==0){
			SDL_BlitSurface(gameover,NULL,ecran,&b.pos_background);
			SDL_Flip(ecran);
	                initBack(&b);
    	                initialiser_evan(&evan);
			initminimap (&m);
			//afficherminimap(m,ecran);	
}
                        if (evan.pos_hero2.x==1560)	
{	
			Init_Enigme(&e, "questions.txt", "reponses.txt" , "vraireponses.txt") ;    			        continuer=Play_Enigme(&e,ecran,&Game);
    			sauvegarder (scoree,nom,"sauvegarde.txt",&evan,temp);
}			
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
                Liberer(&m);	
}
