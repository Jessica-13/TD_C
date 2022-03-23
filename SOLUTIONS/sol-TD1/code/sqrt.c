#include <stdio.h>
#include <math.h>

int main()
{
  printf("La racine carré de 5 est %f\n",sqrt(5.));
  printf("Le sinus de 5 est %f\n",sin(5.));

  return(0);
}

//a compiler avec la règle:
//sqrt: sqrt.c
//       gcc -Wall sqrt.c -o sqrt -lm
