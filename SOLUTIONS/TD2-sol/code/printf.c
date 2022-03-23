#include <stdio.h>

int main()
{
  int i,max=30;

  /* à la suite */
  printf("Carré de %d premiers entiers:\n",max);
  for (i=0; i<max; i++)
    {
      printf(" %d ",i*i);
    }
  printf("\n Un par ligne:\n");
  /* un par ligne */
  for (i=0; i<max; i++)
    {
      printf("%d\n",i*i);
    }
  printf("\n Allignés à droite:\n");
  for (i=0; i<max; i++)
    {
      printf("%10d\n",i*i);
    }

  return 0;
}
