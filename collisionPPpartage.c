#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"headerpartage.h"
SDL_Color GetPixelp(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;
	char* pPosition = ( char* ) surface->pixels ;
	pPosition += ( surface->pitch * y ) ;
	pPosition += ( surface->format->BytesPerPixel * x ) ;
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
} 
int collisionPPp(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col2,col22,col;
        col=GetPixelp(calque,posperso.x+20+posmap.x,posperso.y+220);
	col2=GetPixelp(calque,posperso.x+10+posmap.x,posperso.y+200);
	col22=GetPixelp(calque,posperso.x+80+posmap.x,posperso.y+180);

        if ((col.r==0)&&(col.b==0)&&(col.g==255))
         return 3;
	else if ((col22.r==0)&&(col22.b==0)&&(col22.g==0))
  	 return 1;
	else if ((col2.r==0)&&(col2.b==0)&&(col2.g==0))
 	 return 2;
	else
	 return 0;
}


//***********************************background2*******************************
SDL_Color GetPixel2p(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;
	char* pPosition = ( char* ) surface->pixels ;
	pPosition += ( surface->pitch * y ) ;
	pPosition += ( surface->format->BytesPerPixel * x ) ;
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}
int collisionPP2p(SDL_Surface *calque,SDL_Surface *perso2,SDL_Rect posperso2,SDL_Rect posmap2)
{
  SDL_Color col0,col220,col20;
	col0=GetPixel2p(calque,posperso2.x+100+posmap2.x,posperso2.y+220);
	col20=GetPixel2p(calque,posperso2.x+10+posmap2.x,posperso2.y+200);
	col220=GetPixel2p(calque,posperso2.x+80+posmap2.x,posperso2.y+180);
if ((col0.r==0)&&(col0.b==0)&&(col0.g==255))
  return 3;
	else if ((col220.r==0)&&(col220.b==0)&&(col220.g==0))
  	 return 1;
	else if ((col20.r==0)&&(col20.b==0)&&(col20.g==0))
 	 return 2;
	else
	 return 0;
}




