#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "Liste_case.h"
#include "API_Grille.h"




typedef struct{
	int dim;/* dimension de la grille */
	int nbcl;/* nombre de couleurs */
	Liste  Lzsg;/* Liste des cases de la zone Zsg */
	Liste *B;/* Tableau de listes de cases de la bordure*/
	int **App;/* Tableau a double entree des appartenances */
} S_Zsg;
S_Zsg * initZone(int dim,int nbcl);

void ajoute_Zsg(S_Zsg * Z,int i,int j);

void ajoute_Bordure(S_Zsg * Z,int i,int j,int cl);

int appartient_Zsg(S_Zsg * Z,int i, int j);

int appartient_Bordure(S_Zsg * Z,int i , int j,int cl);

Liste * trouve_zone_Zsg(int **M,int dim, int i,int j,int cl);

int agrandit_Zsg(int **M, S_Zsg * Z, int cl, int k, int l);

int strequence_aleatoire_rapide(int ** M, Grille *G,S_Zsg * Z);

int fini(int dim,int **App);

