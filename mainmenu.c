#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_mixer.h"
#include"header.h"

#define w 1920// pos background
#define h 1080    //

#define n_w 385  //pos load_newgame image 
#define n_h 55    //

#define s_w 295   // pos settings 
#define s_h 55     //

#define e_w 252  //pos exit
#define e_h 55     //

#define sound_w 55 //pos icon sound en haut a gauche
#define sound_h 55  //

#define i_s_w 500 //insound surface width
#define i_s_h 80  //insound surface high

#define yn_w 384    //yes or no width 
#define yn_h 151    //yes or no high

#define mp_w 40  //+ et - width
#define mp_h 40  //+et - high

bg b;
SDL_Surface *screen = NULL;
SDL_Event event, event2;
Mix_Music  *music,*music2,*music3,*music0,*music25,*music50,*music75,*music100;

 int argc;
char argv[8];

int main()
{
    TTF_Init();
    int running = 1,running2=1,running3=1,running4=1,running5=1,running6=1,running7=1,running8=1,running9=1;
    int i = 0, firsttime = 0,in,s=0,fleche=1;
    Text t;
    atexit(SDL_Quit);
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); 
    inittBack(&b);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }
    music2 = Mix_LoadMUS("game.wav"); //music de fond
    music3 = Mix_LoadMUS("histoire.mp3");
    

    Mix_Chunk *music;
    music = Mix_LoadWAV("son1.wav"); //effet sonore
    music0 = Mix_LoadMUS("../ka/music/100.wav");
    music25 = Mix_LoadMUS("../ka/music/75.wav");
    music50 = Mix_LoadMUS("../ka/music/50.wav");
    music75 = Mix_LoadMUS("../ka/music/25.wav");
    music100 = Mix_LoadMUS("../ka/music/0.wav");
    afficherannimation(&b,screen);
    
    initText(&t);
    FILE *f = fopen("test.txt", "a"); //fichier pour tester le code
    fprintf(f, "test");
    
    
    displayText(t, screen);
    SDL_EnableKeyRepeat(100, 100); //activer le clic continure du fleche
char nomh[50];
Mix_PlayMusic(music2,-1) ;
    while (running)
    {
    
        SDL_WaitEvent(&event);
        
        switch (event.type)
        {
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT && i==4 ) // clic gauche souris avec la position du curseur en exit
            {
              running=0;
              running2=0;
              running3=0;
              running4=0;
              running5=0;
              
                while(running3) // debuter un boucle infinie dans un boucle infinie
                {
                    SDL_PollEvent(&event);
                    switch (event.type)
                    {
                    case SDL_QUIT: // quitter le programme
                     
 				running=0 ;
                        break ;
                    case SDL_KEYDOWN: // echap por quitter
                        switch (event.key.keysym.sym)
                        {
                        case SDLK_ESCAPE:
                            running3=0 ;
                            running=0 ;
                            break ;
                        }
                    }
                }

            }
            else if (event.motion.x== SDL_BUTTON_LEFT && in==1 ) // clic gauche de souris et le curseur  se trouve dans l icon de spon
            {
                if(s==0)  // si son activé le desactive
                {

                    SDL_BlitSurface(b.background, NULL, screen, &b.posback);
                    SDL_FreeSurface(b.sound);
                    SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                     
                    SDL_Flip(screen);
                    s=1 ;
                    in=0 ;
                }
                else if(s==1) //si son desactivé  l'active
                {

                    SDL_BlitSurface(b.background, NULL, screen, &b.posback);
                    SDL_FreeSurface(b.sound);
                    
                    Mix_PauseMusic();
                    SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                    SDL_Flip(screen);
                    s=0 ;
                    in=0 ;
                }

            }
            else if (event.button.button == SDL_BUTTON_LEFT && i==3 ) //clic gauche souris avec la position du curseur en settings
            {

                SDL_BlitSurface(b.in_settings, NULL, screen, &b.posback);
                SDL_Flip(screen);
                i=0;
                running2=1 ;
                while(running2) //entrer dans le sous menu de settings et debuter le boucle infinie
                {

                    SDL_WaitEvent(&event);
                    switch (event.type)
                    {
                    case SDL_MOUSEMOTION:

                        if (event.motion.x > b.pos_insound.x && event.motion.x < (i_s_w + b.pos_insound.x) && event.motion.y > b.pos_insound.y && event.motion.y < (i_s_h + b.pos_insound.y))
                        {
                            if(i==1)
                            {
                                break ;
                            }
                            else
                            {
                                i=1 ;
                                if(fleche==1)
                                {
                                    SDL_BlitSurface(b.in_sound, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music0,-1);
                                }
                                else if (fleche==2)
                                {
                                    SDL_BlitSurface(b.in_sound25, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music25,-1);
                                }
                                else if (fleche==3)
                                {
                                    SDL_BlitSurface(b.in_sound50, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music50,-1);
                                }
				else if(fleche==4)
				{
				SDL_BlitSurface(b.in_sound75, NULL, screen, &b.posback);
                                Mix_PauseMusic();
                                    Mix_PlayMusic(music75,-1);
				}
				else if(fleche==5)
				{
				SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
                                Mix_PauseMusic();
                                    Mix_PlayMusic(music100,-1);
				}
                                if (fleche>5)
                                {
                                    SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music100,-1);
                                }
                                if (fleche<1)
                                {
                                    SDL_BlitSurface(b.in_sound, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                }

                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);
                            }
                        }
                        if (event.motion.x > b.pos_fullscreen.x && event.motion.x < (i_s_w + b.pos_fullscreen.x) && event.motion.y > b.pos_fullscreen.y && event.motion.y < (i_s_h + b.pos_fullscreen.y))
                        {
                            if(i==2)
                            {
                                break ;
                            }
                            else
                            {
                                i=2;
                                SDL_BlitSurface(b.fullscreen, NULL, screen, &b.posback);
                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);
                            }
                        }
                        if (event.motion.x > b.pos_normalscreen.x && event.motion.x < (i_s_w + b.pos_normalscreen.x) && event.motion.y > b.pos_normalscreen.y && event.motion.y < (i_s_h + b.pos_normalscreen.y))
                        {
                            if(i==4)
                            {
                                break ;
                            }
                            else
                            {
                                i=4 ;
                                SDL_BlitSurface(b.normalscreen, NULL, screen, &b.posback);
                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);
                            }
                        }
                        if (event.motion.x > b.pos_back_settings.x && event.motion.x < (i_s_w + b.pos_back_settings.x) && event.motion.y > b.pos_back_settings.y && event.motion.y < (i_s_h + b.pos_back_settings.y))
                        {
                            if(i==3)
                            {
                                break ;
                            }
                            else
                            {
                                i=3 ;
                                SDL_BlitSurface(b.back_settings, NULL, screen, &b.posback);
                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);
                            }
                        }
                        break ;
                    case SDL_MOUSEBUTTONDOWN:
                        if (event.button.button == SDL_BUTTON_LEFT && i==3 )
                        {
                            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                            SDL_BlitSurface(b.background, NULL, screen, &b.posback);
                            displayText(t, screen);
                            
                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                            SDL_Flip(screen);
                            running2=0 ;
                        }
                        if (event.button.button == SDL_BUTTON_LEFT && i==2 )
                        {
                            screen=switchFullScreen();
                            SDL_BlitSurface(b.in_settings, NULL, screen, &b.posback);
                            SDL_Flip(screen); 
                        }
                        if (event.button.button == SDL_BUTTON_LEFT && i==4 )
                        {
                            screen=switchFullScreen();
                            SDL_BlitSurface(b.in_settings, NULL, screen, &b.posback);
                            SDL_Flip(screen);  
                        }

                        break ;

                    case SDL_QUIT:
                        running2= 0;
                        running=0 ;
                        break;
                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {
                        case SDLK_ESCAPE:
                            running3=0 ;
                            running=0 ;
                            break ;
                        case SDLK_LEFT :

                            fleche ++ ;
                            if(fleche>5)
                                fleche=5 ;
			if (fleche<1)
			fleche=1;

                            if(fleche<=5)
                            {
                                switch (fleche)
                                {
                                case 1 :
                                    SDL_BlitSurface(b.in_sound, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music0,-1);
                                    SDL_Flip(screen);
                                    break;

                                case 2:
                                    SDL_BlitSurface(b.in_sound25, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music25,-1);
                                    SDL_Flip(screen);
                                    break;

                                case 3 :
                                    SDL_BlitSurface(b.in_sound50, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music50,-1);
                                    SDL_Flip(screen);
                                    break ;
 				case 4:
                                        SDL_BlitSurface(b.in_sound75, NULL, screen, &b.posback);
		                        Mix_PauseMusic();
                                    Mix_PlayMusic(music75,-1);
                                        SDL_Flip(screen);
                                        break ;
				case 5:
                                        SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
		                         Mix_PauseMusic();
                                    Mix_PlayMusic(music100,-1);
                                        SDL_Flip(screen);
                                        break ;

                                }

                            }
                            break ;
                        case SDLK_RIGHT:

                           
                                fleche-- ;
                                if(fleche>5)
                                    fleche=5 ;
				if (fleche<1)
				fleche=1;

                                if(fleche<=5)
                                {
                                    switch (fleche)
                                    {
                                    case 1 :
                                        SDL_BlitSurface(b.in_sound, NULL, screen, &b.posback);
                                        Mix_PauseMusic();
                                        Mix_PlayMusic(music0,-1);
                                        SDL_Flip(screen);
                                        break;

                                    case 2:
                                        SDL_BlitSurface(b.in_sound25, NULL, screen, &b.posback);
                                           Mix_PauseMusic();
                                    Mix_PlayMusic(music25,-1);
                                        SDL_Flip(screen);
                                        break;
                                    case 3:
                                        SDL_BlitSurface(b.in_sound50, NULL, screen, &b.posback);
                                           Mix_PauseMusic();
                                    Mix_PlayMusic(music50,-1);
                                        SDL_Flip(screen);
                                        break ;
 					case 4:
                                        SDL_BlitSurface(b.in_sound75, NULL, screen, &b.posback);
                                          Mix_PauseMusic();
                                    Mix_PlayMusic(music75,-1);
                                        SDL_Flip(screen);
                                        break ;
					case 5:
                                        SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
                                         Mix_PauseMusic();
                                    Mix_PlayMusic(music100,-1);
                                        SDL_Flip(screen);
                                        break ;

                                    }

                                }
                           

                            break ;
                        case SDLK_SPACE:
                            if(i==4)
                            {

                                SDL_BlitSurface(b.background, NULL, screen, &b.posback);
                                SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                SDL_Flip(screen);
                                running2=0 ;

                            }
                            break ;
                        
                                    }
                                }
                            }
                        }
                    
                
                if (event.button.button == SDL_BUTTON_LEFT && i==1 ) //clic gauche souris avec la position du curseur en play
                {
                    SDL_BlitSurface(b.in_play, NULL, screen, &b.posback);
                    SDL_Flip(screen);
                    i=0;
                    running4=1 ;
                    while(running4) //entrer dans le sous menu de play et debuter le boucle infinie
                    {
		        SDL_WaitEvent(&event);
                        switch (event.type)
                        {
                        case SDL_MOUSEMOTION:
                            if (event.motion.x > b.pos_back_play.x && event.motion.x < (i_s_w + b.pos_back_play.x) && event.motion.y > b.pos_back_play.y && event.motion.y < (i_s_h + b.pos_back_play.y))
                            {
                                if(i==1)
                                {
                                    break ;
                                }
                                else
                                {
                                    i=1 ;
                                    SDL_BlitSurface(b.back_play, NULL, screen, &b.posback);
                                    SDL_Flip(screen);
                                    Mix_PlayChannel(1, music,0);
                                }
                            }
                           if (event.motion.x > b.pos_newgame_play.x && event.motion.x < (i_s_w + b.pos_newgame_play.x) && event.motion.y > b.pos_newgame_play.y && event.motion.y < (i_s_h + b.pos_newgame_play.y)) 
				 {
                                if(i==2)
                                {
                                    break ;
                                }
                                else
                                {
                                    i=2 ;
                                    SDL_BlitSurface(b.newgame_play, NULL, screen, &b.posback);
                                    SDL_Flip(screen);
                                    Mix_PlayChannel(1, music,0);
                                }
                            }
                           if (event.motion.x > b.pos_loadgame_play.x && event.motion.x < (i_s_w + b.pos_loadgame_play.x) && event.motion.y > b.pos_loadgame_play.y && event.motion.y < (i_s_h + b.pos_loadgame_play.y)) 
				 {
                                if(i==3)
                                {
                                    break ;
                                }
                                else
                                {
                                    i=3 ;
                                    SDL_BlitSurface(b.loadgame_play, NULL, screen, &b.posback);
                                    SDL_Flip(screen);
                                    Mix_PlayChannel(1, music,0);
                                }
                            }
                             if (event.motion.x > b.pos_loadgame_best.x && event.motion.x < (i_s_w + b.pos_loadgame_best.x) && event.motion.y > b.pos_loadgame_best.y && event.motion.y < (i_s_h + b.pos_loadgame_best.y)) 
				 {
                                if(i==4)
                                {
                                    break ;
                                }
                                else
                                {
                                    i=4 ;
                                    SDL_BlitSurface(b.best_play, NULL, screen, &b.posback);
                                    SDL_Flip(screen);
                                    Mix_PlayChannel(1, music,0);
                                }
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.button == SDL_BUTTON_LEFT && i==1 )
                            {
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(b.background, NULL, screen, &b.posback);
                                displayText(t, screen);
                               
                                SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                SDL_Flip(screen);
                                running4=0 ;
                            }
			   if (event.button.button == SDL_BUTTON_LEFT && i==4 )
                            {
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(b.wessetbest, NULL, screen, &b.posba);
				SDL_Flip(screen);
				i=0;
                               running7=1;
                              while (running7)
                           {
                        SDL_WaitEvent(&event);
                        switch (event.type)
                        {
                        case SDL_MOUSEMOTION:
                        if (event.motion.x > b.pos_backbest.x && event.motion.x < (i_s_w + b.pos_backbest.x) && event.motion.y > b.pos_backbest.y && event.motion.y < (i_s_h + b.pos_backbest.y)) 
				 {
                                if(i==1)
                                {
                                    break ;
                                }
                                else
                                {
                                    i=1 ;
				     SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                    SDL_BlitSurface(b.backbest, NULL, screen, &b.posback);
                                    SDL_Flip(screen);
                                    Mix_PlayChannel(1, music,0);
                                }
                                 }
break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.button == SDL_BUTTON_LEFT && i==1 )
                            {
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(b.in_play, NULL, screen, &b.posback);
                                SDL_Flip(screen);
                                running7=0 ;
                            }
break;
}
}
                            }
                           if (event.button.button == SDL_BUTTON_LEFT && i==2 )
                            {
        		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                             SDL_BlitSurface(b.ilbarra, NULL, screen, &b.posback);
                             SDL_Flip(screen);
                             i=0;
                    	     running8=1 ;
                             while(running8)
                             {
		             SDL_WaitEvent(&event);
                             switch (event.type)
                             {
                        case SDL_MOUSEMOTION:
				if (event.motion.x > b.pos_single.x && event.motion.x < (i_s_w + b.pos_single.x) && event.motion.y > b.pos_single.y && event.motion.y < (i_s_h + b.pos_single.y)) 
				 {
                                if(i==1)
                                {
                                    break ;
                                }
                                else
                                {
                                    i=1 ;
				     SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                    SDL_BlitSurface(b.singeleplayer, NULL, screen, &b.posback);
                                    SDL_Flip(screen);
                                    Mix_PlayChannel(1, music,0);
                                }
                                 }
				if (event.motion.x > b.pos_multi.x && event.motion.x < (i_s_w + b.pos_multi.x) && event.motion.y > b.pos_multi.y && event.motion.y < (i_s_h + b.pos_multi.y)) 
				 {
                                if(i==2)
                                {
                                    break ;
                                }
                                else
                                {
                                    i=2 ;
				     SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                    SDL_BlitSurface(b.multiplay, NULL, screen, &b.posback);
                                    SDL_Flip(screen);
                                    Mix_PlayChannel(1, music,0);
                                }
                                 }
				if (event.motion.x > b.pos_backmulti.x && event.motion.x < (i_s_w + b.pos_backmulti.x) && event.motion.y > b.pos_backmulti.y && event.motion.y < (i_s_h + b.pos_backmulti.y)) 
				 {
                                if(i==3)
                                {
                                    break ;
                                }
                                else
                                {
                                    i=3 ;
				     SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                    SDL_BlitSurface(b.backkk_ilbara, NULL, screen, &b.posback);
                                    SDL_Flip(screen);
                                    Mix_PlayChannel(1, music,0);
                                }
                                 }
				break;
          			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT && i==1 )
                          {
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                Mix_PlayMusic(music3,-1) ;
				enter_name("sauvegarde.txt",screen ,nomh);
				SDL_Flip(screen);
				/*SDL_Delay(1000); 
                                SDL_BlitSurface(b.img1, NULL, screen, &b.posba);
                                SDL_Flip(screen);
                                SDL_Delay(17000);
                                SDL_BlitSurface(b.img2, NULL, screen, &b.posba);
				SDL_Flip(screen);
				SDL_Delay(11000);
				SDL_BlitSurface(b.img3, NULL, screen, &b.posba);
                                SDL_Flip(screen);
				SDL_Delay(6000);
				SDL_BlitSurface(b.img4, NULL, screen, &b.posba);
                                SDL_Flip(screen);
				SDL_Delay(21000);
				SDL_BlitSurface(b.img5, NULL, screen, &b.posba);
                                SDL_Flip(screen);
				SDL_Delay(16000);
				SDL_BlitSurface(b.img6, NULL, screen, &b.posba);
                                SDL_Flip(screen);
                                SDL_Delay(3000);*/
                                main1();
                                /*Mix_PlayMusic(music3,-1) ;
                                SDL_BlitSurface(b.img7, NULL, screen, &b.posba);
                                SDL_Flip(screen);
                                SDL_Delay(7000);
                                SDL_BlitSurface(b.img8, NULL, screen, &b.posba);
				SDL_Flip(screen);
				SDL_Delay(8000);
				SDL_BlitSurface(b.img9, NULL, screen, &b.posba);
                                SDL_Flip(screen);
                                SDL_Delay(7000);*/
                                main2();
                                /*Mix_PlayMusic(music3,-1) ;
                                SDL_BlitSurface(b.img10, NULL, screen, &b.posba);
                                SDL_Flip(screen);
                                SDL_Delay(3000);
                                SDL_BlitSurface(b.img11, NULL, screen, &b.posba);
				SDL_Flip(screen);
				SDL_Delay(6000);
				SDL_BlitSurface(b.img12, NULL, screen, &b.posba);
                                SDL_Flip(screen);
				SDL_Delay(10000);
				SDL_BlitSurface(b.img13, NULL, screen, &b.posba);
                                SDL_Flip(screen);
				SDL_Delay(22000);
				SDL_BlitSurface(b.img14, NULL, screen, &b.posba);
                                SDL_Flip(screen);
				SDL_Delay(8000);
				SDL_BlitSurface(b.img15, NULL, screen, &b.posba);
                                SDL_Flip(screen);
                                SDL_Delay(13000);
                                SDL_BlitSurface(b.img16, NULL, screen, &b.posba);
                                SDL_Flip(screen);
                                SDL_Delay(19000);
                                SDL_BlitSurface(b.img17, NULL, screen, &b.posba);
				SDL_Flip(screen);
                                SDL_Delay(3000);*/
				main3();	
                                running9=0 ;
                                running4=0 ;
 				}
				if (event.button.button == SDL_BUTTON_LEFT && i==2 )
                            {
                               
                            partage(argc,&argv);
                            }
                            if (event.button.button == SDL_BUTTON_LEFT && i==3 )
                            {
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(b.in_play, NULL, screen, &b.posback);
                                SDL_Flip(screen);
				i=0;
                                running8=0 ;
                            }
break;
}}                                
                            }
				if (event.button.button == SDL_BUTTON_LEFT && i==3 )
                            {
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(b.load, NULL, screen, &b.posba);
                                SDL_Flip(screen);
				i=0;
                                running6=1;
                                while (running6)
                                 {
                         SDL_WaitEvent(&event);
                        switch (event.type)
                        {
                        case SDL_MOUSEMOTION:
                            if (event.motion.x > b.pos_back_load.x && event.motion.x < (i_s_w + b.pos_back_load.x) && event.motion.y > b.pos_back_load.y && event.motion.y < (i_s_h + b.pos_back_load.y))
                            {
                                if(i==1)
                                {
                                    break ;
                                }
                                else
                                {
                                    i=1 ;
                                    SDL_BlitSurface(b.back_load, NULL, screen, &b.posback);
                                    SDL_Flip(screen);
                                    Mix_PlayChannel(1, music,0);
                                }
                            }
                           if (event.motion.x > b.pos_load_play.x && event.motion.x < (i_s_w + b.pos_load_play.x) && event.motion.y > b.pos_load_play.y && event.motion.y < (i_s_h + b.pos_load_play.y)) 
				 {
                                if(i==2)
                                {
                                    break ;
                                }
                                else
                                {
                                    i=2 ;
                                    SDL_BlitSurface(b.load_play, NULL, screen, &b.posback);
                                    SDL_Flip(screen);
                                    Mix_PlayChannel(1, music,0);
                                }
                            }
                            break;
                            case SDL_MOUSEBUTTONDOWN:
                            if (event.button.button == SDL_BUTTON_LEFT && i==1 )
                            {
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(b.in_play, NULL, screen, &b.posback);
                                SDL_Flip(screen);
                                running6=0 ;
                            }
                            break;
                            if (event.button.button == SDL_BUTTON_LEFT && i==2 )
                            {
                                /*......*/
                            }
                            break;
}
                                
                            }

                        
                       /* case SDL_QUIT:
                            running4= 0;
                            running6=0;
                            running=0 ;
                            break;*/
                      }  
                    
}
                }
}
                       
                else if (event.button.button == SDL_BUTTON_LEFT && i==2 ) //clic gauche souris avec la position du curseur en credits
                {

                    SDL_BlitSurface(b.in_credit, NULL, screen, &b.posback);
                    SDL_Flip(screen);
                    i=0;
                    running5=1 ;
                    while(running5) //entrer dans le sous menu de credits et debuter le boucle infinie
                    {
                        SDL_WaitEvent(&event);
                        switch (event.type)
                        {
                        case SDL_MOUSEMOTION:
                            if (event.motion.x > b.pos_back_credit.x && event.motion.x < (i_s_w + b.pos_back_credit.x) && event.motion.y > b.pos_back_credit.y && event.motion.y < (i_s_h + b.pos_back_credit.y))
                            {
                                if(i==1)
                                {
                                    break ;
                                }
                                else
                                {
                                    i=1 ;
                                    SDL_BlitSurface(b.back_credit, NULL, screen, &b.posback);


                                    SDL_Flip(screen);
                                    Mix_PlayChannel(1, music,0);
                                }
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.button == SDL_BUTTON_LEFT && i==1 )
                            {
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(b.background, NULL, screen, &b.posback);
                                displayText(t, screen);
                               
                                SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                SDL_Flip(screen);
                                running5=0 ;
                            }

                            break ;
                        case SDL_QUIT:
                            running5= 0;
                            running=0 ;
                            break;
                        }
                    

                }
            case SDL_MOUSEMOTION:

                if (event.motion.x > b.pos_sound.x && event.motion.x < (sound_w + b.pos_sound.x) && event.motion.y > b.pos_sound.y && event.motion.y < (sound_h + b.pos_sound.y))
                {
                    in=1 ;
                }

                if (event.motion.x > b.pos_play.x && event.motion.x < (n_w + b.pos_play.x) && event.motion.y > b.pos_play.y && event.motion.y < (n_h + b.pos_play.y))
                {
                    if(i==1)
                    {
                        break ;
                    }
                    else
                    {
                        i = 1;

                        SDL_BlitSurface(b.play, NULL, screen, &b.posback);
                        SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                        displayText(t, screen);
                        SDL_Flip(screen);
                        Mix_PlayChannel(1, music,0);
                    }



                }
                if (event.motion.x > b.pos_credit.x && event.motion.x < (n_w + b.pos_credit.x) && event.motion.y > b.pos_credit.y && event.motion.y < (n_h + b.pos_credit.y))
                {
                    if(i==2)
                    {
                        break ;
                    }
                    else
                    {
                        i = 2;

                        SDL_BlitSurface(b.credit, NULL, screen, &b.posback);
                        SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                        displayText(t, screen);
                        SDL_Flip(screen);
                        Mix_PlayChannel(1, music,0);
                    }
                }
                if (event.motion.x > b.pos_settings.x && event.motion.x < (s_w + b.pos_settings.x) && event.motion.y > b.pos_settings.y && event.motion.y < (s_h + b.pos_settings.y))
                {
                    if(i==3)
                    {
                        break ;
                    }
                    else
                    {
                        i = 3;

                        SDL_BlitSurface(b.settings, NULL, screen, &b.posback);
                        SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                        displayText(t, screen);
                        SDL_Flip(screen);
                        Mix_PlayChannel(1, music,0);
                    }

                }
                if (event.motion.x > b.pos_quitter.x && event.motion.x < (e_w + b.pos_quitter.x) && event.motion.y > b.pos_quitter.y && event.motion.y < (e_h + b.pos_quitter.y))
                {
                    if(i==4)
                    {
                        break ;
                    }
                    else
                    {
                        i = 4;

                        SDL_BlitSurface(b.quitter, NULL, screen, &b.posback);
                        SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                        displayText(t, screen);
                        SDL_Flip(screen);
                        Mix_PlayChannel(1, music,0);
                    }
                }

                break;

            case SDL_QUIT:
                      screen == NULL;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:

                    running=0 ;
                    break ;
                case SDLK_SPACE:
                    if(i==4)
                    {
                        running=0 ;
                    }
                    if (event.button.button == SDL_BUTTON_LEFT && i==3 )
                    {
                        SDL_BlitSurface(b.in_settings, NULL, screen, &b.posback);
                        SDL_Flip(screen);
                        i=0;
                        running2=1 ;
                        while(running2)
                        {

                            SDL_WaitEvent(&event);
                            switch (event.type)
                            {
                            case SDL_MOUSEMOTION:

                                if (event.motion.x > b.pos_insound.x && event.motion.x < (i_s_w + b.pos_insound.x) && event.motion.y > b.pos_insound.y && event.motion.y < (i_s_h + b.pos_insound.y))
                                {
                                    if(i==1)
                                    {
                                        break ;
                                    }
                                    else
                                    {
                                        i=1 ;
                                        if(fleche==1)
                                        {
                                            SDL_BlitSurface(b.in_sound, NULL, screen, &b.posback);
                                            Mix_PlayMusic(music0,-1);
                                            Mix_PauseMusic();
                                        }
                                        else if (fleche==2)
                                        {
                                            SDL_BlitSurface(b.in_sound25, NULL, screen, &b.posback);
                                             Mix_PauseMusic();
                                    Mix_PlayMusic(music25,-1);
                                        }
                                        else if (fleche==3)
                                        {
                                            SDL_BlitSurface(b.in_sound50, NULL, screen, &b.posback);
                                              Mix_PauseMusic();
                                    Mix_PlayMusic(music50,-1);
                                        }
                                        if (fleche==4)
                                        {
                                            SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
                                              Mix_PauseMusic();
                                    Mix_PlayMusic(music100,-1);
                                        }
					if (fleche>4)
                                        {
                                            SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
                                            Mix_PauseMusic();
                                    Mix_PlayMusic(music100,-1);
                                        }
                                        if (fleche<1)
                                        {
                                            SDL_BlitSurface(b.in_sound, NULL, screen, &b.posback);
                                            Mix_PauseMusic();
                                        }
                                        SDL_Flip(screen);
                                        Mix_PlayChannel(1, music,0);
                                    }
                                }
                                if (event.motion.x > b.pos_fullscreen.x && event.motion.x < (i_s_w + b.pos_fullscreen.x) && event.motion.y > b.pos_fullscreen.y && event.motion.y < (i_s_h + b.pos_fullscreen.y))
                                {
                                    if(i==2)
                                    {
                                        break ;
                                    }
                                    else
                                    {
                                        i=2 ;
                                        SDL_BlitSurface(b.fullscreen, NULL, screen, &b.posback);


                                        SDL_Flip(screen);
                                        Mix_PlayChannel(1, music,0);
                                    }
                                }
                                if (event.motion.x > b.pos_normalscreen.x && event.motion.x < (i_s_w + b.pos_normalscreen.x) && event.motion.y >b.pos_normalscreen.y && event.motion.y < (i_s_h + b.pos_normalscreen.y))
                                {
                                    if(i==4)
                                    {
                                        break ;
                                    }
                                    else
                                    {
                                        i=4 ;
                                        SDL_BlitSurface(b.normalscreen, NULL, screen, &b.posback);
                                        SDL_Flip(screen);
                                        Mix_PlayChannel(1, music,0);
                                    }
                                }
                                if (event.motion.x > b.pos_back_settings.x && event.motion.x < (i_s_w + b.pos_back_settings.x) && event.motion.y > b.pos_back_settings.y && event.motion.y < (i_s_h + b.pos_back_settings.y))
                                {
                                    if(i==3)
                                    {
                                        break ;
                                    }
                                    else
                                    {
                                        i=3 ;
                                        SDL_BlitSurface(b.back_settings, NULL, screen, &b.posback);
                                        SDL_Flip(screen);
                                        Mix_PlayChannel(1, music,0);
                                    }
                                }
                                break ;
                            case SDL_MOUSEBUTTONDOWN:
                                if (event.button.button == SDL_BUTTON_LEFT && i==3 )
                                {
                                    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                    SDL_BlitSurface(b.background, NULL, screen, &b.posback);
                                    displayText(t, screen);
                                    
                                    SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                    SDL_Flip(screen);
                                    running2=0 ;
                                }
                                break ;
                            case SDL_QUIT:
                                  running2= 0;
                      		  running=0 ;
                                break;
                            case SDL_KEYDOWN:
                                switch (event.key.keysym.sym)
                                {
                                case SDLK_ESCAPE:
                                    running3=0 ;
                                    running=0 ;
                                    break ;
                                case SDLK_LEFT :
                                    fleche ++ ;
                                    if(fleche>5)
                                        fleche=1 ;
                                    if(fleche<5)
                                    {
                                        switch (fleche)
                                        {
                                        case 1 :
                                            SDL_BlitSurface(b.in_sound25, NULL, screen, &b.posback);
                                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                            SDL_Flip(screen);
                                            break;

                                        case 2:
                                            SDL_BlitSurface(b.in_sound50, NULL, screen, &b.posback);
                                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                            SDL_Flip(screen);
                                            break;
 					case 3:
                                            SDL_BlitSurface(b.in_sound75, NULL, screen, &b.posback);
                                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                            SDL_Flip(screen);
                                            break;
					case 4 :
		                          SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
		                          SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
		                          SDL_Flip(screen);
		                          break ;
                                        }
                                    }
                                    break ;
                                case SDLK_RIGHT:
				if(fleche!=4)
				{
                                    fleche-- ;
                                    if(fleche>5)
                                        fleche=3 ;
                                    if(fleche<5)
                                    {
                                        switch (fleche)
                                        {
                                        case 1 :
                                            SDL_BlitSurface(b.in_sound, NULL, screen, &b.posback);
                                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                            SDL_Flip(screen);
                                            break;

                                        case 2:
                                            SDL_BlitSurface(b.in_sound25, NULL, screen, &b.posback);
                                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                            SDL_Flip(screen);
                                            break;
                                        case 3:
                                            SDL_BlitSurface(b.in_sound50, NULL, screen, &b.posback);
                                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                            SDL_Flip(screen);
                                            break ;
					case 4:
                                            SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
                                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                            SDL_Flip(screen);
                                            break ;
                                        }
                                    }
}
                                    break ;
                                case SDLK_SPACE:
                                    if(i==3)
                                    {
                                        SDL_BlitSurface(b.background, NULL, screen, &b.posback);
                                        displayText(t, screen);
                                        SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                        SDL_Flip(screen);
                                        running2=0 ;
                                    }
                                    break ;
                                    if(i==4)
                                    {
                                        SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
					displayText(t, screen);
                                        SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                        SDL_Flip(screen);
                                        Mix_PlayChannel(1, music,0);
                                        i=1 ;
                                    }
                                    break ;
                                        if (i == 0)
                                        {
                                           SDL_BlitSurface(b.back_settings, NULL, screen, &b.posback);
                                            SDL_Flip(screen);
                                            Mix_PlayChannel(1, music,0);
                                            i = 4;
                                        }
                                    }
                                    break;
                                }
                                break ;
                            }
                        }
                    break ;
                case SDLK_p:
                      SDL_BlitSurface(b.in_play, NULL, screen, &b.posback);
                    SDL_Flip(screen);
                    i=0;
                    running4=1 ;
                    while(running4) //entrer dans le sous menu de play et debuter le boucle infinie
                    {
                        SDL_WaitEvent(&event);
                        switch (event.type)
                        {
                        case SDL_QUIT:
                            running4= 0;
                            running=0 ;
                            break;
                        }
                    }
                          break;
                case SDLK_s:
                         SDL_BlitSurface(b.in_settings, NULL, screen, &b.posback);
                SDL_Flip(screen);
                i=0;
                running2=1 ;
                while(running2) //entrer dans le sous menu de settings et debuter le boucle infinie
                {

                    SDL_WaitEvent(&event);
                    switch (event.type)
                    {
                    case SDL_MOUSEMOTION:

                        if (event.motion.x > b.pos_insound.x && event.motion.x < (i_s_w + b.pos_insound.x) && event.motion.y > b.pos_insound.y && event.motion.y < (i_s_h + b.pos_insound.y))
                        {
                            if(i==1)
                            {
                                break ;
                            }
                            else
                            {
                                i=1 ;
                                if(fleche==1)
                                {
                                    SDL_BlitSurface(b.in_sound, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music0,-1);
                                }
                                else if (fleche==2)
                                {
                                    SDL_BlitSurface(b.in_sound25, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music25,-1);
                                }
                                else if (fleche==3)
                                {
                                    SDL_BlitSurface(b.in_sound50, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music50,-1);
                                }
				else if(fleche==4)
				{
				SDL_BlitSurface(b.in_sound75, NULL, screen, &b.posback);
                                Mix_PauseMusic();
                                    Mix_PlayMusic(music75,-1);
				}
				else if(fleche==5)
				{
				SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
                                Mix_PauseMusic();
                                    Mix_PlayMusic(music100,-1);
				}
                                if (fleche>5)
                                {
                                    SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music100,-1);
                                }
                                if (fleche<1)
                                {
                                    SDL_BlitSurface(b.in_sound, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                }

                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);
                            }
                        }
                        if (event.motion.x > b.pos_fullscreen.x && event.motion.x < (i_s_w + b.pos_fullscreen.x) && event.motion.y > b.pos_fullscreen.y && event.motion.y < (i_s_h + b.pos_fullscreen.y))
                        {
                            if(i==2)
                            {
                                break ;
                            }
                            else
                            {
                                i=2;
                                SDL_BlitSurface(b.fullscreen, NULL, screen, &b.posback);
                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);
                            }
                        }
                        if (event.motion.x > b.pos_normalscreen.x && event.motion.x < (i_s_w + b.pos_normalscreen.x) && event.motion.y > b.pos_normalscreen.y && event.motion.y < (i_s_h + b.pos_normalscreen.y))
                        {
                            if(i==4)
                            {
                                break ;
                            }
                            else
                            {
                                i=4 ;
                                SDL_BlitSurface(b.normalscreen, NULL, screen, &b.posback);
                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);
                            }
                        }
                        if (event.motion.x > b.pos_back_settings.x && event.motion.x < (i_s_w + b.pos_back_settings.x) && event.motion.y > b.pos_back_settings.y && event.motion.y < (i_s_h + b.pos_back_settings.y))
                        {
                            if(i==3)
                            {
                                break ;
                            }
                            else
                            {
                                i=3 ;
                                SDL_BlitSurface(b.back_settings, NULL, screen, &b.posback);
                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);
                            }
                        }
                        break ;
                   case SDL_MOUSEBUTTONDOWN:
                        if (event.button.button == SDL_BUTTON_LEFT && i==3 )
                        {
                            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                            SDL_BlitSurface(b.background, NULL, screen, &b.posback);
                            displayText(t, screen);
                           
                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                            SDL_Flip(screen);
                            running2=0 ;
                        }
                        if (event.button.button == SDL_BUTTON_LEFT && i==2 )
                        {
                            screen=switchFullScreen();
                            SDL_BlitSurface(b.in_settings, NULL, screen, &b.posback);
                            SDL_Flip(screen); 
                        }
                        if (event.button.button == SDL_BUTTON_LEFT && i==4 )
                        {
                            screen=switchFullScreen();
                            SDL_BlitSurface(b.in_settings, NULL, screen, &b.posback);
                            SDL_Flip(screen);  
                        }

                        break ;
                    case SDL_QUIT:
                        running2= 0;
                        running=0 ;
                        break;
                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {
                        case SDLK_ESCAPE:
                            running3=0 ;
                            running=0 ;
                            break ;
                        case SDLK_LEFT :

                            fleche ++ ;
                            if(fleche>5)
                                fleche=5 ;
			if (fleche<1)
			fleche=1;

                            if(fleche<=5)
                            {
                                switch (fleche)
                                {
                                case 1 :
                                    SDL_BlitSurface(b.in_sound, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music0,-1);
                                    SDL_Flip(screen);
                                    break;

                                case 2:
                                    SDL_BlitSurface(b.in_sound25, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music25,-1);
                                    SDL_Flip(screen);
                                    break;

                                case 3 :
                                    SDL_BlitSurface(b.in_sound50, NULL, screen, &b.posback);
                                    Mix_PauseMusic();
                                    Mix_PlayMusic(music50,-1);
                                    SDL_Flip(screen);
                                    break ;
 				case 4:
                                        SDL_BlitSurface(b.in_sound75, NULL, screen, &b.posback);
		                        Mix_PauseMusic();
                                    Mix_PlayMusic(music75,-1);
                                        SDL_Flip(screen);
                                        break ;
				case 5:
                                        SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
		                         Mix_PauseMusic();
                                    Mix_PlayMusic(music100,-1);
                                        SDL_Flip(screen);
                                        break ;

                                }

                            }
                            break ;
                        case SDLK_RIGHT:

                           
                                fleche-- ;
                                if(fleche>5)
                                    fleche=5 ;
				if (fleche<1)
				fleche=1;

                                if(fleche<=5)
                                {
                                    switch (fleche)
                                    {
                                    case 1 :
                                        SDL_BlitSurface(b.in_sound, NULL, screen, &b.posback);
                                        Mix_PauseMusic();
                                        Mix_PlayMusic(music0,-1);
                                        SDL_Flip(screen);
                                        break;

                                    case 2:
                                        SDL_BlitSurface(b.in_sound25, NULL, screen, &b.posback);
                                           Mix_PauseMusic();
                                    Mix_PlayMusic(music25,-1);
                                        SDL_Flip(screen);
                                        break;
                                    case 3:
                                        SDL_BlitSurface(b.in_sound50, NULL, screen, &b.posback);
                                           Mix_PauseMusic();
                                    Mix_PlayMusic(music50,-1);
                                        SDL_Flip(screen);
                                        break ;
 					case 4:
                                        SDL_BlitSurface(b.in_sound75, NULL, screen, &b.posback);
                                          Mix_PauseMusic();
                                    Mix_PlayMusic(music75,-1);
                                        SDL_Flip(screen);
                                        break ;
					case 5:
                                        SDL_BlitSurface(b.in_sound100, NULL, screen, &b.posback);
                                         Mix_PauseMusic();
                                    Mix_PlayMusic(music100,-1);
                                        SDL_Flip(screen);
                                        break ;

                                    }

                                }
                           

                            break ;
                        case SDLK_SPACE:
                            if(i==4)
                            {

                                SDL_BlitSurface(b.background, NULL, screen, &b.posback);
                                SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                SDL_Flip(screen);
                                running2=0 ;

                            }
                            break ;
                        
                                    }
                                }
                            }
                        
                    break;
                case SDLK_c:
                     SDL_BlitSurface(b.in_credit, NULL, screen, &b.posback);
                    SDL_Flip(screen);
                    i=0;
                    running5=1 ;
                    while(running5) //entrer dans le sous menu de credits et debuter le boucle infinie
                    {
                        SDL_WaitEvent(&event);
                        switch (event.type)
                        {
                        case SDL_MOUSEMOTION:
                            if (event.motion.x > b.pos_back_credit.x && event.motion.x < (i_s_w + b.pos_back_credit.x) && event.motion.y > b.pos_back_credit.y && event.motion.y < (i_s_h + b.pos_back_credit.y))
                            {
                                if(i==1)
                                {
                                    break ;
                                }
                                else
                                {
                                    i=1 ;
                                    SDL_BlitSurface(b.back_credit, NULL, screen, &b.posback);


                                    SDL_Flip(screen);
                                    Mix_PlayChannel(1, music,0);
                                }
                            }
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.button == SDL_BUTTON_LEFT && i==1 )
                            {
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(b.background, NULL, screen, &b.posback);
                                displayText(t, screen);
                          
                                SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                SDL_Flip(screen);
                                running5=0 ;
                            }

                            break ;
                        case SDL_QUIT:
                            running5= 0;
                            running=0 ;
                            break;
                        }
     }
                    break;
                case SDLK_q:
                      running=0;
              running2=0;
              running3=0;
              running4=0;
              running5=0;
                case SDLK_DOWN:
                    fprintf(f, "%d :\n", i);
                    i++;
                    if (i < 5)
                    {
                        switch (i)
                        {
                        case 1:
                            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                            SDL_BlitSurface(b.play, NULL, screen, &b.posback);
                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                            displayText(t, screen);
                            SDL_Flip(screen);
                            Mix_PlayChannel(1, music,0);

                            break;
                        case 2:
                            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                            SDL_BlitSurface(b.settings, NULL, screen, &b.posback);
                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                            displayText(t, screen);
                            SDL_Flip(screen);
                            Mix_PlayChannel(1, music,0);

                            break;
                        case 3:
                            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                            SDL_BlitSurface(b.credit, NULL, screen, &b.posback);
                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                            displayText(t, screen);
                            SDL_Flip(screen);
                            Mix_PlayChannel(1, music,0);
                            break;
                        case 4:
                            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                            SDL_BlitSurface(b.quitter, NULL, screen, &b.posback);
                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                            displayText(t, screen);
                            SDL_Flip(screen);
                            Mix_PlayChannel(1, music,0);
                            break;
                        }
                    }
                    else if (i == 5)
                    {
                        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                        SDL_BlitSurface(b.play, NULL, screen, &b.posback);
                        SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                        displayText(t, screen);
                        SDL_Flip(screen);
                        Mix_PlayChannel(1, music,0);
                        i = 1;
                    }
                    fprintf(f, "%d :\n", i);
                    break;
                case SDLK_UP:         
         i--;
                            switch (i)
                            {
                            case 1:
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(b.play, NULL, screen, &b.posback);
                                SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                displayText(t, screen);
                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);
                                break;
                            case 2:
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(b.settings, NULL, screen, &b.posback);
                                SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                displayText(t, screen);
                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);
break;
                            case 3:
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(b.credit, NULL, screen, &b.posback);
                                SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                displayText(t, screen);
                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);

                                break;
                            case 4:
                                SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                                SDL_BlitSurface(b.quitter, NULL, screen, &b.posback);
                                SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                                displayText(t, screen);
                                SDL_Flip(screen);
                                Mix_PlayChannel(1, music,0);

                                break;
                            
                        }
                       if (i == 0)
                        {
                            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
                            SDL_BlitSurface(b.quitter, NULL, screen, &b.posback);
                            SDL_BlitSurface(b.sound, NULL, screen, &b.pos_sound);
                            displayText(t, screen);
                            SDL_Flip(screen);
                            Mix_PlayChannel(1, music,0);

                            i = 4;
                        }
                    break;  
                }
}
    }
    }
    SDL_FreeSurface(b.background);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(b.play) ;
    SDL_FreeSurface(b.credit);
    SDL_FreeSurface(b.settings) ;
    SDL_FreeSurface(b.quitter) ;
    Mix_FreeMusic(music2);
    freeText(t);
    TTF_CloseFont (t.font);
    TTF_Quit();
    SDL_Quit();
    return (EXIT_SUCCESS);
}


