#include <stdio.h>
#include <stdlib.h>
#include "exo1.h"


int appartient_liste(Liste L, int i, int j){//fonction pour simplifier les autres (surtout imperative)
	while (L){
		if ((L->i == i) && (L->j == j)){
			return 1;
		}
		L = L->suiv;
	}
	return 0;
}

void afficher_liste (Liste L){//vérifier ce qu'il y a dans la liste
	printf("liste:");
	while (L){
		printf ("case: i:%d j:%d\n", L->i, L->j);
		L = L->suiv;
	}
}

void trouve_zone_rec(int **M, int dim, int i, int j, int *taille, Liste *L){
	if (!appartient_liste(*L, i, j)){
		ajoute_en_tete(L, i, j);
		(*taille)++;
	}//on teste d'abord si la case choisie n'appartient pas déja a la zone et ensuite les cases autour
	
	if((i>0) && (M[i-1][j]== M[i][j]) && (!appartient_liste(*L, i-1, j))){
		trouve_zone_rec(M, dim ,i-1 ,j ,taille, L);
	}//tes pour la casecase au dessus	
	
	if((i+1<dim) && (M[i+1][j]== M[i][j]) && (!appartient_liste(*L, i+1, j))){
		trouve_zone_rec(M, dim, i+1, j, taille, L);
	}//test pour la case en dessous
	
	if((j>0) && (M[i][j-1]== M[i][j]) && (!appartient_liste(*L, i, j-1))){
		trouve_zone_rec(M, dim, i, j-1, taille, L);	
	}//test pour la case a gauche
	
	if((j+1<dim) && (M[i][j+1]== M[i][j]) && (!appartient_liste(*L, i, j+1))){
		trouve_zone_rec(M, dim, i, j+1, taille, L);	
	}//test pour la case a droite
}

int sequence_aleatoire_rec(int **M, Grille *G, int dim, int nbcl, int aff,int choix)
{
	int cpt = 0;
	if(nbcl<=1)return 1;
	int couleurAlea = rand()%(G->nbcl);
	while (couleurAlea == M[0][0]){
		couleurAlea = rand()%(G->nbcl);//si on tombe sur la meme couleur que la case de depart on relance 
		
	}
	Liste *L = malloc(sizeof(Liste));
	init_liste(L);
	int taille=0;
	if (choix==1){
		trouve_zone_rec(M, dim, 0, 0, &taille, L);//
	}
	else{trouve_zone_imp(M,dim,0,0,&taille,L);}
	
	
	Liste Lcopie = *L;//j'ai mis L dans une autre variable car cela ne marchait pas en l'utilisant directement dans les instructions qui suivent
	afficher_liste(Lcopie);
	
	while(Lcopie){
		M[Lcopie->i][Lcopie->j] = couleurAlea;
		Grille_attribue_couleur_case(G, Lcopie->i, Lcopie->j, M[Lcopie->i][Lcopie->j]);
		Lcopie = Lcopie->suiv;//on change la couleur des cases de la liste actuelle
	}
	if (taille != dim*dim){
		 aff = 1; //si on est pas encore arrivé a colorier toutes les cases, aff=1 et on redessine la grille
	
		Grille_redessine_Grille();
	
		cpt = 1 + sequence_aleatoire_rec(M, G, dim, nbcl, aff,choix);//on relance sequence_aleatoire tant que la grille n'est pas remplie avec une seule couleur et on incrémente cpt
		
	} else {
		return cpt;
	}
}

void trouve_zone_imp(int **M, int dim, int i, int j, int *taille, Liste *L)
{
	if (!appartient_liste(*L, i, j)){
		(*taille)++;
		ajoute_en_tete(L,i,j);//on empile le premier élément
	}
	int k, l;
	for (k = i; k<dim; k++){
		for (l = j; l<dim; l++){
			if (M[k][l] == M[i][j]){
				if (((k>0) && (appartient_liste(*L, k-1,l)))  ||
					 ((l>0) && (appartient_liste(*L, k,l-1))) ||
					 ((k+1<dim) && (appartient_liste(*L, k+1,l))) ||
					  ((l+1<dim) && (appartient_liste(*L, k, l+1)))){//on fait ici tous les tests en un coup a chaque fois
					if (!appartient_liste(*L, k, l)){
						(*taille)++;
						ajoute_en_tete(L, k, l);//on empile
					}
				}
			}
		}
	}
}


