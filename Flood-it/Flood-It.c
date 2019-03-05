#include <stdio.h>
#include <stdlib.h>

#include "API_Grille.h"
#include "API_Gene_instance.h"
#include "exo1.h"
#include "zones.h"

 
 
int main(int argc,char**argv){

  int dim, nbcl, nivdif, graine;
  Grille *G;
  int i,j;
  int **M;



  if(argc!=5){
    printf("usage: %s <dimension nb_de_couleurs niveau_difficulte graine>\n",argv[0]);
    return 1;
  }

  dim=atoi(argv[1]);


  nbcl=atoi(argv[2]);
  nivdif=atoi(argv[3]);
  graine=atoi(argv[4]);

  /* Generation de l'instance */

  M=(int **) malloc(sizeof(int*)*dim);
  for (i=0;i<dim;i++){
    M[i]=(int*) malloc(sizeof(int)*dim);
    if (M[i]==0) printf("Pas assez d'espace mémoire disponible\n");
  }

  Gene_instance_genere_matrice(dim, nbcl, nivdif, graine, M);

  /* Affichage de la grille */

  Grille_init(dim,nbcl, 500,&G);

  Grille_ouvre_fenetre(G);

  for (i=0;i<dim;i++)
    for (j=0;j<dim;j++){
      Grille_attribue_couleur_case(G,i,j,M[i][j]);
    }

  Grille_redessine_Grille();
 


  
  //Exo1
	Liste *l = malloc (sizeof(Liste));
	init_liste(l);
	int t=0;
	int choix;

	printf("Pour la version recursive tapez 1\n, pour l'imperative tapez 2\n pour l'acyclique tapez 3: ");
	
	
	scanf("%d", &choix);
	if(choix == 1){
		trouve_zone_rec(M,dim,0,0,&t,l);
		printf ("Il a fallu %d tours pour finir\n",sequence_aleatoire_rec(M, G, dim, nbcl, 1,1));
    }
    
    if(choix == 2){
		trouve_zone_imp(M,dim,0,0,&t,l);
		printf ("Il a fallu %d tours pour finir\n",sequence_aleatoire_rec(M, G, dim, nbcl, 1,2));
    }
	if(choix == 3){
		S_Zsg * Z=initZone(dim,nbcl);
		strequence_aleatoire_rapide(M,G,Z);
	}

  Grille_attente_touche();
 
  Grille_ferme_fenetre();

  Grille_free(&G);

  return 0;
}
