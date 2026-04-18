#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <math.h>
//***********************************ennemie*********************


typedef struct Enemy
{
  SDL_Surface *image[3];
  SDL_Surface *image2[3];
  SDL_Surface *Hit;
  SDL_Surface *imageActuel;
  SDL_Rect position;
  SDL_Rect positionO;
  int frame;
  int direction;
  int died;
SDL_Surface *en;
//***********enemy2*******************
  SDL_Surface *imagee2[3]; 
  SDL_Surface *image22[3];
  SDL_Surface *Hit2;
  SDL_Surface *imageActuel2;
  SDL_Rect position2;
  SDL_Rect positionO2;
  int frame2;
  int direction2;
  int died2;
SDL_Surface *en2;
//**************enemy3*****************
  SDL_Surface *image3[3];
  SDL_Surface *image23[3];
  SDL_Surface *Hit3;
  SDL_Surface *imageActuel3;
  SDL_Rect position3;
  SDL_Rect positionO3;
  int frame3;
  int direction3;
  int died3;
SDL_Surface *en3;
}Enemy;


//***********************************minimap1**********************************
typedef struct 
{
	int heur1; 
	int heur2;
	int minute1; 
	int minute2; 
	int seconde1; 
	int seconde2; 
	SDL_Surface *temp; 
	SDL_Rect position_temp; 
	TTF_Font *police;
	int tempactuel; 
	int tempprecedent; 
	char chaine[20]; 	
}tempss;


typedef struct 
{
     SDL_Rect posminijoueur;   	 
     SDL_Rect posminimap;   	  
     SDL_Surface *minimap;
     SDL_Surface *petit;	  
int nbmoved;
//***********************************minimap2**********************************

     SDL_Rect posminijoueur2;   	 
     SDL_Rect posminimap2;   	  
     SDL_Surface *minimap2;
     SDL_Surface *petit2;	  
int nbmoved2;
//***********************************minimap3**********************************

     SDL_Rect posminijoueur3;   	 
     SDL_Rect posminimap3;   	  
     SDL_Surface *minimap3;
     SDL_Surface *petit3;
int nbmoved3;	  
}minimap;

typedef struct hero
{
//***********************************background1*******************************
	int mouvment;
	SDL_Rect pos_hero[9];
	SDL_Surface *afficher_hero[9];
	SDL_Surface *afficher_herod[9];
	SDL_Rect pos_hero2;
	int farm;
int heromoved;
int vie;
int hit;
SDL_Surface *afficher_vie[4];
SDL_Rect pos_vie;
//***********************************background2*******************************
	int mouvment2;
	SDL_Rect pos_hero20[9];
	SDL_Surface *afficher_hero2[9];
	SDL_Surface *afficher_herod2[9];
	SDL_Rect pos_hero22;
	int farm2;
int heromoved2;
int vie2;
int hit2;
SDL_Surface *afficher_vie2[4];
SDL_Rect pos_vie2;

//***********************************background3*******************************
	int mouvment3;
	SDL_Rect pos_hero3[9];
	SDL_Surface *afficher_hero3[9];
	SDL_Surface *afficher_herod3[9];
	SDL_Rect pos_hero23;
	int farm3;	
int heromoved3;
int vie3;
int hit3;
SDL_Surface *afficher_vie3[4];
SDL_Rect pos_vie3;
}hero;


typedef struct background{
//***********************************background1*******************************
	SDL_Surface *afficher_background;
	SDL_Surface *aff;
	SDL_Rect pos_background;
	SDL_Rect pos_background2;
	SDL_Surface *calque_background;
	SDL_Surface *porte[14];
	SDL_Surface *owl[14];
	SDL_Rect port;
	SDL_Rect owll;
//***********************************background2*******************************
	SDL_Surface *afficher_background2;
	SDL_Surface *aff2;
	SDL_Rect pos_background20;
	SDL_Rect pos_background22;
	SDL_Surface *calque_background2;
	SDL_Surface *porte2[14];
	SDL_Surface *owl2[14];
	SDL_Rect port2;
	SDL_Rect owll2;
//***********************************background3*******************************
	SDL_Surface *afficher_background3;
	SDL_Surface *aff3;
	SDL_Rect pos_background3;
	SDL_Rect pos_background23;
	SDL_Surface *calque_background3;
	SDL_Surface *porte3[14];
	SDL_Surface *owl3[14];
	SDL_Rect port3;
	SDL_Rect owll3;
}background;
//**********************************ennemie***********************
Enemy InitEnemy(Enemy Ennemie,int x, int y);
	void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen);
	Enemy AnimateEnemy(Enemy Ennemie,int stat);
	Enemy MoveEnemy(Enemy Ennemie,SDL_Rect personnage,int *stat,int mouvment);
	int collision_Parfaite(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);
	void affichiervie(hero evan, SDL_Surface *ecran);
	int gestionvie(hero *evan,SDL_Surface *ecran);
	//void scrolling4 (hero *evan,background *bckg,int co );

//***********************ennemie2***********************
void affichiervie2(hero evan2, SDL_Surface *ecran);
int gestionvie2(hero *evan2, SDL_Surface *ecran);
Enemy InitEnemy2(Enemy Ennemie2,int x, int y);
void  AfficherEnemy2(Enemy Ennemie2,SDL_Surface *screen);
Enemy AnimateEnemy2(Enemy Ennemie2,int stat2);
Enemy MoveEnemy2(Enemy Ennemie2,SDL_Rect personnage2,int *stat2,int mouvment2);


//*************************************ennemie3***********************
void affichiervie3(hero evan3, SDL_Surface *ecran);
int gestionvie3(hero *evan3, SDL_Surface *ecran);
Enemy InitEnemy3(Enemy Ennemie3,int x, int y);
void  AfficherEnemy3(Enemy Ennemie3,SDL_Surface *screen);
Enemy AnimateEnemy3(Enemy Ennemie3,int stat3);
Enemy MoveEnemy3(Enemy Ennemie3,SDL_Rect personnage3,int *stat3,int mouvment3);
//***********************************background1******************************* 
	void initBack(background *b);
 	void afficherBack(background b,SDL_Surface *ecran);
	void initialiser_evan(hero *evan);
	void afficher_evan(hero evan,SDL_Surface *ecran);
	void animerBackground (background *b,SDL_Surface *ecran);
	void scrolling (hero *evan,background *b, int co);
	int mouvment(hero evan,SDL_Event *event);
	int collisionPP(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);
	SDL_Color GetPixel(SDL_Surface *surface,int x,int y);
int animation_perso(hero evan);
//***********************************background2*******************************

void initBack2(background *b2);
 	void afficherBack2(background b2,SDL_Surface *ecran);
	void initialiser_evan2(hero *evan2);
	void afficher_evan2(hero evan2,SDL_Surface *ecran);
	void animerBackground2(background *b2,SDL_Surface *ecran);
	void scrolling2(hero *evan2,background *b2, int co2);
	int mouvment2(hero evan2,SDL_Event *event2);
	int collisionPP2(SDL_Surface *calque,SDL_Surface *perso2,SDL_Rect posperso2,SDL_Rect posmap2);
	SDL_Color GetPixel2(SDL_Surface *surface,int x,int y);

int animation_perso2(hero evan2);
//***********************************background3*******************************

void initBack3(background *b3);
 	void afficherBack3(background b3,SDL_Surface *ecran);
	void initialiser_evan3(hero *evan3);
	void afficher_evan3(hero evan3,SDL_Surface *ecran);
	void animerBackground3 (background *b3,SDL_Surface *ecran);
	void scrolling3 (hero *evan3,background *b3, int co3);
	int mouvment3(hero evan3,SDL_Event *event3);
	int collisionPP3(SDL_Surface *calque,SDL_Surface *perso3,SDL_Rect posperso3,SDL_Rect posmap3);
	SDL_Color GetPixel3(SDL_Surface *surface,int x,int y);
int animation_perso3(hero evan3);

//*********************************minimap1*************************************
void initminimap (minimap *m);
//void majminimap (minimap *m ,hero *evan,background *b,int co );
void afficherminimap( minimap m,SDL_Surface *ecran);
void Liberer(minimap *m);
tempss initialiser_temp (tempss temp); 
void meilleur(char nomfich[],int * scoree,char nomjoueur[]);
void sauvegarder (int scoree , char nomjoueur[] ,char nomfich[],hero *evan,tempss temp);
void affichermeilleur (SDL_Surface *ecran,int scoree,char nomjoueur[]);
void enter_name(char nomfich[], SDL_Surface *ecran , char nomh[] );
void majminimap(minimap *m,SDL_Surface *ecran,int mouvment,int co,hero *evan);
//*********************************minimap2*************************************
void initminimap2 (minimap *m2);
void majminimap2(minimap *m2,SDL_Surface *ecran,int mouvment2,int co2,hero *evan2);
void afficherminimap2( minimap m2,SDL_Surface *ecran);
void Liberer2(minimap *m2);
void sauvegarder2 (int scoree2 , char nomjoueur[] ,char nomfich[],hero *evan2,tempss temp);
//*********************************minimap3*************************************
void initminimap3 (minimap *m3);
void majminimap3(minimap *m3,SDL_Surface *ecran,int mouvment3,int co3,hero *evan3);
void afficherminimap3( minimap m3,SDL_Surface *ecran);
void Liberer3(minimap *m3);
void sauvegarder3 (int scoree3 , char nomjoueur[] ,char nomfich[],hero *evan3,tempss temp);
//************************enigme************************
typedef struct 
{
	SDL_Surface *background[2];
	SDL_Surface *boutons[5];
	SDL_Surface *reponses[5];
	SDL_Surface *question;
	SDL_Surface *win;
	SDL_Surface *lost;
	
	SDL_Rect posRepones[5];
	SDL_Rect posQuestion;
	int choix_question;
	int image_courrante;
	int positionVraiReponse;
          
      
}Enigme;
typedef struct save
{
	SDL_Rect posperso; 
	SDL_Rect posennemi;
	SDL_Rect poscam; 
	int vies; 
	int temps; 
	int score; 
	FILE *fichier;
SDL_Rect pos_hero2;
}save; 




void Init_Enigme(Enigme *e , char *f1 , char *f2 ,char *f3);
int Play_Enigme(Enigme *e,SDL_Surface *ecran,int *Game);
void Display_Enigme(Enigme *e,SDL_Surface *ecran);
int Verify_Enigme(Enigme *e,int *Game,SDL_Surface *ecran);
void Free_Enigme(Enigme *e);
void animerEnigme (SDL_Surface *porte[14],SDL_Rect *port,SDL_Surface *ecran);
void animerEnigmee (SDL_Surface *porte[14],SDL_Rect *port,SDL_Surface *ecran);
void init_save (save *s);
void update_save (save *s, SDL_Rect posperso,SDL_Rect ennemi,SDL_Rect cam, int v , int tps, int sc);
void enregistrer (save s);
void chargement (save *s);
//***********************enigme2************************
void Init_Enigmee(Enigme *ee , char *f1 , char *f2 ,char *f3);
int Play_Enigmee(Enigme *ee,SDL_Surface *ecran,int *Game);
void Display_Enigmee(Enigme *ee,SDL_Surface *ecran);
int Verify_Enigmee(Enigme *ee,int *Game,SDL_Surface *ecran);
void Free_Enigmee(Enigme *ee);
//******************enigme3************************************
void Init_Enigmeee(Enigme *eee , char *f1 , char *f2 ,char *f3);
int Play_Enigmeee(Enigme *eee,SDL_Surface *ecran,int *Game);
void Display_Enigmeee(Enigme *eee,SDL_Surface *ecran);
int Verify_Enigmeee(Enigme *eee,int *Game,SDL_Surface *ecran);
void Free_Enigmeee(Enigme *eee);
//************************menu***********************************
typedef struct
{
    SDL_Rect position;
    TTF_Font *font;
    SDL_Surface *surfaceTexte;
    SDL_Color textColor;
    char texte [50];
} Text;
typedef struct
{
    SDL_Surface *img[39];
    SDL_Rect imgp;
    SDL_Surface *screen;
    SDL_Surface *background;
    SDL_Surface *play ; 
    SDL_Surface *credit ;
    SDL_Surface *settings ;
    SDL_Surface *quitter ;
    SDL_Surface *sound ;
    SDL_Surface *in_credit;
    SDL_Surface *in_play;
    SDL_Surface *in_settings;
    SDL_Surface *in_sound;
    SDL_Surface *fullscreen;
    SDL_Surface *normalscreen;
    SDL_Surface *back_settings;
    SDL_Surface *back_credit;
    SDL_Surface *back_play;
    SDL_Surface *back_load;
    SDL_Surface *newgame_play;
    SDL_Surface *loadgame_play;
    SDL_Surface *load;
    SDL_Surface *load_play;
    SDL_Surface *in_sound25;
    SDL_Surface *in_sound50;
    SDL_Surface *in_sound75;
    SDL_Surface *in_sound100;
    SDL_Surface *wexit;
    SDL_Surface *nwexit;
    SDL_Surface *exxit;
    SDL_Surface *img1;
    SDL_Surface *img2;
    SDL_Surface *img3;
    SDL_Surface *img4;
    SDL_Surface *img5;
    SDL_Surface *img6;
    SDL_Surface *img7;
    SDL_Surface *img8;
    SDL_Surface *img9;
    SDL_Surface *img10;
    SDL_Surface *img11;
    SDL_Surface *img12;
    SDL_Surface *img13;
    SDL_Surface *img14;
    SDL_Surface *img15;
    SDL_Surface *img16;
    SDL_Surface *img17;
    SDL_Surface *best_play;
    SDL_Surface *wessetbest;
    SDL_Surface *backbest;
    SDL_Surface *singeleplayer ;
    SDL_Surface *multiplay ;
    SDL_Surface *backkk_ilbara ;
    SDL_Surface *ilbarra ;
    SDL_Rect position;
    SDL_Rect posback;
    SDL_Rect posba;
    SDL_Rect pos_play; 
    SDL_Rect pos_credit;
    SDL_Rect pos_settings;
    SDL_Rect pos_quitter;
    SDL_Rect pos_sound;
    SDL_Rect imgggg;
    SDL_Rect pos_insound;
    SDL_Rect pos_fullscreen;
    SDL_Rect pos_normalscreen;
    SDL_Rect pos_back_settings;
    SDL_Rect pos_back_credit;
    SDL_Rect pos_back_load;
    SDL_Rect pos_load_play;
    SDL_Rect pos_newgame_play;
    SDL_Rect pos_loadgame_play;
    SDL_Rect pos_back_play;
    SDL_Rect pos_yes;
    SDL_Rect pos_no;
    SDL_Rect pos_moins;
    SDL_Rect pos_plus ;
    SDL_Rect pos_loadgame_best ;
    SDL_Rect pos_backbest;
    SDL_Rect pos_backmulti;
    SDL_Rect pos_multi;
    SDL_Rect pos_single;
} bg;


void initText(Text *A);
void freeText(Text A);
void displayText(Text t,SDL_Surface *screen);
void afficherannimation(bg *b,SDL_Surface *screen);
SDL_Surface* switchFullScreen();
void inittBack(bg *b);
void main1();
void main2();
void main3();


#endif
