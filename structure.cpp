#include "structure.h"
#include "constantes.h"

void affichergrille(SDL_Surface *affichage, int x, int y)
{
    SDL_Surface *grille=NULL;
    SDL_Rect grilleposition;
    grille = SDL_LoadBMP("grille.bmp");
    SDL_SetColorKey(grille, SDL_SRCCOLORKEY, SDL_MapRGB(grille->format, 255, 255, 255));
    grilleposition.x = x;
    grilleposition.y = y;
    SDL_BlitSurface(grille, NULL, affichage, &grilleposition);
    SDL_FreeSurface(grille);
};

void ecriretexte(SDL_Surface *affichage, char phrase[200], TTF_Font *police_ecrire, SDL_Color couleur_police, int x, int y)
{
    SDL_Surface *texte;
    SDL_Rect texteposition;
    texte = TTF_RenderText_Blended(police_ecrire, phrase, couleur_police);
    texteposition.x = x;
    texteposition.y = y;
    SDL_BlitSurface(texte, NULL, affichage, &texteposition);
    SDL_FreeSurface(texte);
};

int casechoisie(SDL_Surface *affichage, int eventx, int eventy, int IndexX, int IndexY, int *pointeurX, int *pointeurY) // on lui indique la position cliquée, ainsi que l'index de la grille (l'index de la premiere grille est le point en haut à gauche de la case A1).
{
    for(int i=1;i<11;i++)
    {
        if (((IndexX+LargeurCase<eventx)&&(eventx<IndexX+LargeurCase*11))&&((IndexY+HauteurCase<eventy)&&(eventy<IndexY+HauteurCase*11)))
        {
            if ((IndexX+i*LargeurCase < eventx) && (eventx < IndexX+LargeurCase+i*LargeurCase))
            {
                *pointeurX = i;
            }
            if ((IndexY+i*HauteurCase < eventy) && (eventy < IndexY+HauteurCase+i*HauteurCase))
            {
                *pointeurY = i;
            }
        }
    }
};

void dessinernavire(SDL_Surface *affichage, TBateau bateau, TIndexGrille grillepos)
{
    SDL_Surface *bateau=NULL;
    SDL_Rect beateaupos;
    bateau = SDL_LoadBMP(bateau.cheminskin);
    beateaupos.x = x;
    beateaupos.y = y;
    SDL_BlitSurface(bateau, NULL, affichage, &beateaupos);
    SDL_FreeSurface(bateau);
};

