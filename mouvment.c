#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header.h"
 int mouvment(hero evan,SDL_Event *event){

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

 int mouvment2(hero evan2,SDL_Event *event2){

 	int mouvment2;

 	SDL_PollEvent(event2);
 	switch (event2->type)
        {
   
        case SDL_KEYDOWN:
            switch (event2->key.keysym.sym)
            {
            case SDLK_RIGHT:
		mouvment2=1;
                break;
            case SDLK_LEFT:
            	mouvment2=2;
                break;
            case SDLK_UP: 
                mouvment2=3;  
                 break;
            case SDLK_DOWN:
		mouvment2=4;
                 break;
            }
            break;
             default: 	mouvment2=9;
 }
 return mouvment2;
}


//***********************************background3*******************************

int mouvment3(hero evan3,SDL_Event *event3){

 	int mouvment3;

 	SDL_PollEvent(event3);
 	switch (event3->type)
        {
   
        case SDL_KEYDOWN:
            switch (event3->key.keysym.sym)
            {
            case SDLK_RIGHT:
		mouvment3=1;
                break;
            case SDLK_LEFT:
            	mouvment3=2;
                break;
            case SDLK_UP: 
                mouvment3=3;  
                 break;
            case SDLK_DOWN:
		mouvment3=4;
                 break;
            }
            break;
             default: 	mouvment3=9;
 }
 return mouvment3;
}
