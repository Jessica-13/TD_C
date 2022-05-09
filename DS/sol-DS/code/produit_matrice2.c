#include <stdio.h>
#include <stdlib.h>


int **produit_matrice2(int **A, int **B, int N, int M, int P)
{
  int i,j,k;
  int **C;
  C=(int **)malloc(N*sizeof(int *));
  for (i=0;i<N;i++)
    C[i]=(int *)malloc(M*sizeof(int));
  
  for(i=0;i<N;i++)
    for (j=0;j<M;j++)
      {
        C[i][j]=0;
        for (k=0;k<P;k++)
          {
            C[i][j]=C[i][j]+A[i][k]*B[k][j];
          }
      }
  return C;
}

int main()
{

  int N=10, M=5, P=7;
  
  int **A;
  int **B;
  int **C;
  int i,j;
  
  A=(int **)malloc(N*sizeof(int *));
  for (i=0;i<N;i++)
    A[i]=(int *)malloc(P*sizeof(int));

  B=(int **)malloc(P*sizeof(int *));
  for (i=0;i<N;i++)
    B[i]=(int *)malloc(M*sizeof(int));

  for(i=0;i<N;i++)
    for (j=0;j<P;j++)
      A[i][j]=1;
  
  
  for(i=0;i<P;i++)
    for (j=0;j<M;j++)
      B[i][j]=1;

  C=produit_matrice2(A,B,N,M,P);

  for(i=0;i<N;i++)
    {
      
      for (j=0;j<M;j++)
        {
          printf(" %4d ",C[i][j]);
        }
      printf("\n");
    }
}
  
