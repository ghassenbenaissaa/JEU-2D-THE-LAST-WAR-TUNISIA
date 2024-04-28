#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define largeur 1920
#define hauteur 1080


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
//int vie;
//int hit;
//SDL_Surface *afficher_vie[4];
//SDL_Rect pos_vie;
//***********************************background2*******************************
	int mouvment2;
	SDL_Rect pos_hero20[9];
	SDL_Surface *afficher_hero2[9];
	SDL_Surface *afficher_herod2[9];
	SDL_Rect pos_hero22;
	int farm2;
int heromoved2;
//int vie2;
//int hit2;
//SDL_Surface *afficher_vie2[4];
//SDL_Rect pos_vie2;
}hero;


typedef struct background{
//***********************************background1*******************************
	SDL_Surface *afficher_background;
	SDL_Surface *aff;
	SDL_Rect pos_background;
	SDL_Rect pos_background2;
	SDL_Surface *calque_background;

//***********************************background2*******************************
	SDL_Surface *afficher_background2;
	SDL_Surface *aff2;
	SDL_Rect pos_background20;
	SDL_Rect pos_background22;
	SDL_Surface *calque_background2;
}background;
//*********************background1****************************

	void initialiser_background1p(background *b);
	void afficherBackp(background b,SDL_Surface *ecran);
	void initialiser_evanp(hero *evan);
	void afficher_evanp(hero evan,SDL_Surface *ecran);
	void animerBackgroundp(background *b,SDL_Surface *ecran);
	void scrollingp (hero *evan,background *b, int co);
	int mouvmentp(hero evan,SDL_Event *event);
	int collisionPPp(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap);
	SDL_Color GetPixelp(SDL_Surface *surface,int x,int y);
	int animation_persop(hero evan);

//***********************************background2*******************************

	void initialiser_background2p(background *b);
	void initialiser_evan2p(hero *evan2);
	void afficherBack2p(background b2,SDL_Surface *ecran);
	void afficher_evan2p(hero evan2,SDL_Surface *ecran);
	void animerBackground2p(background *b2,SDL_Surface *ecran);
	void scrolling2p(hero *evan2,background *b2, int co2);
	int mouvment2p(hero evan2,SDL_Event *event2);
	int collisionPP2p(SDL_Surface *calque,SDL_Surface *perso2,SDL_Rect posperso2,SDL_Rect posmap2);
	SDL_Color GetPixel2p(SDL_Surface *surface,int x,int y);
	int animation_perso2p(hero evan2);





