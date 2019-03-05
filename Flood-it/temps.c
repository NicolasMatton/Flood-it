#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>
#include "API_Grille.h"
#include "API_Gene_instance.h"
#include "Liste_case.h"
#include "zones.h"
#include "exo1.h"
void simulation_jeu(int dim, int nbcl, int nivdif, int graine, int aff, int mode,float *temps_cpu ){
	clock_t
		temps_initial, // Temps initial en micro-secondes
		temps_final;   // Temps final en micro-secondes
		
	Grille *G;
	
	int **M;
	/* Generation de l'instance */
	
	M=(int **) malloc(sizeof(int*)*dim);
	int i,j;
	for (i=0;i<dim;i++){
		M[i]=(int*) malloc(sizeof(int)*dim);
		if (M[i]==0) 
			printf("Pas assez d'espace mémoire disponible\n");
	}

	Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);

	/* Affichage de la grille */

	Grille_init(dim,nbcl,500,&G);

	Grille_ouvre_fenetre(G);

	for (i=0;i<dim;i++)
		for (j=0;j<dim;j++)
 		Grille_attribue_couleur_case(G,i,j,M[i][j]);
	
	Grille_redessine_Grille();
	
	if(mode==1){
		temps_initial=clock();
		sequence_aleatoire_rec(M, G,dim,G->nbcl,1,1);
		temps_final=clock();
	}
	else if(mode==2){
		temps_initial=clock();
		sequence_aleatoire_rec(M, G,dim,G->nbcl,1,2);
		temps_final=clock();
	}
	else if(mode==3){
		temps_initial=clock();
		S_Zsg * Z=initZone(dim,nbcl);
		strequence_aleatoire_rapide(M,G,Z);
		temps_final=clock();
	}
			
	*temps_cpu=temps_final-temps_initial;

	//Grille_attente_touche();

	Grille_ferme_fenetre();

	Grille_free(&G);

}

void test_couleur(int n){

	FILE *f1=fopen("couleurrec.txt","w");
	FILE *f2=fopen("couleurimp.txt","w");
	FILE *f3=fopen("couleurzsg.txt","w");
	
	int i;
	
	float *temps_cpu=(float *)malloc(sizeof(float));
	printf("TEST COULEUR\n");
	for(i=1;i<=n;i++){
		printf("i=%d\n",i);
		simulation_jeu(20,i,1,1,0,1,temps_cpu);
		fprintf(f1,"%d %f\n",i,*temps_cpu);
		simulation_jeu(20,i,1,1,0,2,temps_cpu);
		fprintf(f2,"%d %f\n",i,*temps_cpu);
		simulation_jeu(20,i,1,1,0,3,temps_cpu);
	
		fprintf(f3,"%d %f\n",i,*temps_cpu);
	}
	printf("\n");
	fclose(f1); 
	fclose(f2); 
	fclose(f3); 	
}

void test_dim(int n){

	FILE *f1=fopen("dimrec.txt","w");
	FILE *f2=fopen("dimimp.txt","w");
	FILE *f3=fopen("dimzsg.txt","w");
	
	int i;
	
	float *temps_cpu=(float *)malloc(sizeof(float));
	printf("TEST DIM\n");
	for(i=1;i<=n;i++){
		printf("i=%d\n",i);
		simulation_jeu(i,5,1,1,0,1,temps_cpu);
		fprintf(f1,"%d %f\n",i,*temps_cpu);
		simulation_jeu(i,5,1,1,0,2,temps_cpu);
		fprintf(f2,"%d %f\n",i,*temps_cpu);
		simulation_jeu(i,5,1,1,0,3,temps_cpu);
	
		fprintf(f3,"%d %f\n",i,*temps_cpu);
	}
	printf("\n");
	fclose(f1); 
	fclose(f2); 
	fclose(f3); 	
}


int main(int argc,char**argv){
	int couleur;
	int dimension;
	printf("Entrez une dimension maximale:");
	scanf("%d",&dimension);
	printf("Entrez un nombre de couleurs maximal:");
	scanf("%d",&couleur);
	test_dim(dimension);
	test_couleur(couleur);
	return 0;
}

