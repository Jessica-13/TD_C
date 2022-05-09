#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 5
#define P 7


void produit_matrice1(int A[N][P], int B[P][M], int C[N][M])
{
  int i,j,k;

  for(i=0;i<N;i++)
    for (j=0;j<M;j++)
      {
        C[i][j]=0;
        for (k=0;k<P;k++)
          {
            C[i][j]=C[i][j]+A[i][k]*B[k][j];
          }
      }
}

int main()
{
  int A[N][P];
  int B[P][M];
  int C[N][M];
  int i,j;
  
  for(i=0;i<N;i++)
    for (j=0;j<P;j++)
      A[i][j]=1;
  
  
  for(i=0;i<P;i++)
    for (j=0;j<M;j++)
      B[i][j]=1;

  produit_matrice1(A,B,C);

  for(i=0;i<N;i++)
    {
      
      for (j=0;j<M;j++)
        {
          printf(" %4d ",C[i][j]);
        }
      printf("\n");
    }
}
  
