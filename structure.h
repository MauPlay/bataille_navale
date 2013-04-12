#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#include <SDL.h>
#include <SDL/SDL_ttf.h>

typedef struct{
    int IndexXGrille;
    int IndexYGrille;
}TIndexGrille;
typedef struct{
    bool horizontalvertical;
    int nombrecases;
    int posX;
    int posY;
}TBateau;
void affichergrille(SDL_Surface *affichage, int x, int y);
void ecriretexte(SDL_Surface *affichage, char phrase[200], TTF_Font *police_ecrire, SDL_Color couleur_police, int x, int y);
int casechoisie(SDL_Surface *affichage, int eventx, int eventy, int IndexX, int IndexY, int *pointeurX, int *pointeurY);
void ligneVerticale(SDL_Surface *affichage, int x, int y, int h, Uint32 coul);
void ligneHorizontale(SDL_Surface *affichage, int x, int y, int w, Uint32 coul);
#endif // STRUCTURE_H_INCLUDED
