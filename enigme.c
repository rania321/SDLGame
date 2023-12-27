#include "enigme.h"


void InitEnigme(enigme *e,char *nomfichier[]){   
 
	nomfichier[100];


	FILE *fquestion=NULL;
	FILE *freponse=NULL;
	FILE *fvraireponse=NULL;
	
	e->reponsejoueur=0;
	e->background= IMG_Load("background.png");
	e->button= IMG_Load("button.png");
	e->button1= IMG_Load("button1.png");

	TTF_Init();


	SDL_Color couleur = {0,0,0}; 

	(*e).police = TTF_OpenFont("arial.ttf", 25);
	e->police1 = TTF_OpenFont("arial.ttf", 20);
	  
	char question[50];
	
	srand(time(NULL)); 
	e->num_question=rand()%4;   

	while(e->num_question==0){
		srand(time(NULL));
		e->num_question=rand()%4;
	}
	 
	sprintf(*nomfichier,"questions.txt"); 

	fquestion=fopen(*nomfichier,"r+");
	if(fquestion!=NULL){

		int test=1;
		while (fgets(question, 50, fquestion) &&(test!=e->num_question)){ 
			test++;
		}
		
		fclose(fquestion);
	}
	
	char reponse[20];

	int min,max;
    switch(e->num_question)
    {
    	case 1:
    	{
    		min=0;
    		max=2;
    		break;
    	}
    	case 2:
    	{
    		min=3;
    		max=5;
    		break;
    	}
    	case 3:
    	{
    		min=6;
    		max=8;
    		break;
    	}
    }


	freponse=fopen("reponses.txt","r+");
	if(freponse!=NULL){

		int test=0;
		while (fgets((reponse), 15, freponse) &&(test<max)){
			
			if(test>=min){
				e->reponses[test-min]=TTF_RenderText_Blended(e->police1, reponse, couleur);
			}
			test++;
		}	
		
		fclose(freponse);
	}
	
	fvraireponse=fopen("vraireponses.txt","r+");
	if(fvraireponse!=NULL){
		
		int test=1;
		while (fgets((reponse), 15, fvraireponse)){
			
			if(test==e->num_question){ 
				printf("%s\n",reponse);
				e->reponses[2]=TTF_RenderText_Blended(e->police1, reponse, couleur); 
			}
			test++;
		}
		fclose(freponse);
	}

	srand(time(NULL));
	e->reponsejuste=rand()%4; 

	while(e->reponsejuste==0){
		srand(time(NULL));
		e->reponsejuste=rand()%4;
	}
	printf("%d\n",e->reponsejuste);

	e->question = TTF_RenderText_Blended(e->police, question, couleur);

	e->pos_question.x=250;
	e->pos_question.y=270;
 
	e->pos_reponse1.x=375;
	e->pos_reponse1.y=400;


	e->pos_reponse2.x=177;
	e->pos_reponse2.y=470;

	e->pos_reponse3.x=566;
	e->pos_reponse3.y=470;

	e->pos_reponse1txt.x=e->pos_reponse1.x+50;
	e->pos_reponse1txt.y=400+30;

	e->pos_reponse2txt.x=177+50;
	e->pos_reponse2txt.y=470+30;

	e->pos_reponse3txt.x=566+50;
	e->pos_reponse3txt.y=470+30;
	
	
	(*e).image=IMG_Load("water.png");  

	e->pos_image_water.x=860;
	e->pos_image_water.y=120;
	
	e->water1.w=50;
	e->water1.h=81;
	e->water1.x=0;
	e->water1.y=0;

	e->numwater=0;

 

}

void afficherEnigme(enigme e,SDL_Surface *ecran){

	
		
	SDL_BlitSurface(e.background, NULL, ecran, NULL);
	SDL_Flip(ecran);
	displayWater(e,ecran);
	SDL_BlitSurface(e.question, NULL, ecran, &e.pos_question);
	SDL_Flip(ecran);
	

	switch(e.reponsejuste){
		case 1:{

			switch(e.reponsejoueur){
			case 1:
			{
				SDL_BlitSurface(e.button1, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button1, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button1, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}	
			break;
		}
		case 2:{
			switch(e.reponsejoueur){
			case 1:
			{
				SDL_BlitSurface(e.button1, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button1, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button1, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}
			break;
		}
		case 3:{
			switch(e.reponsejoueur){
			case 1:
			{
				SDL_BlitSurface(e.button1, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:                       
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button1, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button1, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}

			break;
		}
	}
	
	SDL_Delay(100);
}

void verifierenigme(enigme *e,SDL_Surface*ecran){

	SDL_Rect pos={160,330}; 
	if(e->reponsejuste==e->reponsejoueur)
	{
		printf("You win\n");
		SDL_Surface *win;
		win=IMG_Load("youwin.png");
		SDL_BlitSurface(win, NULL, ecran,&pos);
		SDL_Flip(ecran);

	}
	else
	{
		SDL_Surface *lost;
		lost=IMG_Load("youlost.png");
		SDL_BlitSurface(lost, NULL, ecran, &pos);
		SDL_Flip(ecran);
		printf("You lost\n");
	}
	SDL_Delay(2000);

}
void displayWater(enigme e,SDL_Surface *ecran){
			
 		SDL_BlitSurface(e.image,&(e.water1), ecran, &e.pos_image_water);
}
void animer(enigme *e){
		 	
	if (e->numwater >=0 && e->numwater <8) {
	e->water1.x=e->numwater * e->water1.w;
	e->numwater++;
	}
	
	if ( e->numwater == 8) {
	e->water1.x=e->numwater * e->water1.w;
	e->numwater=0;
	}

	 
}

/*
void initialiserperso(personne *p)
{	
	p->image_p=IMG_Load("pers.bmp");
	  // p->pos_perso.x=0;
	 //p->pos_perso.y=200;
	
}

void afficher_perso(SDL_Surface *screen,personne p)
{	
	SDL_BlitSurface(p.image_p,NULL,screen,&p.pos_perso);
}

void deplacer_perso(personne *p,SDL_Event event)
{	
	SDL_PollEvent(&event);
         switch(event.type)
            {
                case SDL_KEYDOWN:
                       switch(event.key.keysym.sym)
                        {
                        
                        case SDLK_UP:
                            p->pos_perso.y=p->pos_perso.y-10;
                            break;
                        case SDLK_DOWN:
                            p->pos_perso.y=p->pos_perso.y+10;
                            break;
                        case SDLK_RIGHT:
                            p->pos_perso.x=p->pos_perso.x+10;
                            break;
                        case SDLK_LEFT:
                            p->pos_perso.x=p->pos_perso.x-10;
                            break;
                        }
                 break;
             }
}
void free_perso(personne p)
{
	SDL_FreeSurface(p.image_p);
}

void initialiser_background(background *back)
{
	back->backg=SDL_LoadBMP("background.bmp");
	back->posbackg.x=0;
	back->posbackg.y=0;
	
}
void afficher_background(SDL_Surface *screen,background back)
{	
	
	 SDL_BlitSurface(back.backg,NULL,screen,&back.posbackg);
	 
}


void sauvegarder (personne p, background b, char * nomfichier)
{	
	FILE *f;
   
	f=fopen(nomfichier, "w");
	fprintf(f, "%d %d\n", p.pos_perso.x, p.pos_perso.y);
	fclose(f);
}


int charger (personne *p, background *b , char * nomfichier)
{
	
	FILE *f=fopen(nomfichier,"r");
	if(f==NULL)
	{
	     printf("Erreur !");
	}
	else
	{	int x=0,y=0;
		printf("loading");
		fscanf(f,"%d %d\n",&p->pos_perso.x,&p->pos_perso.y);
		printf("%d %d",x,y);
	}
	fclose(f);
}*/

void free_Surface_enigme(enigme e){

	SDL_FreeSurface(e.background);
	SDL_FreeSurface(e.question);
	SDL_FreeSurface(e.reponses[0]);
	SDL_FreeSurface(e.reponses[1]);
	SDL_FreeSurface(e.reponses[2]);
	SDL_FreeSurface(e.button);
	SDL_FreeSurface(e.button1);
}

