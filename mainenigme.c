#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"

int main()
{
	
	SDL_Surface * ecran=NULL;
	ecran = SDL_SetVideoMode(1000,1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	int continuer=1,winn=0;
	SDL_Event event;
	char *nomfichier[100];
	SDL_Surface *win;
	SDL_Surface *lost;
	SDL_Rect pos={160,330}; 
	enigme e;
	InitEnigme(&e,&nomfichier[100]);
	win=IMG_Load("youwin.png");
	lost=IMG_Load("youlost.png");
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024==-1))
        printf ("error %s",Mix_GetError());
        
	 e.music=Mix_LoadMUS("music.mp3"); 
	 Mix_PlayMusic(e.music,-1);


	while(continuer){	
 		animer(&e);
		afficherEnigme(e,ecran);
	
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type)
			{
				case SDL_QUIT:
				{	
					free_Surface_enigme(e);

				}
				case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{	
					case SDLK_a:
					e.reponsejoueur=1;
					break ; 
					
					case SDLK_b:
					e.reponsejoueur=2;
					break ; 
					
					case SDLK_c:
					e.reponsejoueur=3;
					break ; 
					
					case SDLK_RETURN:
					verifierenigme(&e,ecran); 
						return 0;
					break ; 

				}break;
				case SDL_MOUSEMOTION:
				{
					//printf("Souris en position %d %d\n",event.motion.x, event.motion.y);
					printf(".");
				}
			case SDL_MOUSEBUTTONUP:
				{
					if((event.motion.x>375 && event.motion.x<615)&&(event.motion.y>400 && event.motion.y<490))
					{
						e.reponsejoueur=1;
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							if(winn==1){
							printf("You win\n");
							SDL_BlitSurface(win, NULL, ecran,&pos);
							SDL_Flip(ecran);
							
							}else{	
							SDL_BlitSurface(lost, NULL, ecran, &pos);
							SDL_Flip(ecran);
							printf("You lost\n");	
							}
							SDL_Delay(2000);
							return 0;
						} 	 
					}
					else if((event.motion.x>178 && event.motion.x<417)&&(event.motion.y>470 && event.motion.y<560))
					{
						e.reponsejoueur=2;
						if (event.button.button == SDL_BUTTON_LEFT)
						{	
							if(winn==1){
							printf("You win\n");
							SDL_BlitSurface(win, NULL, ecran,&pos);
							SDL_Flip(ecran);
							
							}else{
							SDL_BlitSurface(lost, NULL, ecran, &pos);
							SDL_Flip(ecran);
							printf("You lost\n");							
							}
							SDL_Delay(2000);
							return 0;
						} 
					}
					else if((event.motion.x>566 && event.motion.x<806)&&(event.motion.y>470 && event.motion.y<560))
					{
						e.reponsejoueur=3;
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							if(winn==1){
							printf("You win\n");
							SDL_BlitSurface(win, NULL, ecran,&pos);
							SDL_Flip(ecran);
							
							}else{
							SDL_BlitSurface(lost, NULL, ecran, &pos);
							SDL_Flip(ecran);
							printf("You lost\n");						
							}
							SDL_Delay(2000); 
							return 0;
						} 					
					}
				}
				break;
			}
		}
		 
		if(e.reponsejuste==e.reponsejoueur)
		{
		winn=1;
		}
		else
		{
		winn=0;
		}
		}
		Mix_FreeMusic(e.music);		
}


