#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"headerpartage.h"
 int mouvmentp(hero evan,SDL_Event *event){

 	int mouvment;

 	SDL_PollEvent(event);
 	switch (event->type)
        {
   
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym)
            {
            case SDLK_RIGHT:
		mouvment=1;
                break;
            case SDLK_LEFT:
            	mouvment=2;
                break;
            case SDLK_UP: 
                mouvment=3;  
                 break;
            case SDLK_DOWN:
		mouvment=4;
                 break;
            }
            break;
             default: 	mouvment=9;
 }
 return mouvment;
}



//***********************************background2*******************************

 int mouvment2p(hero evan2,SDL_Event *event2){

 	int mouvment2;

 	SDL_PollEvent(event2);
 	switch (event2->type)
        {
   
        case SDL_KEYDOWN:
            switch (event2->key.keysym.sym)
            {
            case SDLK_d:
		mouvment2=1;
                break;
            case SDLK_q:
            	mouvment2=2;
                break;
            case SDLK_z: 
                mouvment2=3;  
                 break;
            case SDLK_s:
		mouvment2=4;
                 break;
            }
            break;
             default: 	mouvment2=9;
 }
 return mouvment2;
}


