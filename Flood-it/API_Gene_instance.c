#include "API_Gene_instance.h"
#include<stdio.h>

void Gene_instance_genere_matrice(int dim, int nbcl, int nivdif, int graine, int **M){
  int i,j,k,m,c,di,si,prof,larg;

  int diam= (nivdif/100.0)*dim;
  if (diam==0) diam=1;
  srand(graine);

  for (j=0;j<dim;j++)
    for (i=0;i<dim;i++)
      M[i][j]=-1;
 
  for (j=0;j<dim;j++)
    for (i=0;i<dim;i++){

      if (M[i][j]==-1){

	c=rand()%(nbcl);

	prof=1+rand()%(diam);
	larg=1+rand()%(diam);

	k=0;
	while ((k<prof)&&(j+k<dim)){

	  M[i][j]=c;
	  
	  di=(rand()%larg)/4.0;
	  si=1-2*rand()%2;
	  m=0;
	  while (m<larg){

	    if ((i+si*di+m>=0)&&(i+si*di+m<dim)&&(M[i+si*di+m][j+k]==-1))
	      M[i+si*di+m][j+k]=c;
	    m++;
	  }

	  k++;
	}

      }
    }
 
}
