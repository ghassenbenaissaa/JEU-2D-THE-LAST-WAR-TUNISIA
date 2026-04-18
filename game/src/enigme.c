/**  
* @file enigme.c  
* @brief Testing Program.  
* @author ACE 
* @version 1.0 
* @date Apr 19, 2022
*  
* Testing program for enigme  *  
*/


#include "header.h"
//*********************enigme1**************************************
void Init_Enigme(Enigme *e, char *f1 , char *f2 ,char *f3)
{
	e->background[0]=IMG_Load("fond2.png");
	e->background[1]=IMG_Load("enigmes.png");

	e->win=IMG_Load("youWin1.png");
   	e->lost=IMG_Load("gameOver.png");

        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);  
        Mix_Music *music ;
        music=Mix_LoadMUS("game1.mp3");
        Mix_PlayMusic(music,-1);
	for(int i=1;i<5;i++)
	{
		char str[30];
		sprintf(str,"%dt.png",i);
		e->boutons[i]=IMG_Load(str);
	}

	srand(time(NULL));
	e->choix_question=rand()%4;

	while(e->choix_question==0){
		srand(time(NULL));
		e->choix_question=rand()%4;
	}

	SDL_Color couleurNoire={0,0,0};
	TTF_Font *police;
	TTF_Init();
	police = TTF_OpenFont("font.ttf", 20);

	char question[150];
	FILE *fichier;
    fichier=fopen(f1, "r");
    int i=1,boucle=1;
    if(fichier!=NULL)
    {
    	while(fgets((question),150,fichier)!=NULL && boucle==1)
    	{
    		if(e->choix_question==i)
    		{
    			e->question = TTF_RenderText_Blended (police,question,couleurNoire);
    			boucle=0;//en quit le boucle while
    		}
    		else{
    			i++;
    		}
    		
    	} 	
    	fclose(fichier);
    }
    

    FILE *fic;
    fic=fopen(f2, "r");
    int min,max;
    switch(e->choix_question)
    {
    	case 1:
    	{
    		min=1;
    		max=3;
    		break;
    	}
    	case 2:
    	{
    		min=4;
    		max=6;
    		break;
    	}
    	case 3:
    	{
    		min=7;
    		max=9;
    		break;
    	}
    }
    int j=1;
    if(fic!=NULL)
    {
    	char reponses[150];
    	while(fgets((reponses),15,fic)!=NULL && j<=max)
    	{	
    		if(j>min || j==min)
    		{
    			e->reponses[j-min+1]= TTF_RenderText_Blended (police,reponses,couleurNoire);
    			printf("%s\n",reponses);
    		}
    		j++;
    		
    	}
    	fclose(fic);
    }
    
    printf("%d\n",e->choix_question);

    FILE *f;
    f=fopen(f3, "r");
    char vraiReponse[150];
    int k=1,boucle1=1;
    if(f!=NULL)
    {
    	while(fgets((vraiReponse),15,f)!=NULL && boucle1==1)
    	{
    		if(e->choix_question==k)
    		{
    			e->reponses[4]= TTF_RenderText_Blended (police,vraiReponse,couleurNoire);
    			
    			boucle1=0;//en quit le boucle while
    		}
    		else{
    			k++;
    		}
    		
    	} 	
    	fclose(f);
    }
    

    
    e->posRepones[1].x=809;
	e->posRepones[1].y=471;
	e->posRepones[2].x=809;
	e->posRepones[2].y=564;
	e->posRepones[3].x=809;
	e->posRepones[3].y=676;
	e->posRepones[4].x=809;
	e->posRepones[4].y=783;

	e->posQuestion.x=709;
	e->posQuestion.y=325;

	e->image_courrante=1;


	srand(time(NULL));
	e->positionVraiReponse=rand()%5;

	while(e->positionVraiReponse==0){
		srand(time(NULL));
		e->positionVraiReponse=rand()%5;
	}

}


void Display_Enigme(Enigme *e,SDL_Surface *ecran)
{
	SDL_Rect position;
	position.x = 0;
	position.y = 0;
	SDL_BlitSurface(e->background[0],NULL,ecran,NULL);
	SDL_BlitSurface(e->background[1],NULL,ecran,&position);

	SDL_BlitSurface(e->boutons[e->image_courrante],NULL,ecran,&position);

	
	switch(e->positionVraiReponse)
	{
		case 1:
		{
			SDL_BlitSurface(e->reponses[1],NULL,ecran,&(e->posRepones[2]));
			SDL_BlitSurface(e->reponses[2],NULL,ecran,&(e->posRepones[3]));
			SDL_BlitSurface(e->reponses[3],NULL,ecran,&(e->posRepones[4]));
			break;
		}
		case 2:
		{
			SDL_BlitSurface(e->reponses[1],NULL,ecran,&(e->posRepones[1]));
			SDL_BlitSurface(e->reponses[2],NULL,ecran,&(e->posRepones[3]));
			SDL_BlitSurface(e->reponses[3],NULL,ecran,&(e->posRepones[4]));
			break;
		}
		case 3:
		{
			SDL_BlitSurface(e->reponses[1],NULL,ecran,&(e->posRepones[1]));
			SDL_BlitSurface(e->reponses[2],NULL,ecran,&(e->posRepones[2]));
			SDL_BlitSurface(e->reponses[3],NULL,ecran,&(e->posRepones[4]));
			break;
		}
		case 4:
		{
			SDL_BlitSurface(e->reponses[1],NULL,ecran,&(e->posRepones[1]));
			SDL_BlitSurface(e->reponses[2],NULL,ecran,&(e->posRepones[2]));
			SDL_BlitSurface(e->reponses[3],NULL,ecran,&(e->posRepones[3]));
			break;
		}
	}
	

	SDL_BlitSurface(e->reponses[4],NULL,ecran,&(e->posRepones[e->positionVraiReponse]));//la vrai reponse


	SDL_BlitSurface(e->question,NULL,ecran,&(e->posQuestion));
	SDL_Flip(ecran);
}

int Verify_Enigme(Enigme *e,int *Game,SDL_Surface *ecran)
{
      Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);  
     Mix_Chunk* button,*win1, *lose1; 
     win1=Mix_LoadWAV("win.wav");
     lose1=Mix_LoadWAV("fail.wav");
	SDL_Rect position={0,0};
	if(e->positionVraiReponse==e->image_courrante)
	{
		(*Game)=1;
                 
		SDL_BlitSurface(e->win,NULL,ecran,&position);
		SDL_Flip(ecran);
                 Mix_PlayChannel(1,win1,0);
		SDL_Delay(1000);
		return 0;//win
	}
	else
	{
		(*Game)=0;
		SDL_BlitSurface(e->lost,NULL,ecran,&position);
		SDL_Flip(ecran);
                Mix_PlayChannel(1,lose1,0);
		SDL_Delay(1000);
		return 0;//lost
	}
}

int Play_Enigme(Enigme *e,SDL_Surface *ecran,int *Game)
{

 tempss temp; 
SDL_Color rouge = {255,255,255};
temp=initialiser_temp (temp);


	while(1)
	{

		Display_Enigme(e,ecran);//affichage
temp.temp=TTF_RenderText_Blended(temp.police,temp.chaine,rouge);

temp.tempactuel=SDL_GetTicks();

if (temp.tempactuel- temp.tempprecedent >1000  )
{
temp.seconde1++;
temp.tempprecedent= temp.tempactuel;

}
if (temp.seconde1>9)
{
	temp.seconde1=0;
	temp.seconde2++;
}
if (temp.seconde2>=6)
{
	temp.seconde2=0;
	temp.minute1++;
}
if (temp.minute1>=9)
{
	temp.minute1=0;
	temp.minute2++;
}
if (temp.minute2>=6)
{
	temp.minute2=0;
	temp.heur1++;
}
if (temp.heur1>=9)
{
	temp.heur1=0;
	temp.heur2++;
}
sprintf(temp.chaine,"%d %d : %d %d ",temp.minute2,temp.minute1,temp.seconde2,temp.seconde1);
SDL_BlitSurface(temp.temp,NULL,ecran,&temp.position_temp);
SDL_Flip(ecran) ;
	Display_Enigme(e,ecran);
	SDL_Event event;
       if (temp.seconde1==9)
return 0;
		while(SDL_PollEvent(&event))
		{
           
		switch (event.type)
		{ 
			case SDL_KEYDOWN:
			{
				if(event.key.keysym.sym==SDLK_UP)
				{//o++;
					e->image_courrante--;
					if(e->image_courrante<1)
					{
						e->image_courrante=4;
					}
				}
				else if(event.key.keysym.sym==SDLK_DOWN)
				{//o++;
					e->image_courrante++;
					if(e->image_courrante>4)
					{
						e->image_courrante=1;
					}
		
				}
				else if(event.key.keysym.sym==SDLK_RETURN)
				{
					return Verify_Enigme(e,Game,ecran);
				}
                                 //if(o==5)
                                 //return 0;
				break;
                         
			}
			case SDL_MOUSEMOTION:
			{
				printf("Souris en position %d %d\n",event.motion.x, event.motion.y);
			}
			case SDL_MOUSEBUTTONUP:
			{

				if(event.motion.x>280 && event.motion.x<525 && event.motion.y>255 && event.motion.y<290)
				{
					e->image_courrante=1;	 
					if (event.button.button == SDL_BUTTON_LEFT)
					{ 
						return Verify_Enigme(e,Game,ecran);
					}
					break;
				}
				else if(event.motion.x>280 && event.motion.x<525 && event.motion.y>300 && event.motion.y<335)
				{
					e->image_courrante=2;			 
					if (event.button.button == SDL_BUTTON_LEFT)
					{ 
						return Verify_Enigme(e,Game,ecran);
					}
					break;
				}
				else if(event.motion.x>280 && event.motion.x<525 && event.motion.y>350 && event.motion.y<380)
				{
					e->image_courrante=3;	
					if (event.button.button == SDL_BUTTON_LEFT)
					{ 
						return Verify_Enigme(e,Game,ecran);
					}
					break;
				}
				else if(event.motion.x>280 && event.motion.x<525 && event.motion.y>395 && event.motion.y<425)
				{
					e->image_courrante=4;	
					if (event.button.button == SDL_BUTTON_LEFT)
					{ 
						return Verify_Enigme(e,Game,ecran);
					}
					break;
				}
				break;
			}
			case SDL_QUIT:
			{	
				return 0;
			}
		}

}
	}printf("sortie");

}


void animerEnigme (SDL_Surface *porte[14],SDL_Rect *port,SDL_Surface *ecran)
{
    int j;
    char ch[50];
 
    port->x=  0 ;
    port->y=  0 ;

    for(j=1; j<15; j++)
    {
        sprintf(ch,"../Background/animation/%d.png",j);
        porte[j]=IMG_Load(ch);
    }

    for(j=1; j<15; j++)
    {
        SDL_BlitSurface(porte[j], NULL,ecran,port);
        SDL_Flip(ecran);
        SDL_Delay(120);
    }  
}

void animerEnigmee (SDL_Surface *porte[14],SDL_Rect *port,SDL_Surface *ecran)
{
    int j;
    char ch[50];
 
    port->x=  0 ;
    port->y=  0 ;

    for(j=1; j<14; j++)
    {
        sprintf(ch,"../Background/animation/%d.png",j);
        porte[j]=IMG_Load(ch);
    }

    for(j=1; j<14; j++)
    {
        SDL_BlitSurface(porte[j], NULL,ecran,port);
        SDL_Flip(ecran);
        SDL_Delay(120);
    }  
}
void init_save (save *s)
{
	s->posperso.x=-1;
	s->posperso.y=-1;
	s->posennemi.x=-1;
	s->posennemi.y=-1;
	s->vies=-1;
	s->temps=-1;
	s->score=-1;
	s->fichier=NULL;
}

void update_save (save *s, SDL_Rect perso,SDL_Rect ennemi,SDL_Rect cam, int v , int tps, int sc)
{
	s->pos_hero2=perso; 
	s->posennemi=ennemi;
	s->poscam=cam; 
	s->vies=v; 
	s->temps=tps; 
	s->score=sc; 
}

void enregistrer (save s)
{
	s.fichier=fopen("Sauvegarde","wb");
	if (s.fichier !=NULL)
	{
		fwrite(&s,sizeof(save),1,s.fichier);
		printf("Sauvegarde reussie ! \n");	
		fclose (s.fichier);
	}else 
		printf("Impossible d'ouvrir le fichier !\n");
}

void chargement (save *s)
{
	s->fichier=fopen("Sauvegarde","rb");
	if (s->fichier !=NULL)
	{
		fread(&s,sizeof(save),1,s->fichier);
		printf("perso.x=%d, perso.y=%d\n", s->pos_hero2.x, s->pos_hero2.y);
		printf("ennemi.x=%d, ennemi.y=%d\n", s->posennemi.x, s->posennemi.y);
		printf("cam.x=%d, cam.y=%d\n", s->poscam.x, s->poscam.y);
		printf("vies=%d, temps=%d, score=%d\n", s->vies, s->temps, s->score);	
		fclose (s->fichier);
	}else 
		printf("Impossible d'ouvrir le fichier !\n");
}


//****************************enigme2***************************************
void Init_Enigmee(Enigme *ee, char *f1 , char *f2 ,char *f3)
{
	ee->background[0]=IMG_Load("fond22.png");
	ee->background[1]=IMG_Load("enigmes2.png");

	ee->win=IMG_Load("youWin1.png");
   	ee->lost=IMG_Load("gameOver.png");

        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);  
        Mix_Music *music ;
        music=Mix_LoadMUS("game1.mp3");
        Mix_PlayMusic(music,-1);
	for(int i=1;i<5;i++)
	{
		char str[30];
		sprintf(str,"%dtt.png",i);
		ee->boutons[i]=IMG_Load(str);
	}

	srand(time(NULL));
	ee->choix_question=rand()%4;

	while(ee->choix_question==0){
		srand(time(NULL));
		ee->choix_question=rand()%4;
	}

	SDL_Color couleurNoire={0,0,0};
	TTF_Font *police;
	TTF_Init();
	police = TTF_OpenFont("font.ttf", 20);

	char question[150];
	FILE *fichier;
    fichier=fopen(f1, "r");
    int i=1,boucle=1;
    if(fichier!=NULL)
    {
    	while(fgets((question),150,fichier)!=NULL && boucle==1)
    	{
    		if(ee->choix_question==i)
    		{
    			ee->question = TTF_RenderText_Blended (police,question,couleurNoire);
    			boucle=0;//en quit le boucle while
    		}
    		else{
    			i++;
    		}
    		
    	} 	
    	fclose(fichier);
    }
    

    FILE *fic;
    fic=fopen(f2, "r");
    int min,max;
    switch(ee->choix_question)
    {
    	case 1:
    	{
    		min=1;
    		max=3;
    		break;
    	}
    	case 2:
    	{
    		min=4;
    		max=6;
    		break;
    	}
    	case 3:
    	{
    		min=7;
    		max=9;
    		break;
    	}
    }
    int j=1;
    if(fic!=NULL)
    {
    	char reponses[150];
    	while(fgets((reponses),15,fic)!=NULL && j<=max)
    	{	
    		if(j>min || j==min)
    		{
    			ee->reponses[j-min+1]= TTF_RenderText_Blended (police,reponses,couleurNoire);
    			printf("%s\n",reponses);
    		}
    		j++;
    		
    	}
    	fclose(fic);
    }
    
    printf("%d\n",ee->choix_question);

    FILE *f;
    f=fopen(f3, "r");
    char vraiReponse[150];
    int k=1,boucle1=1;
    if(f!=NULL)
    {
    	while(fgets((vraiReponse),15,f)!=NULL && boucle1==1)
    	{
    		if(ee->choix_question==k)
    		{
    			ee->reponses[4]= TTF_RenderText_Blended (police,vraiReponse,couleurNoire);
    			
    			boucle1=0;//en quit le boucle while
    		}
    		else{
    			k++;
    		}
    		
    	} 	
    	fclose(f);
    }
    

    
    ee->posRepones[1].x=809;
	ee->posRepones[1].y=471;
	ee->posRepones[2].x=809;
	ee->posRepones[2].y=564;
	ee->posRepones[3].x=809;
	ee->posRepones[3].y=676;
	ee->posRepones[4].x=809;
	ee->posRepones[4].y=783;

	ee->posQuestion.x=709;
	ee->posQuestion.y=325;

	ee->image_courrante=1;


	srand(time(NULL));
	ee->positionVraiReponse=rand()%5;

	while(ee->positionVraiReponse==0){
		srand(time(NULL));
		ee->positionVraiReponse=rand()%5;
	}

}


void Display_Enigmee(Enigme *ee,SDL_Surface *ecran)
{
	SDL_Rect position;
	position.x = 0;
	position.y = 0;
	SDL_BlitSurface(ee->background[0],NULL,ecran,NULL);
	SDL_BlitSurface(ee->background[1],NULL,ecran,&position);

	SDL_BlitSurface(ee->boutons[ee->image_courrante],NULL,ecran,&position);

	
	switch(ee->positionVraiReponse)
	{
		case 1:
		{
			SDL_BlitSurface(ee->reponses[1],NULL,ecran,&(ee->posRepones[2]));
			SDL_BlitSurface(ee->reponses[2],NULL,ecran,&(ee->posRepones[3]));
			SDL_BlitSurface(ee->reponses[3],NULL,ecran,&(ee->posRepones[4]));
			break;
		}
		case 2:
		{
			SDL_BlitSurface(ee->reponses[1],NULL,ecran,&(ee->posRepones[1]));
			SDL_BlitSurface(ee->reponses[2],NULL,ecran,&(ee->posRepones[3]));
			SDL_BlitSurface(ee->reponses[3],NULL,ecran,&(ee->posRepones[4]));
			break;
		}
		case 3:
		{
			SDL_BlitSurface(ee->reponses[1],NULL,ecran,&(ee->posRepones[1]));
			SDL_BlitSurface(ee->reponses[2],NULL,ecran,&(ee->posRepones[2]));
			SDL_BlitSurface(ee->reponses[3],NULL,ecran,&(ee->posRepones[4]));
			break;
		}
		case 4:
		{
			SDL_BlitSurface(ee->reponses[1],NULL,ecran,&(ee->posRepones[1]));
			SDL_BlitSurface(ee->reponses[2],NULL,ecran,&(ee->posRepones[2]));
			SDL_BlitSurface(ee->reponses[3],NULL,ecran,&(ee->posRepones[3]));
			break;
		}
	}
	

	SDL_BlitSurface(ee->reponses[4],NULL,ecran,&(ee->posRepones[ee->positionVraiReponse]));//la vrai reponse


	SDL_BlitSurface(ee->question,NULL,ecran,&(ee->posQuestion));
	SDL_Flip(ecran);
}

int Verify_Enigmee(Enigme *ee,int *Game,SDL_Surface *ecran)
{
      Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);  
     Mix_Chunk* button,*win1, *lose1; 
     win1=Mix_LoadWAV("win.wav");
     lose1=Mix_LoadWAV("fail.wav");
	SDL_Rect position={0,0};
	if(ee->positionVraiReponse==ee->image_courrante)
	{
		(*Game)=1;
                 
		SDL_BlitSurface(ee->win,NULL,ecran,&position);
		SDL_Flip(ecran);
                 Mix_PlayChannel(1,win1,0);
		SDL_Delay(1000);
		return 0;//win
	}
	else
	{
		(*Game)=0;
		SDL_BlitSurface(ee->lost,NULL,ecran,&position);
		SDL_Flip(ecran);
                Mix_PlayChannel(1,lose1,0);
		SDL_Delay(1000);
		return 0;//lost
	}
}

int Play_Enigmee(Enigme *ee,SDL_Surface *ecran,int *Game)
{
tempss temp; 
SDL_Color rouge = {255,255,255};
temp=initialiser_temp (temp);
	while(1)
	{
		Display_Enigmee(ee,ecran);//affichage
temp.temp=TTF_RenderText_Blended(temp.police,temp.chaine,rouge);

temp.tempactuel=SDL_GetTicks();

if (temp.tempactuel- temp.tempprecedent >1000  )
{
temp.seconde1++;
temp.tempprecedent= temp.tempactuel;

}
if (temp.seconde1>9)
{
	temp.seconde1=0;
	temp.seconde2++;
}
if (temp.seconde2>=6)
{
	temp.seconde2=0;
	temp.minute1++;
}
if (temp.minute1>=9)
{
	temp.minute1=0;
	temp.minute2++;
}
if (temp.minute2>=6)
{
	temp.minute2=0;
	temp.heur1++;
}
if (temp.heur1>=9)
{
	temp.heur1=0;
	temp.heur2++;
}
sprintf(temp.chaine,"%d %d : %d %d ",temp.minute2,temp.minute1,temp.seconde2,temp.seconde1);
SDL_BlitSurface(temp.temp,NULL,ecran,&temp.position_temp);
SDL_Flip(ecran) ;
	Display_Enigmee(ee,ecran);
	SDL_Event event;
       if (temp.seconde1==9)
return 0;
		while(SDL_PollEvent(&event))
		{
		switch (event.type)
		{ 
			case SDL_KEYDOWN:
			{
				if(event.key.keysym.sym==SDLK_UP)
				{
					ee->image_courrante--;
					if(ee->image_courrante<1)
					{
						ee->image_courrante=4;
					}
				}
				else if(event.key.keysym.sym==SDLK_DOWN)
				{
					ee->image_courrante++;
					if(ee->image_courrante>4)
					{
						ee->image_courrante=1;
					}
		
				}
				else if(event.key.keysym.sym==SDLK_RETURN)
				{
					return Verify_Enigmee(ee,Game,ecran);
				}
				break;
			}
			case SDL_MOUSEMOTION:
			{
				printf("Souris en position %d %d\n",event.motion.x, event.motion.y);
			}
			case SDL_MOUSEBUTTONUP:
			{

				if(event.motion.x>280 && event.motion.x<525 && event.motion.y>255 && event.motion.y<290)
				{
					ee->image_courrante=1;	 
					if (event.button.button == SDL_BUTTON_LEFT)
					{ 
						return Verify_Enigmee(ee,Game,ecran);
					}
					break;
				}
				else if(event.motion.x>280 && event.motion.x<525 && event.motion.y>300 && event.motion.y<335)
				{
					ee->image_courrante=2;			 
					if (event.button.button == SDL_BUTTON_LEFT)
					{ 
						return Verify_Enigmee(ee,Game,ecran);
					}
					break;
				}
				else if(event.motion.x>280 && event.motion.x<525 && event.motion.y>350 && event.motion.y<380)
				{
					ee->image_courrante=3;	
					if (event.button.button == SDL_BUTTON_LEFT)
					{ 
						return Verify_Enigmee(ee,Game,ecran);
					}
					break;
				}
				else if(event.motion.x>280 && event.motion.x<525 && event.motion.y>395 && event.motion.y<425)
				{
					ee->image_courrante=4;	
					if (event.button.button == SDL_BUTTON_LEFT)
					{ 
						return Verify_Enigmee(ee,Game,ecran);
					}
					break;
				}
				break;
			}
			case SDL_QUIT:
			{	
				return 0;
			}
		}}
	}printf("sortie");
}

//************************************************enigme3****************************************************
void Init_Enigmeee(Enigme *eee, char *f1 , char *f2 ,char *f3)
{
	eee->background[0]=IMG_Load("fond23.png");
	eee->background[1]=IMG_Load("enigmes3.png");

	eee->win=IMG_Load("youWin1.png");
   	eee->lost=IMG_Load("gameOver.png");

        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);  
        Mix_Music *music ;
        music=Mix_LoadMUS("game1.mp3");
        Mix_PlayMusic(music,-1);
	for(int i=1;i<5;i++)
	{
		char str[30];
		sprintf(str,"%dttt.png",i);
		eee->boutons[i]=IMG_Load(str);
	}

	srand(time(NULL));
	eee->choix_question=rand()%4;

	while(eee->choix_question==0){
		srand(time(NULL));
		eee->choix_question=rand()%4;
	}

	SDL_Color couleurNoire={0,0,0};
	TTF_Font *police;
	TTF_Init();
	police = TTF_OpenFont("font.ttf", 20);

	char question[150];
	FILE *fichier;
    fichier=fopen(f1, "r");
    int i=1,boucle=1;
    if(fichier!=NULL)
    {
    	while(fgets((question),150,fichier)!=NULL && boucle==1)
    	{
    		if(eee->choix_question==i)
    		{
    			eee->question = TTF_RenderText_Blended (police,question,couleurNoire);
    			boucle=0;//en quit le boucle while
    		}
    		else{
    			i++;
    		}
    		
    	} 	
    	fclose(fichier);
    }
    

    FILE *fic;
    fic=fopen(f2, "r");
    int min,max;
    switch(eee->choix_question)
    {
    	case 1:
    	{
    		min=1;
    		max=3;
    		break;
    	}
    	case 2:
    	{
    		min=4;
    		max=6;
    		break;
    	}
    	case 3:
    	{
    		min=7;
    		max=9;
    		break;
    	}
    }
    int j=1;
    if(fic!=NULL)
    {
    	char reponses[150];
    	while(fgets((reponses),15,fic)!=NULL && j<=max)
    	{	
    		if(j>min || j==min)
    		{
    			eee->reponses[j-min+1]= TTF_RenderText_Blended (police,reponses,couleurNoire);
    			printf("%s\n",reponses);
    		}
    		j++;
    		
    	}
    	fclose(fic);
    }
    
    printf("%d\n",eee->choix_question);

    FILE *f;
    f=fopen(f3, "r");
    char vraiReponse[150];
    int k=1,boucle1=1;
    if(f!=NULL)
    {
    	while(fgets((vraiReponse),15,f)!=NULL && boucle1==1)
    	{
    		if(eee->choix_question==k)
    		{
    			eee->reponses[4]= TTF_RenderText_Blended (police,vraiReponse,couleurNoire);
    			
    			boucle1=0;//en quit le boucle while
    		}
    		else{
    			k++;
    		}
    		
    	} 	
    	fclose(f);
    }
    

    
    eee->posRepones[1].x=809;
	eee->posRepones[1].y=471;
	eee->posRepones[2].x=809;
	eee->posRepones[2].y=564;
	eee->posRepones[3].x=809;
	eee->posRepones[3].y=676;
	eee->posRepones[4].x=809;
	eee->posRepones[4].y=783;

	eee->posQuestion.x=709;
	eee->posQuestion.y=325;

	eee->image_courrante=1;


	srand(time(NULL));
	eee->positionVraiReponse=rand()%5;

	while(eee->positionVraiReponse==0){
		srand(time(NULL));
		eee->positionVraiReponse=rand()%5;
	}

}


void Display_Enigmeee(Enigme *eee,SDL_Surface *ecran)
{
	SDL_Rect position;
	position.x = 0;
	position.y = 0;
	SDL_BlitSurface(eee->background[0],NULL,ecran,NULL);
	SDL_BlitSurface(eee->background[1],NULL,ecran,&position);

	SDL_BlitSurface(eee->boutons[eee->image_courrante],NULL,ecran,&position);

	
	switch(eee->positionVraiReponse)
	{
		case 1:
		{
			SDL_BlitSurface(eee->reponses[1],NULL,ecran,&(eee->posRepones[2]));
			SDL_BlitSurface(eee->reponses[2],NULL,ecran,&(eee->posRepones[3]));
			SDL_BlitSurface(eee->reponses[3],NULL,ecran,&(eee->posRepones[4]));
			break;
		}
		case 2:
		{
			SDL_BlitSurface(eee->reponses[1],NULL,ecran,&(eee->posRepones[1]));
			SDL_BlitSurface(eee->reponses[2],NULL,ecran,&(eee->posRepones[3]));
			SDL_BlitSurface(eee->reponses[3],NULL,ecran,&(eee->posRepones[4]));
			break;
		}
		case 3:
		{
			SDL_BlitSurface(eee->reponses[1],NULL,ecran,&(eee->posRepones[1]));
			SDL_BlitSurface(eee->reponses[2],NULL,ecran,&(eee->posRepones[2]));
			SDL_BlitSurface(eee->reponses[3],NULL,ecran,&(eee->posRepones[4]));
			break;
		}
		case 4:
		{
			SDL_BlitSurface(eee->reponses[1],NULL,ecran,&(eee->posRepones[1]));
			SDL_BlitSurface(eee->reponses[2],NULL,ecran,&(eee->posRepones[2]));
			SDL_BlitSurface(eee->reponses[3],NULL,ecran,&(eee->posRepones[3]));
			break;
		}
	}
	

	SDL_BlitSurface(eee->reponses[4],NULL,ecran,&(eee->posRepones[eee->positionVraiReponse]));//la vrai reponse


	SDL_BlitSurface(eee->question,NULL,ecran,&(eee->posQuestion));
	SDL_Flip(ecran);
}

int Verify_Enigmeee(Enigme *eee,int *Game,SDL_Surface *ecran)
{
      Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);  
     Mix_Chunk* button,*win1, *lose1; 
     win1=Mix_LoadWAV("win.wav");
     lose1=Mix_LoadWAV("fail.wav");
	SDL_Rect position={0,0};
	if(eee->positionVraiReponse==eee->image_courrante)
	{
		(*Game)=1;
                 
		SDL_BlitSurface(eee->win,NULL,ecran,&position);
		SDL_Flip(ecran);
                 Mix_PlayChannel(1,win1,0);
		SDL_Delay(1000);
		return 0;//win
	}
	else
	{
		(*Game)=0;
		SDL_BlitSurface(eee->lost,NULL,ecran,&position);
		SDL_Flip(ecran);
                Mix_PlayChannel(1,lose1,0);
		SDL_Delay(1000);
		return 0;//lost
	}
}

int Play_Enigmeee(Enigme *eee,SDL_Surface *ecran,int *Game)
{
	tempss temp; 
SDL_Color rouge = {255,255,255};
temp=initialiser_temp (temp);
	while(1)
	{
		Display_Enigmeee(eee,ecran);//affichage
temp.temp=TTF_RenderText_Blended(temp.police,temp.chaine,rouge);

temp.tempactuel=SDL_GetTicks();

if (temp.tempactuel- temp.tempprecedent >1000  )
{
temp.seconde1++;
temp.tempprecedent= temp.tempactuel;

}
if (temp.seconde1>9)
{
	temp.seconde1=0;
	temp.seconde2++;
}
if (temp.seconde2>=6)
{
	temp.seconde2=0;
	temp.minute1++;
}
if (temp.minute1>=9)
{
	temp.minute1=0;
	temp.minute2++;
}
if (temp.minute2>=6)
{
	temp.minute2=0;
	temp.heur1++;
}
if (temp.heur1>=9)
{
	temp.heur1=0;
	temp.heur2++;
}
sprintf(temp.chaine,"%d %d : %d %d ",temp.minute2,temp.minute1,temp.seconde2,temp.seconde1);
SDL_BlitSurface(temp.temp,NULL,ecran,&temp.position_temp);
SDL_Flip(ecran) ;
	Display_Enigmeee(eee,ecran);
	SDL_Event event;
       if (temp.seconde1==9)
return 0;
		while(SDL_PollEvent(&event))
		{
		switch (event.type)
		{ 
			case SDL_KEYDOWN:
			{
				if(event.key.keysym.sym==SDLK_UP)
				{
					eee->image_courrante--;
					if(eee->image_courrante<1)
					{
						eee->image_courrante=4;
					}
				}
				else if(event.key.keysym.sym==SDLK_DOWN)
				{
					eee->image_courrante++;
					if(eee->image_courrante>4)
					{
						eee->image_courrante=1;
					}
		
				}
				else if(event.key.keysym.sym==SDLK_RETURN)
				{
					return Verify_Enigmeee(eee,Game,ecran);
				}
				break;
			}
			case SDL_MOUSEMOTION:
			{
				printf("Souris en position %d %d\n",event.motion.x, event.motion.y);
			}
			case SDL_MOUSEBUTTONUP:
			{

				if(event.motion.x>280 && event.motion.x<525 && event.motion.y>255 && event.motion.y<290)
				{
					eee->image_courrante=1;	 
					if (event.button.button == SDL_BUTTON_LEFT)
					{ 
						return Verify_Enigmeee(eee,Game,ecran);
					}
					break;
				}
				else if(event.motion.x>280 && event.motion.x<525 && event.motion.y>300 && event.motion.y<335)
				{
					eee->image_courrante=2;			 
					if (event.button.button == SDL_BUTTON_LEFT)
					{ 
						return Verify_Enigmee(eee,Game,ecran);
					}
					break;
				}
				else if(event.motion.x>280 && event.motion.x<525 && event.motion.y>350 && event.motion.y<380)
				{
					eee->image_courrante=3;	
					if (event.button.button == SDL_BUTTON_LEFT)
					{ 
						return Verify_Enigmeee(eee,Game,ecran);
					}
					break;
				}
				else if(event.motion.x>280 && event.motion.x<525 && event.motion.y>395 && event.motion.y<425)
				{
					eee->image_courrante=4;	
					if (event.button.button == SDL_BUTTON_LEFT)
					{ 
						return Verify_Enigmeee(eee,Game,ecran);
					}
					break;
				}
				break;
			}
			case SDL_QUIT:
			{	
				return 0;
			}
		}}
	}printf("sortie");
}




