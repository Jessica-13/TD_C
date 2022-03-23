#include <stdio.h>

void troisFoisCinq()
{
  int res;

  printf("Combien font 3 x 5 ? ");
  scanf("%d",&rep);

  While(res!=15)
    {
      printf("Mauvaise réponse, essayez encore: combien font 3 x 5?\n");
      scanf("%d",&rep);
    }
  return rep;
}
	
int main()
{
int res; 
  res=troisFoisCinq();
}
