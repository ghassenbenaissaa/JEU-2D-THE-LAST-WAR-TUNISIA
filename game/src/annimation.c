#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header.h"
void afficherannimation(bg *b,SDL_Surface *screen)
{
    //////////////////////////animation logo/////////////////////////

     char ch[39];
    int j;
//////////animation intro//////////////

   for(j=1; j<39; j++)
    {
        SDL_BlitSurface(b->img[j], NULL,screen,&b->imgp);
        SDL_Flip(screen);
        SDL_Delay(16);
    }
 SDL_Delay(500);
SDL_BlitSurface(b->background, NULL, screen, &b->posback);
}
