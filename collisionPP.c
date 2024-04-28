#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header.h"
SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
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
int collisionPP(SDL_Surface *calque,SDL_Surface *perso,SDL_Rect posperso,SDL_Rect posmap)
{
  SDL_Color col2,col22,col;
        col=GetPixel(calque,posperso.x+20+posmap.x,posperso.y+220);
	col2=GetPixel(calque,posperso.x+10+posmap.x,posperso.y+200);
	col22=GetPixel(calque,posperso.x+80+posmap.x,posperso.y+180);

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
SDL_Color GetPixel2(SDL_Surface *surface,int x,int y)
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
int collisionPP2(SDL_Surface *calque,SDL_Surface *perso2,SDL_Rect posperso2,SDL_Rect posmap2)
{
  SDL_Color col2,col22,col;
col=GetPixel3(calque,posperso2.x+100+posmap2.x,posperso2.y+220);
	col2=GetPixel2(calque,posperso2.x+10+posmap2.x,posperso2.y+200);
	col22=GetPixel2(calque,posperso2.x+80+posmap2.x,posperso2.y+180);
if ((col.r==0)&&(col.b==0)&&(col.g==255))
  return 3;
	else if ((col22.r==0)&&(col22.b==0)&&(col22.g==0))
  	 return 1;
	else if ((col2.r==0)&&(col2.b==0)&&(col2.g==0))
 	 return 2;
	else
	 return 0;
}


//***********************************background3*******************************

SDL_Color GetPixel3(SDL_Surface *surface,int x,int y)
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
int collisionPP3(SDL_Surface *calque,SDL_Surface *perso3,SDL_Rect posperso3,SDL_Rect posmap3)
{
  SDL_Color col2,col22,col,col1;
col=GetPixel3(calque,posperso3.x+100+posmap3.x,posperso3.y+220);
//col1=GetPixel(calque,posperso3.x+100+posmap3.x,posperso3.y+220);
	col2=GetPixel3(calque,posperso3.x+10+posmap3.x,posperso3.y+200);
	col22=GetPixel3(calque,posperso3.x+120+posmap3.x,posperso3.y+180);
if ((col.r==0)&&(col.b==0)&&(col.g==255))
  return 3;
	else if ((col22.r==0)&&(col22.b==0)&&(col22.g==0))
  	 return 1;
	else if ((col2.r==0)&&(col2.b==0)&&(col2.g==0))
 	 return 2;
	else
	 return 0;

}


