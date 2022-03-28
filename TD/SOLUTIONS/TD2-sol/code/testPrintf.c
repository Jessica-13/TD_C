#include <stdio.h>

int main()
{
  float x;
  char c;
  char chaine[80];
  
  printf("entrer un flottant:\n");
  //Je lit le retour chariot
  scanf("%f",&x);
  printf("Le flottant lu est:  %f\n",x);
  printf("entrer un caractère (ça ne devrait pas marcher chez eux):\n");
  scanf("%c",&c);
  printf("Le caractère lu est:  %c\n",c);
  printf("entrer la chaîne de caractère:\n");
  scanf("%s",chaine);
  printf("La chaîne de caractère lue est:  %s\n",chaine);

  return 0;
}
