#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrice.h"
#include "utilMatrice.h"
#include "matProd.h"
#include "matEqualQ.h"
	 
int  main(int argc,char *argv[])
{
  FILE *fichA, *fichB, *fichD;
  char nomFichA[15]="matriceA.txt";
  char nomFichB[15]="matriceB.txt";
  char nomFichD[15]="matriceAxB.txt";

  int A[N][N], B[N][N], C[N][N], D[N][N];
  int err;
  
  fichA=fopen(nomFichA,"r");
  if (!fichA)
    {
      fprintf(stderr,"erreur d'ouverture du fichier %s\n",nomFichA);
      exit(-1);
    }

  fichB=fopen(nomFichB,"r");
  if (!fichB)
    {
      fprintf(stderr,"erreur d'ouverture du fichier %s\n",nomFichB);
      exit(-1);
    }
  
  err=lireMatrice(fichA,A);
  if (err)
    {
      fprintf(stderr,"erreur lors de la lecture de %s\n",nomFichA);
      exit(-1);
    }

  err=lireMatrice(fichB,B); 
  if (err)
    {
      fprintf(stderr,"erreur lors de la lecture de %s\n",nomFichB);
      exit(-1);
    }
  




  fichD=fopen(nomFichD,"r");
  if (!fichD)
    {
      fprintf(stderr,"erreur d'ouverture du fichier %s\n",nomFichD);
      exit(-1);
    }
  
  err=lireMatrice(fichD,D); 
  if (err)
    {
      fprintf(stderr,"erreur lors de la lecture de %s\n",nomFichD);
      exit(-1);
    }
  




 fprintf(stdout," Matrice lues: \n");
 fprintf(stdout," A: \n");
 ecrireMatrice(stdout,A);

 fprintf(stdout," B: \n");
 ecrireMatrice(stdout,B);

  fprintf(stdout," D: \n");
  ecrireMatrice(stdout,D);

 matProd(A,B,C);

 fprintf(stdout," resultat du produit C=AB (FAUX évidement): \n");
 ecrireMatrice(stdout,C);




// Question 
 fprintf(stdout," resultat du test égalité entre A et B: \n");
 fprintf(stdout, "%s\n", matEqualQ(A,B) ? "true" : "false");
 
  fprintf(stdout," resultat du test égalité entre C et D: \n");
  fprintf(stdout, "%s\n", matEqualQ(C,D) ? "true" : "false");
    return(0);
}
