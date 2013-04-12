#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <conio.h>
#include <SDL_endian.h> /* Used for the endian-dependent 24 bpp mode */

#include "structure.h"
#include "constantes.h"

int main ( int argc, char** argv )
{
    char var[100]; // cette variable contiendras la chaine "Case : XX"
    int posX=0, posY=0; // Variables retournées par casechoisie() donnant les coordonnées
    bool jouer = true; // Cette booléenne sers à définir quand le joueur peut jouer et à quel moment il ne peut rien faire
    bool placement = true; // Le joueur peut placer ces bateaux
    bool done = false; // Tant que cette booléenne reste à false, la partie continue

    SDL_Surface *screen = NULL;
    TTF_Font *police_wood = NULL, *police_arial = NULL;

    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ){printf( "Unable to init SDL: %s\n", SDL_GetError() );return 1;}
    if ( TTF_Init() == -1 ){printf( "Erreur d'initialisation de TTF_Init : %s\n",TTF_GetError());return 1;}

    SDL_WM_SetCaption("Bataille Navale", NULL); // Définition du titre
    screen = SDL_SetVideoMode(LargeurFenetre, HauteurFenetre, 32, SDL_SWSURFACE|SDL_DOUBLEBUF); // initialisation de la fenêtre
    if ( !screen ){printf("Unable to set 1248x680 video: %s\n", SDL_GetError());return 1;} // en cas d'erreur

    police_wood = TTF_OpenFont("aw.ttf", 65);
    police_arial = TTF_OpenFont("arial.ttf", 40);
    SDL_Color police_couleur_noir = {0, 0, 0}; // Définition de la variable police_couleur_noir permettant d'écrire du texte en noir

    TIndexGrille grilleG = {screen->w/2-510, 70}; // structure positionnant la grille de gauche
    TIndexGrille grilleD = {screen->w/2+70, 70};  // structure positionnant la grille de droite
    TBateau cuirasse1 = {0, 4, 1, 8};

    while (!done)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                {
                    done = true;
                    break;
                }
            case SDL_KEYDOWN:
                {
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        done = true;
                    }
                    break;
                }
            case SDL_MOUSEBUTTONUP:
                {
                    if  (event.button.button==SDL_BUTTON_LEFT) // Si l'évênement est un click gauche
                    {
                        if (placement==true)
                        {
                            casechoisie(screen, event.button.x, event.button.y, grilleD.IndexXGrille, grilleD.IndexYGrille, &posX, &posY);
                        } // si le joueur peut placer on détermine les coordonées du click
                        if (jouer==true)
                        {
                            casechoisie(screen, event.button.x, event.button.y, grilleG.IndexXGrille, grilleG.IndexYGrille, &posX, &posY);
                        } // si le joueur peut jouer, on fait pareil
                    }
                }
            }
        }
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 255, 255, 255)); // on vide l'écran

        // DRAWING STARTS HERE

        affichergrille(screen, grilleD.IndexXGrille, grilleD.IndexYGrille); // on charge les grilles
        affichergrille(screen, grilleG.IndexXGrille, grilleG.IndexYGrille);
        sprintf(var, "Case : %c%d", posX+64, posY); // On utilise sprintf pour créer une chaine de caractere var contenant le message de la case, var est mis à jours en fonction des variables de coordonnées
        ecriretexte(screen, var, police_arial, police_couleur_noir, 10, 10); // on affiche la chaine var

        // DRAWING ENDS HERE

        SDL_Flip(screen);
    }

    TTF_CloseFont(police_arial);
    TTF_CloseFont(police_wood);
    TTF_Quit();
    SDL_Quit();
    printf("Exited cleanly\n");
    return 0;
}
