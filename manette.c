#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "header.h"


int arduinoWriteData(int x);
int arduinoReadData(int *x);
int checkCollidsionBoundingBox(SDL_Rect a, SDL_Rect b);


int manette( int argc, char *argv[ ] )
{
background b;
hero evan ;
int co;
int directionSDL=0; 
int directionArduino=0; 
int game=1;
char received;
int collisionRightSide = 0;
int collisionLeftSide= 0;


SDL_Event event;
SDL_Surface *screen=NULL,*perso=NULL,*barriere=NULL;
SDL_Rect positionperso;



system("stty -F /dev/ttyACM0 9600 -parenb cs8 -cstopb");

    SDL_Init(SDL_INIT_VIDEO);

    while (game)
    {
  
      while(SDL_PollEvent(&event)){
            switch (event.type)
            {
        
            case SDL_QUIT:
                game = 0;
                break;
            case SDL_KEYDOWN:
            {

                if (event.key.keysym.sym == SDLK_RIGHT)
                  directionSDL = 1;

                if (event.key.keysym.sym == SDLK_LEFT)
                  directionSDL = 2;

            }
            break;
            case SDL_KEYUP:
              directionSDL=0;
            break;

            }
          }
   
            if(co!=1)
                collisionRightSide=0;
            else
                collisionRightSide=1;
            if((co!=2)&&(co!=1))
              collisionLeftSide=0;
            else
              collisionLeftSide=1;


            if(collisionRightSide == 1){
              printf("\n COLLISION RIGHT SENDING 1 TO SERIAL");
              //........................

            } else if(collisionLeftSide == 1){
              printf("\n COLLISION UP SENDING 2 TO SERIAL");
            //..........................

            } else {
            printf("\n NO COLLISION SENDING 0 TO SERIAL");
            //..........................
            }

            if((directionSDL == 1 ) && (((evan.pos_hero2.x<800)||((b.pos_background2.x>=5200))&&(evan.pos_hero2.x<1700)))&& !collisionRightSide){
                 evan.pos_hero2.x=evan.pos_hero2.x+15;

            }
            if ((directionSDL == 2 ) &&((evan.pos_hero2.y<600)&&(evan.pos_hero2.y!=400)&&(b.pos_background2.y<20)) && !collisionLeftSide){
              evan.pos_hero2.y=evan.pos_hero2.y+17;
            }

            SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255,255, 255));
   
            SDL_Flip( screen );
           
    }


    SDL_FreeSurface(perso);
    //SDL_FreeSurface(barriere);
    SDL_Quit();
    return 0;
}


int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}

int arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyACM0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}
