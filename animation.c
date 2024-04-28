#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header.h"
int animation_perso(hero evan){

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

int animation_perso2(hero evan2){


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
//**************************************back3
int animation_perso3(hero evan3){


	int farm3=evan3.farm3;
	switch(evan3.mouvment3){

		case 1:
				if (farm3<6)
					farm3++;
				else farm3=0;
				//usleep(30000);
			
			break;
		case 2:
                       
				if (farm3<6)

					farm3++;

				else farm3=0;			
				
				//usleep(20000);
			
			break;
		case 3:
			if (farm3<6)
					farm3++;
				else farm3=0;			
				
				//usleep(20000);
			
			break;
		default: farm3=0;
	}
	return farm3;
}
