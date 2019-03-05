#ifndef __API_GENE_INSTANCE__
#define __API_GENE_INSTANCE__
#include <stdlib.h>

/* Fonction de generation d'une instance*/
/* Entree:
   dim   : dimension de la grille carree 
   nbcl  : nombre de couleurs demandees
   nivdif: niveau de difficulte entre 0 et 100
           (taille moyenne d une zone mesuree 
            en pourcentage de dim*dim)
   graine: graine de la generation aleatoire
   M     : matrice entiere carree dim*dim DEJA ALLOUEE
           
   Sortie: Affectation de M telle que M[i][j] possede un numero
           de couleur choisi aleatoirement entre 0 et nbcl-1.
           La generation depend du niveau de difficulte choisi*/

void Gene_instance_genere_matrice(int dim, int nbcl, int nivdif, int graine, int **M);


#endif
