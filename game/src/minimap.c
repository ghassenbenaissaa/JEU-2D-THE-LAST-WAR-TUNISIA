#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "header.h"
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>
#include <math.h>
//**************************Background1***********************************
void initminimap (minimap *m)
{ m->nbmoved=0;
	m->minimap=IMG_Load("minimap1.png");
		if (m->minimap==NULL) 
{
			printf("Unable to load png: %s \n ",SDL_GetError() );
			return;
	}
		
	m->posminimap.x=600;
	m->posminimap.y=0;

m->petit=IMG_Load("petit.png");
		if (m->petit==NULL) 
{
			printf("Unable to load png: %s \n ",SDL_GetError() );
			return;
}
	m->posminijoueur.x=605;
	m->posminijoueur.y=75;

	

}
/*void afficherminimap( minimap m,SDL_Surface* ecran)
{                        

SDL_BlitSurface(m.minimap, NULL, ecran, &m.posminimap);
SDL_BlitSurface(m.petit, NULL, ecran, &m.posminijoueur);
}*/

void Liberer(minimap *m)
{

SDL_FreeSurface(m->minimap);
SDL_FreeSurface(m->petit);
}
void majminimap(minimap *m,SDL_Surface *ecran,int mouvment,int co,hero *evan){

float red_y=10.2;
	SDL_BlitSurface(m->minimap, NULL, ecran, &m->posminimap);
SDL_BlitSurface(m->petit, NULL, ecran, &m->posminijoueur);
	if (mouvment==1)
if(co!=1)
{		m->nbmoved+=1;
}	if (mouvment==2)
if(co!=1){
		m->nbmoved--;
}
		if (m->nbmoved==3){
		m->posminijoueur.x+=4;
		m->nbmoved=0;

}
	if (m->nbmoved==-3){
		m->posminijoueur.x-=4;
		m->nbmoved=0;
	}


 if (mouvment==3)

{if (evan->pos_hero2.y>50){

 m->posminijoueur.y=evan->pos_hero2.y*(red_y/100)+0;
//m->posminijoueur.y=m->posminijoueur.y-2;
}

  
}
if (mouvment==4)
 {
if ((co!=2)&&(co!=1)&&(m->posminijoueur.y<75))
  //m->posminijoueur.y=m->posminijoueur.y+2;
 m->posminijoueur.y=evan->pos_hero2.y*(red_y/100)+0;
}

if ((evan->mouvment!=3)&&(co!=2)&&(co!=1)&&(m->posminijoueur.y<75))
 // m->posminijoueur.y=m->posminijoueur.y+2;
   m->posminijoueur.y=evan->pos_hero2.y*(red_y/100)+0;










}

tempss initialiser_temp (tempss temp)
{
temp.heur1=0;
temp.minute1=0;
temp.seconde1=0;
temp.heur2=0;
temp.minute2=0;
temp.seconde2=0;
temp.tempactuel=0;
temp.temp=NULL;
temp.tempprecedent=0;
temp.position_temp.x=200;
temp.position_temp.y=0;
temp.police=TTF_OpenFont("arial.ttf",40);

	return temp;
}
void sauvegarder (int scoree , char nomjoueur[] ,char nomfich[],hero *evan,tempss temp)
{
  FILE *fic;
  fic = fopen(nomfich,"a+"); 
  if(fic == NULL) 
   {
      printf("Error!");   
      exit(1);             
   }
scoree=temp.seconde1+(temp.seconde2*10)+(temp.minute1*100);
  fprintf(fic,"%d \n",scoree); 
  fprintf(fic,"\n");
  fclose(fic); 
}

void meilleur(char nomfich[],int * scoree,char nomjoueur[])
{
  typedef struct data{
    char nom[20];
    int scr;
  }data;

  char tempchar[20];
  int i=0,j=0,tempint=0;
  data data_tab[100];
  FILE *fic;
  fic = fopen(nomfich,"r");
  if(fic == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   /// loading all data
   while (fscanf(fic,"%s \t %d \n",data_tab[i].nom,&(data_tab[i]).scr)!=EOF)
        i++;
  /// trouver meilleur score
  for(j=0;j<i;j++)
  {
    if(data_tab[j].scr>tempint)
    {
      tempint=data_tab[j].scr;
      strcpy(tempchar,data_tab[j].nom);
    }
  } 
  /// return best score and name
  *scoree=tempint;
  strcpy(nomjoueur,tempchar);
  fclose(fic); 
}

void affichermeilleur (SDL_Surface *ecran,int scoree,char nomjoueur[])
{
    TTF_Init();
    TTF_Font *police=NULL;
    police=TTF_OpenFont("arial.ttf",70);
    SDL_Color couleur= {255,255,255};
    SDL_Rect postext,best;
    best.x=850;
    best.y=400;
    postext.x=900;
    postext.y=200;
    char s[20],b[50];
    sprintf(s,"BEST SCORE");
    sprintf(b,"%s   ::  %d",nomjoueur,scoree);
    SDL_Surface *txt;
    SDL_Surface *info;
    txt=TTF_RenderText_Blended(police,s,couleur);
    info=TTF_RenderText_Blended(police,b,couleur);
    SDL_BlitSurface(txt,NULL,ecran,&postext);
    SDL_BlitSurface(info,NULL,ecran,&best);
}
void enter_name(char nomfich[], SDL_Surface *ecran , char nomh[] )
{
FILE *fic ;
SDL_Color couleur={255,255,255}  ;
int continuer=1 ;
char ch[20] ; 
SDL_Surface *texte=NULL ; 
SDL_Rect pos_texte  ; 
TTF_Font *police=NULL ;  
SDL_Event event ;
  fic=fopen(nomfich,"a+") ; 
  police=TTF_OpenFont("font.ttf",40) ; 
  pos_texte.x=780; 
  pos_texte.y=579 ;
      //////
SDL_Surface *flu=NULL;       
SDL_Rect pos_flu ; 
flu=IMG_Load("name.png");
pos_flu.x=0;
pos_flu.y=0;              
SDL_BlitSurface(flu,NULL,ecran,&pos_flu);                  
SDL_Flip(ecran);
       

  while (continuer)
  {
    SDL_WaitEvent(&event) ;   
    switch(event.type)
    {
      case SDL_KEYDOWN :
         switch(event.key.keysym.sym)
         {
            case SDLK_RETURN :
            continuer =0 ; 
            break ;
            case SDLK_0 :
            strcat(nomh,"0") ;
            strcat(ch,"0") ;
            break ;
            case SDLK_1 :
            strcat(nomh,"1") ;
            strcat(ch,"1") ;
            break ;
            case SDLK_2 :
            strcat(nomh,"2") ;
            strcat(ch,"2") ;
            break ;
            case SDLK_3 :
            strcat(nomh,"3") ;
            strcat(ch,"3") ;
            break ;
            case SDLK_4:
            strcat(nomh,"4") ;
            strcat(ch,"4") ;
            break ;
            case SDLK_5 :
            strcat(nomh,"5") ;
            strcat(ch,"5") ;
            break ;
            case SDLK_6 :
            strcat(nomh,"6") ;
            strcat(ch,"6") ;
            break ;
            case SDLK_7 :
            strcat(nomh,"7") ;
            strcat(ch,"7") ;
            break ;
            case SDLK_8:
            strcat(nomh,"8") ;
            strcat(ch,"8") ;
            break ;
            case SDLK_9:
            strcat(nomh,"9") ;
            strcat(ch,"9") ;
            break ;
            case SDLK_a  :
            strcat(nomh,"a") ;
            strcat(ch,"a") ;
            break ;
            case SDLK_b :
            strcat(nomh,"b") ;
             strcat(ch,"b") ;
            break ;  
            case SDLK_c :
            strcat(nomh,"c") ;
            strcat(ch,"c") ;
            break ;  
            case SDLK_d :
            strcat(nomh,"d") ;
            strcat(ch,"d") ;
            break ;  
            case SDLK_e :
            strcat(nomh,"e") ;
            strcat(ch,"e") ;
            break ;  
            case SDLK_f :
            strcat(nomh,"f") ;
            strcat(ch,"f") ;
            break ;  
            case SDLK_g :
            strcat(nomh,"g") ;
            strcat(ch,"g") ;
            break ;  
            case SDLK_h :
            strcat(nomh,"h") ;
            strcat(ch,"h") ;
            break ;  
            case SDLK_i :
            strcat(nomh,"i") ;
            strcat(ch,"i") ;
            break ;  
            case SDLK_j :
            strcat(nomh,"j") ;
            strcat(ch,"j") ;
            break ;  
            case SDLK_k :
            strcat(nomh,"k") ;
            strcat(ch,"k") ;
            break ;  
            case SDLK_l :
            strcat(nomh,"l") ;
            strcat(ch,"l") ;
            break ;  
            case SDLK_m :
            strcat(nomh,"m") ;
            strcat(ch,"m") ;
            break ;  
            case SDLK_n :
            strcat(nomh,"n") ;
            strcat(ch,"n") ;
            break ;  
            case SDLK_o :
            strcat(nomh,"o") ;
            strcat(ch,"o") ;
            break ;  
            case SDLK_p :
            strcat(nomh,"p") ;
            strcat(ch,"p") ;
            break ;  
            case SDLK_q :
            strcat(nomh,"q") ;
            strcat(ch,"q") ;
            break ;  
            case SDLK_r :
            strcat(nomh,"r") ;
            strcat(ch,"r") ;
            break ;  
            case SDLK_s :
            strcat(nomh,"s") ;
            strcat(ch,"s") ;
            break ;  
            case SDLK_t :
            strcat(nomh,"t") ;
            strcat(ch,"t") ;
            break ;  
            case SDLK_u :
            strcat(nomh,"u") ;
            strcat(ch,"u") ;
            break ;  
            case SDLK_v :
            strcat(nomh,"v") ;
            strcat(ch,"v") ;
            break ;  
            case SDLK_w :
            strcat(nomh,"w") ;
            strcat(ch,"w") ;
            break ;  
            case SDLK_x :
            strcat(nomh,"x") ;
            strcat(ch,"x") ;
            break ;  
            case SDLK_y :
            strcat(nomh,"y") ;
            strcat(ch,"y") ;
            break ;  
            case SDLK_z :
            strcat(nomh,"z") ;
            strcat(ch,"z") ;
            break ;
         }  
    }
  }  
 texte=TTF_RenderText_Blended(police,ch,couleur) ;       
         SDL_BlitSurface(texte,NULL,ecran,&pos_texte) ;

  fprintf(fic,"%s \n",nomh) ;
  fclose(fic)  ;     
  TTF_CloseFont(police) ; 
  SDL_FreeSurface(texte) ;  
}

//**************************Background2***********************************
void initminimap2 (minimap *m2)
{ m2->nbmoved2=0;
	m2->minimap2=IMG_Load("minimap2.png");
		if (m2->minimap2==NULL) 
{
			printf("Unable to load png: %s \n ",SDL_GetError() );
			return;
	}
		
	m2->posminimap2.x=600;
	m2->posminimap2.y=0;

m2->petit2=IMG_Load("petit1.png");
		if (m2->petit2==NULL) 
{
			printf("Unable to load png: %s \n ",SDL_GetError() );
			return;
}
	m2->posminijoueur2.x=605;
	m2->posminijoueur2.y=60;

	

}

void afficherminimap2( minimap m2,SDL_Surface* ecran)
{                        

SDL_BlitSurface(m2.minimap2, NULL, ecran, &m2.posminimap2);
SDL_BlitSurface(m2.petit2, NULL, ecran, &m2.posminijoueur2);
}

void Liberer2(minimap *m2)
{
SDL_FreeSurface(m2->minimap2);
SDL_FreeSurface(m2->petit2);
}


void majminimap2(minimap *m2,SDL_Surface *ecran,int mouvment2,int co2,hero *evan2){

float red_y2=10.2;
	SDL_BlitSurface(m2->minimap2, NULL, ecran, &m2->posminimap2);
SDL_BlitSurface(m2->petit2, NULL, ecran, &m2->posminijoueur2);
	if (mouvment2==1)
if(co2!=1)
{		m2->nbmoved2+=1;
}	if (mouvment2==2)
if(co2!=1){
		m2->nbmoved2--;
}
		if (m2->nbmoved2==3){
		m2->posminijoueur2.x+=4;
		m2->nbmoved2=0;

}
	if (m2->nbmoved2==-3){
		m2->posminijoueur2.x-=4;
		m2->nbmoved2=0;
	}


 if (mouvment2==3)

{if (evan2->pos_hero22.y>50){

 m2->posminijoueur2.y=evan2->pos_hero22.y*(red_y2/100)+0;
}

  
}
if (mouvment2==4)
 {
if ((co2!=2)&&(co2!=1)&&(m2->posminijoueur2.y<75))
 m2->posminijoueur2.y=evan2->pos_hero22.y*(red_y2/100)+0;
}

if ((evan2->mouvment2!=3)&&(co2!=2)&&(co2!=1)&&(m2->posminijoueur2.y<75))
   m2->posminijoueur2.y=evan2->pos_hero22.y*(red_y2/100)+0;



}
void sauvegarder2 (int scoree2 , char nomjoueur[] ,char nomfich[],hero *evan2,tempss temp)
{
  FILE *fic;
  fic = fopen(nomfich,"a+"); 
  if(fic == NULL) 
   {
      printf("Error!");   
      exit(1);             
   }
scoree2=temp.seconde1+(temp.seconde2*10)+(temp.minute1*100);
  fprintf(fic,"%d \n",scoree2); 
  fprintf(fic,"\n");
  fclose(fic); 
}

//**************************Background3***********************************

void initminimap3 (minimap *m3)
{ m3->nbmoved3=0;
	m3->minimap3=IMG_Load("minimap3.png");
		if (m3->minimap3==NULL) 
{
			printf("Unable to load png: %s \n ",SDL_GetError() );
			return;
	}
		
	m3->posminimap3.x=600;
	m3->posminimap3.y=0;

m3->petit3=IMG_Load("petit1.png");
		if (m3->petit3==NULL) 
{
			printf("Unable to load png: %s \n ",SDL_GetError() );
			return;
}
	m3->posminijoueur3.x=618;
	m3->posminijoueur3.y=75;

	

}
/*
void afficherminimap3( minimap m3,SDL_Surface* ecran)
{                        

SDL_BlitSurface(m3.minimap3, NULL, ecran, &m3.posminimap3);
SDL_BlitSurface(m3.petit3, NULL, ecran, &m3.posminijoueur3);
}
*/
void Liberer3(minimap *m3)
{
SDL_FreeSurface(m3->minimap3);
SDL_FreeSurface(m3->petit3);
}
void majminimap3(minimap *m3,SDL_Surface *ecran,int mouvment3,int co3,hero *evan3){

float red_y3=10.2;
	SDL_BlitSurface(m3->minimap3, NULL, ecran, &m3->posminimap3);
SDL_BlitSurface(m3->petit3, NULL, ecran, &m3->posminijoueur3);
	if (mouvment3==1)
if(co3!=1)
{		m3->nbmoved3+=1;
}	if (mouvment3==2)
if(co3!=1){
		m3->nbmoved3--;
}
		if (m3->nbmoved3==3){
		m3->posminijoueur3.x+=4;
		m3->nbmoved3=0;

}
	if (m3->nbmoved3==-3){
		m3->posminijoueur3.x-=4;
		m3->nbmoved3=0;
	}


 if (mouvment3==3)

{if (evan3->pos_hero23.y>50){

 m3->posminijoueur3.y=evan3->pos_hero23.y*(red_y3/100)+0;
}

  
}
if (mouvment3==4)
 {
if ((co3!=2)&&(co3!=1)&&(m3->posminijoueur3.y<75))
 m3->posminijoueur3.y=evan3->pos_hero23.y*(red_y3/100)+0;
}

if ((evan3->mouvment3!=3)&&(co3!=2)&&(co3!=1)&&(m3->posminijoueur3.y<75))
   m3->posminijoueur3.y=evan3->pos_hero23.y*(red_y3/100)+0;



}
void sauvegarder3 (int scoree3 , char nomjoueur[] ,char nomfich[],hero *evan3,tempss temp)
{
  FILE *fic;
  fic = fopen(nomfich,"a+"); 
  if(fic == NULL) 
   {
      printf("Error!");   
      exit(1);             
   }
scoree3=temp.seconde1+(temp.seconde2*10)+(temp.minute1*100);
  fprintf(fic,"%d \n",scoree3); 
  fprintf(fic,"\n");
  fclose(fic); 
}

