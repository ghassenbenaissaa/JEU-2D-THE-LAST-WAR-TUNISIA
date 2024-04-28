#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header.h"
void scrolling (hero *evan,background *b,int co )
{ //evan->heromoved=0;
	switch(evan->mouvment)
	{

		case 1: 
			if (co!=1){
			if ((b->pos_background2.x<5200)&&(evan->pos_hero2.x>=800))
                		b->pos_background2.x=b->pos_background2.x+15;
			if (((evan->pos_hero2.x<800)||((b->pos_background2.x>=5200))&&(evan->pos_hero2.x<1700)))
				evan->pos_hero2.x=evan->pos_hero2.x+15;
evan->heromoved=1;
			
		}
		break;
		case 2:
		if (co!=1){
			if (b->pos_background2.x>0)
                		b->pos_background2.x=b->pos_background2.x-15;
	    		if (((b->pos_background2.x!=0)&&(evan->pos_hero2.x>=150))||((b->pos_background2.x==0)&&(evan->pos_hero2.x=50)))
				evan->pos_hero2.x=evan->pos_hero2.x-15;
		    evan->heromoved=2;
			}	
		break;
		case 3:

		if (evan->pos_hero2.y>50){
			if (b->pos_background2.x<5200)

				evan->pos_hero2.y=evan->pos_hero2.y-20;	

		}
                if ((evan->pos_hero2.y>750)&&(b->pos_background2.y>=0))
                b->pos_background2.y=b->pos_background2.y-5;
		break;
		case 4:

		if ((evan->pos_hero2.y<600)&&(evan->pos_hero2.y!=400)&&(b->pos_background2.y<20))
                b->pos_background2.y=b->pos_background2.y+5;
		if ((co!=2)&&(co!=1))

		evan->pos_hero2.y=evan->pos_hero2.y+17;

		break;
                
		
	}
	if ((evan->mouvment!=3)&&(co!=2)&&(co!=1))
		evan->pos_hero2.y=evan->pos_hero2.y+17;

	
}


//***********************************background2*******************************

void scrolling2(hero *evan2,background *b2,int co2 )
{
	
	switch(evan2->mouvment2)
	{

		case 1: 
			if (co2!=1){
			if ((b2->pos_background22.x<5500)&&(evan2->pos_hero22.x>=800))
                		b2->pos_background22.x=b2->pos_background22.x+15;
			if (((evan2->pos_hero22.x<800)||((b2->pos_background22.x>=5500))&&(evan2->pos_hero22.x<1700)))
				evan2->pos_hero22.x=evan2->pos_hero22.x+10;
evan2->heromoved2=1;
			
		}
		break;
		case 2:
		if (co2!=1){
			if (b2->pos_background22.x>0)
                		b2->pos_background22.x=b2->pos_background22.x-15;
	    		if (((b2->pos_background22.x!=0)&&(evan2->pos_hero22.x>=150))||((b2->pos_background22.x==0)&&(evan2->pos_hero22.x=50)))
				evan2->pos_hero22.x=evan2->pos_hero22.x-10;
 evan2->heromoved2=2;
			   
			}	
		break;
		case 3:

		if (evan2->pos_hero22.y>50){
			if (b2->pos_background22.x<5500)
				evan2->pos_hero22.y=evan2->pos_hero22.y-20;	
		}
                if ((evan2->pos_hero22.y>750)&&(b2->pos_background22.y>=0))
                b2->pos_background22.y=b2->pos_background22.y-5;
		break;
		case 4:

		if ((evan2->pos_hero22.y<600)&&(evan2->pos_hero22.y!=810)&&(b2->pos_background22.y<20))
                b2->pos_background22.y=b2->pos_background22.y+5;
		if ((co2!=2)&&(co2!=1))
		evan2->pos_hero22.y=evan2->pos_hero22.y+10;
		break;
                
		
	}
	if ((evan2->mouvment2!=3)&&(co2!=2)&&(co2!=1))
		evan2->pos_hero22.y=evan2->pos_hero22.y+5;
	
}


//***********************************background3*******************************

void scrolling3(hero *evan3,background *b3,int co3 )
{
	
	switch(evan3->mouvment3)
	{

		case 1: 
			if (co3!=1){
			if ((b3->pos_background23.x<5500)&&(evan3->pos_hero23.x>=800))
                		b3->pos_background23.x=b3->pos_background23.x+15;
			if (((evan3->pos_hero23.x<800)||((b3->pos_background23.x>=5500))&&(evan3->pos_hero23.x<1700)))
				evan3->pos_hero23.x=evan3->pos_hero23.x+10;
evan3->heromoved3=1;
			
		}
		break;
		case 2:
		if (co3!=1){
			if (b3->pos_background23.x>0)
                		b3->pos_background23.x=b3->pos_background23.x-15;
	    		if (((b3->pos_background23.x!=0)&&(evan3->pos_hero23.x>=150))||((b3->pos_background23.x==0)&&(evan3->pos_hero23.x=50)))
				evan3->pos_hero23.x=evan3->pos_hero23.x-10;
 evan3->heromoved3=2;
			   
			}	
		break;
		case 3:

		if (evan3->pos_hero23.y>50){
			if (b3->pos_background23.x<5500)
				evan3->pos_hero23.y=evan3->pos_hero23.y-20;	
		}
                if ((evan3->pos_hero23.y>750)&&(b3->pos_background23.y>=0))
                b3->pos_background23.y=b3->pos_background23.y-5;
		break;
		case 4:

		if ((evan3->pos_hero23.y<600)&&(evan3->pos_hero23.y!=810)&&(b3->pos_background23.y<20))
                b3->pos_background23.y=b3->pos_background23.y+5;
		if ((co3!=2)&&(co3!=1))
		evan3->pos_hero23.y=evan3->pos_hero23.y+10;
		break;
                
		
	}
	if ((evan3->mouvment3!=3)&&(co3!=2)&&(co3!=1))
		evan3->pos_hero23.y=evan3->pos_hero23.y+5;
	
}













