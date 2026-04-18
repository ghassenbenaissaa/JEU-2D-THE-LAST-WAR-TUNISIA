#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header.h"
void initText(Text *A)
{

    A->position.x=1566;
    A->position.y=1028;
//couleur jaune
    A->textColor.r=255;
    A->textColor.g=255;
    A->textColor.b=255;

    A->font = TTF_OpenFont( "../Background/last_night.ttf", 32 );
}

void freeText(Text A)
{
    SDL_FreeSurface(A.surfaceTexte);
}


void displayText(Text t,SDL_Surface *screen)
{
    t.surfaceTexte= TTF_RenderText_Solid(t.font, "the_most_powerfull_team", t.textColor );
    SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
}
