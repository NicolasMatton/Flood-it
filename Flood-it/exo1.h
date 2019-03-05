#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "Liste_case.h"
#include "API_Grille.h"
int dans_la_liste (Liste L, int i, int j);

void print_liste (Liste L);

void trouve_zone_rec(int **M, int dim, int i, int j, int *taille, Liste *L);

int sequence_aleatoire_rec(int **M, Grille *G, int dim, int nbcl, int aff,int choix);

void trouve_zone_imp(int **M, int dim, int i, int j, int *taille, Liste *L);
