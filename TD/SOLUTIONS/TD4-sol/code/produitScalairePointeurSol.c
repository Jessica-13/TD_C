#include <stdio.h>
#include <stdlib.h>

#define N 5

int produit_scalaire(int A[N], int B[N])
{
  int i, res;
  int *pA, *pB;
    
  res=0;
  pA=A; // ou pA=&A[0] , c'est est équivalent
  pB=B; 
  for (i=0;i<N;i++)
    {
      res += (*pA++) *(*pB++);
    }

  return res;
}

void erreur(char *chaine)
{
  printf("%s",chaine);
  exit(-1);
}

int main()
{
int *A,*B,i;
 
 A=(int *)malloc(N*sizeof(int));
 if (!A) erreur("Pb during allocation of A\n");
 B=(int *)malloc(N*sizeof(int));
 if (!B) erreur("Pb during allocation of A\n");
 
 for (i=0;i<N;i++)
   {
     A[i]=1;
     B[i]=1;
   }
  printf("le produit scalaire vaut %d\n", produit_scalaire(A,B));
  free(A);
  free(B);
    
  return 0;
}
	 
