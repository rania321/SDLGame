#ifndef ENIGMETF_H_INCLUDED
#define ENIGMETF_H_INCLUDED

#include <stdio.h> 
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

typedef struct{ 

	SDL_Surface *background; 
	SDL_Surface *question;
	SDL_Surface *reponses[4]; 
	SDL_Surface *button; 
	SDL_Surface *button1;

	int reponsejoueur;
	SDL_Rect pos_question; 
	SDL_Rect pos_reponse1;
	SDL_Rect pos_reponse2; 
	SDL_Rect pos_reponse3; 
	int num_question;
	
	SDL_Rect pos_reponse1txt; 
	SDL_Rect pos_reponse2txt; 
	SDL_Rect pos_reponse3txt; 
	int vrai_reponse; 
	int reponsejuste;  
	TTF_Font *police; 
	TTF_Font *police1;
	Mix_Music *music;
		
	SDL_Surface *image;  
	SDL_Rect pos_image_water;
	
	SDL_Rect water1;
	
	
	int numwater;

}enigme;

/*typedef struct 
{
	SDL_Surface *backg;
	SDL_Rect posbackg;
}background;

typedef struct
{
  	SDL_Surface *image_p;
  	SDL_Rect pos_perso;
}personne;*/

void InitEnigme(enigme *e,char *nomfichier[]);
void afficherEnigme(enigme e,SDL_Surface *ecran);
void displayWater(enigme e,SDL_Surface *ecran);
void verifierenigme(enigme *e,SDL_Surface*ecran);
void animer(enigme *e);
void free_Surface_enigme(enigme e);
/*void initialiser_background(background *back);
void afficher_background(SDL_Surface *screen,background back);
void initialiserperso(personne *p);
void deplacer_perso(personne *p,SDL_Event event);
void afficher_perso(SDL_Surface *screen,personne p);
void free_perso(personne p);
void sauvegarder (personne p, background b, char * nomfichier);
int charger (personne *p, background *b , char * nomfichier);*/

#endif
