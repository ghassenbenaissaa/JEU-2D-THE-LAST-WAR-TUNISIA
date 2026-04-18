#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"headerpartage.h"
int animation_persop(hero evan){


	int farm=evan.farm;
	switch(evan.mouvment){

		case 1:
				if (farm<6)
					farm++;
				else farm=0;
				//usleep(30000);
			
			break;
		case 2:
                       
				if (farm<6)

					farm++;

				else farm=0;			
				
				//usleep(20000);
			
			break;
		case 3:
			if (farm<6)
					farm++;
				else farm=0;			
				
				//usleep(20000);
			
			break;
		default: farm=0;
	}
	return farm;
}
//*************************back2

int animation_perso2p(hero evan2){


	int farm2=evan2.farm2;
	switch(evan2.mouvment2){

		case 1:
				if (farm2<6)
					farm2++;
				else farm2=0;
				//usleep(30000);
			
			break;
		case 2:
                       
				if (farm2<6)

					farm2++;

				else farm2=0;			
				
				//usleep(20000);
			
			break;
		case 3:
			if (farm2<6)
					farm2++;
				else farm2=0;			
				
				//usleep(20000);
			
			break;
		default: farm2=0;
	}
	return farm2;
}

