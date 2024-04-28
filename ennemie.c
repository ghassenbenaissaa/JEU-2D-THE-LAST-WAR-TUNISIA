#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"header.h"

Enemy InitEnemy(Enemy Ennemie,int x, int y)
{
  Ennemie.en=IMG_Load("map.png");
  Ennemie.image[0]=IMG_Load("rpg1.png");
  Ennemie.image[1]=IMG_Load("rpg2.png");
  Ennemie.image[2]=IMG_Load("rpg3.png");
  Ennemie.Hit=IMG_Load("rpg4.png");

   Ennemie.image2[0]=IMG_Load("rpd1.png");
  Ennemie.image2[1]=IMG_Load("rpd2.png");
  Ennemie.image2[2]=IMG_Load("rpd3.png");
  Ennemie.imageActuel=Ennemie.image[0];
  Ennemie.position.x=x;
  Ennemie.position.y=y;
  Ennemie.positionO=Ennemie.position;
  Ennemie.frame=0;
  Ennemie.direction=0;
  Ennemie.died=0;
  return Ennemie;
}

void  AfficherEnemy(Enemy Ennemie,SDL_Surface *screen)
{
  SDL_BlitSurface(Ennemie.imageActuel,NULL,screen,&Ennemie.position);
}
Enemy AnimateEnemy(Enemy Ennemie,int stat)
{
  if (Ennemie.frame==2) {
    Ennemie.frame=0;
  }
  else
  Ennemie.frame++;
	if (Ennemie.direction==1)
 	 	Ennemie.imageActuel=Ennemie.image[Ennemie.frame];
	else if(Ennemie.direction==0)
	 	 Ennemie.imageActuel=Ennemie.image2[Ennemie.frame];
  if(stat==1)
    Ennemie.imageActuel=Ennemie.Hit;
  return Ennemie;

}



Enemy MoveEnemy(Enemy Ennemie,SDL_Rect personnage,int *stat,int mouvment)
{

int distance;

  if(Ennemie.position.x>=personnage.x)
    distance=Ennemie.position.x-personnage.x;
  else
    distance=personnage.x-Ennemie.position.x;
if(distance<50)*stat=1;
else *stat=0;
    if(distance<200)
      {
        if(Ennemie.position.x>=personnage.x)
          Ennemie.direction=0;
        else
          Ennemie.direction=1;
      }

      else
    {  if(Ennemie.positionO.x+200<=Ennemie.position.x)
          Ennemie.direction=0;

      if(Ennemie.positionO.x-200>=Ennemie.position.x)

        Ennemie.direction=1;}


      if(Ennemie.direction==1)
      {
        Ennemie.position.x+=4;
      }
      if(Ennemie.direction==0)
      {
        Ennemie.position.x-=4;
      }
  
      if(mouvment==1){
      	Ennemie.position.x-=5;
      	Ennemie.positionO.x-=5;
      }
      if (mouvment==2)	{

      	Ennemie.position.x+=5;
      	Ennemie.positionO.x+=5;
      }
      if ((mouvment==3)&&(personnage.y>50)){

}
  return Ennemie;

}










Enemy InitEnemy2(Enemy Ennemie2,int x, int y)
{
  Ennemie2.en2=IMG_Load("map.png");
  Ennemie2.imagee2[0]=IMG_Load("rpg12.png");
  Ennemie2.imagee2[1]=IMG_Load("rpg22.png");
  Ennemie2.imagee2[2]=IMG_Load("rpg32.png");
  Ennemie2.Hit2=IMG_Load("rpg42.png");

   Ennemie2.image22[0]=IMG_Load("rpd12.png");
  Ennemie2.image22[1]=IMG_Load("rpd22.png");
  Ennemie2.image22[2]=IMG_Load("rpd32.png");
  Ennemie2.imageActuel2=Ennemie2.imagee2[0];
  Ennemie2.position2.x=x;
  Ennemie2.position2.y=y;
  Ennemie2.positionO2=Ennemie2.position2;
  Ennemie2.frame2=0;
  Ennemie2.direction2=0;
  Ennemie2.died2=0;
  return Ennemie2;
}

void  AfficherEnemy2(Enemy Ennemie2,SDL_Surface *screen)
{
  SDL_BlitSurface(Ennemie2.imageActuel2,NULL,screen,&Ennemie2.position2);
}
Enemy AnimateEnemy2(Enemy Ennemie2,int stat2)
{
  if (Ennemie2.frame2==2) {
    Ennemie2.frame2=0;
  }
  else
  Ennemie2.frame2++;
	if (Ennemie2.direction2==1)
 	 	Ennemie2.imageActuel2=Ennemie2.imagee2[Ennemie2.frame2];
	else if(Ennemie2.direction2==0)
	 	 Ennemie2.imageActuel2=Ennemie2.image22[Ennemie2.frame2];
  if(stat2==1)
    Ennemie2.imageActuel2=Ennemie2.Hit2;
  return Ennemie2;

}




Enemy MoveEnemy2(Enemy Ennemie2,SDL_Rect personnage2,int *stat2,int mouvment2)
{

int distance2;

  if(Ennemie2.position2.x>=personnage2.x)
    distance2=Ennemie2.position2.x-personnage2.x;
  else
    distance2=personnage2.x-Ennemie2.position2.x;
if(distance2<50)*stat2=1;
else *stat2=0;
    if(distance2<200)
      {
        if(Ennemie2.position2.x>=personnage2.x)
          Ennemie2.direction2=0;
        else
          Ennemie2.direction2=1;
      }

      else
    {  if(Ennemie2.positionO2.x+200<=Ennemie2.position2.x)
          Ennemie2.direction2=0;

      if(Ennemie2.positionO2.x-200>=Ennemie2.position2.x)

        Ennemie2.direction2=1;}


      if(Ennemie2.direction2==1)
      {
        Ennemie2.position2.x+=4;
      }
      if(Ennemie2.direction2==0)
      {
        Ennemie2.position2.x-=4;
      }
  
      if(mouvment2==1){
      	Ennemie2.position2.x-=5;
      	Ennemie2.positionO2.x-=5;
      }
      if (mouvment2==2)	{

      	Ennemie2.position2.x+=5;
      	Ennemie2.positionO2.x+=5;
      }
      if ((mouvment2==3)&&(personnage2.y>50)){

}
  return Ennemie2;

}





























Enemy InitEnemy3(Enemy Ennemie3,int x, int y)
{
  Ennemie3.en3=IMG_Load("map.png");
  Ennemie3.image3[0]=IMG_Load("rpg11.png");
  Ennemie3.image3[1]=IMG_Load("rpg21.png");
  Ennemie3.image3[2]=IMG_Load("rpg31.png");
  Ennemie3.Hit3=IMG_Load("rpg41.png");

  Ennemie3.image23[0]=IMG_Load("rpd11.png");
  Ennemie3.image23[1]=IMG_Load("rpd21.png");
  Ennemie3.image23[2]=IMG_Load("rpd31.png");
  Ennemie3.imageActuel3=Ennemie3.image3[0];
  Ennemie3.position3.x=x;
  Ennemie3.position3.y=y;
  Ennemie3.positionO3=Ennemie3.position3;
  Ennemie3.frame3=0;
  Ennemie3.direction3=0;
  Ennemie3.died3=0;
  return Ennemie3;
}

void  AfficherEnemy3(Enemy Ennemie3,SDL_Surface *screen)
{
  SDL_BlitSurface(Ennemie3.imageActuel3,NULL,screen,&Ennemie3.position3);
}
Enemy AnimateEnemy3(Enemy Ennemie3,int stat3)
{
  if (Ennemie3.frame3==2) {
    Ennemie3.frame3=0;
  }
  else
  Ennemie3.frame3++;
	if (Ennemie3.direction3==1)
 	 	Ennemie3.imageActuel3=Ennemie3.image3[Ennemie3.frame3];
	else if(Ennemie3.direction3==0)
	 	 Ennemie3.imageActuel3=Ennemie3.image23[Ennemie3.frame3];
  if(stat3==1)
    Ennemie3.imageActuel3=Ennemie3.Hit3;
  return Ennemie3;

}



Enemy MoveEnemy3(Enemy Ennemie3,SDL_Rect personnage3,int *stat3,int mouvment3)
{

int distance3;

  if(Ennemie3.position3.x>=personnage3.x)
    distance3=Ennemie3.position3.x-personnage3.x;
  else
    distance3=personnage3.x-Ennemie3.position3.x;
if(distance3<50)*stat3=1;
else *stat3=0;
    if(distance3<200)
      {
        if(Ennemie3.position3.x>=personnage3.x)
          Ennemie3.direction3=0;
        else
          Ennemie3.direction3=1;
      }

      else
    {  if(Ennemie3.positionO3.x+200<=Ennemie3.position3.x)
          Ennemie3.direction3=0;

      if(Ennemie3.positionO3.x-200>=Ennemie3.position3.x)

        Ennemie3.direction3=1;}


      if(Ennemie3.direction3==1)
      {
        Ennemie3.position3.x+=4;
      }
      if(Ennemie3.direction3==0)
      {
        Ennemie3.position3.x-=4;
      }
  
      if(mouvment3==1){
      	Ennemie3.position3.x-=5;
      	Ennemie3.positionO3.x-=5;
      }
      if (mouvment3==2)	{

      	Ennemie3.position3.x+=5;
      	Ennemie3.positionO3.x+=5;
      }
      if ((mouvment3==3)&&(personnage3.y>50)){

}
  return Ennemie3;

}




