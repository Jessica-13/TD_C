#include <stdio.h>

#define N 5

int produit_scalaire(int A[N], int B[N])
{
  int i, res;
  int *pA, *pB;

  res=0;
  pA=A; // on prendre l'addresse de la prémiere case et on la donne : pA = &A[0]
  pB=B;
  for (i=0;i<N;i++)
    {
      res += (*pA++) *(*pB++);  // avec ++ on incrément l'addresse de +4 // 5
      // res += *(pA + i) * *(pB + i); // 5
      // res += (*pA + i) *(*pB + i); // 55
    } 
  return res;
}

int main()
{
  int A[N]={1,1,1,1,1};
  int B[N]={1,1,1,1,1};

  printf("le produit scalaire vaut %d\n", produit_scalaire(A,B));

  return 0;
}
	 
