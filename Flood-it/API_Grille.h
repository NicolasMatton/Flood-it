#ifndef __API_GRILLE__
#define __API_GRILLE__

#include <SDL/SDL.h>
#include <stdlib.h>

/* Structure necessaire aux fonctions d affichage*/
typedef struct grille{

  int dim;          /* Dimension de la grille */
  int nbcl;         /* Nombre de couleurs */
  int taille_pixel; /* Taille de la grille a l ecran */

  int cas_aff;      /* Dit si une case est limite a un pixel */
                    /* 0 s il y a trop de cases a afficher / 1 sinon */
  int taille_case;  /* Taille d une case a l ecran */
  int modulo;       /* Saut d affichache en cas de nombre de cases important */

  Uint32 *T_coul;   /* Tableau de codage des couleurs */

} Grille;

/* Fonction d initialisation de la Grille */
/* 
Entree:
   dim : dimension de la grille
   nbcl   : nombre de couleurs
   taille_pixel : taille d affichage de la grille en pixel
            Doit etre inferieur a la resolution de l ecran
   G : adresse d'un pointeur sur l element Grille

Sortie:
   G: allocation et affectation des elements necessaires
      a l affichage d une grille de jeu */
void Grille_init(int dim, int nbcl, int taille_pixel, Grille **G);

/* Fonction permettant l'ouverture de la fenetre graphique
   contenant une grille ainsi que l'affichage total de la grille*/
void Grille_ouvre_fenetre(Grille *G);

/* Fonction permettant la fermeture de la fenetre graphique
   contenant une grille */
void Grille_ferme_fenetre();

/* Fonction permettant l affectation d une case a une nouvelle
   couleur */
void Grille_attribue_couleur_case(Grille *G, int i, int j, int c);
 
/* Fonction permettant de redessiner la grille */
void Grille_redessine_Grille();

/* Fonction permettant de mettre en pause le programme en attente
   de la pression d une touche */
void Grille_attente_touche();

/* Liberation memoire d une grille */
void Grille_free(Grille **G);


#endif
