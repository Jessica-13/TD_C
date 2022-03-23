#include <stdio.h>

int main()
{
  float f;
  char c;

  printf("entrer un flottant:\n");
  scanf("%f",&f);
  printf("f = %f\n",f);
  printf("entrer un caractère: \n");
  scanf("%c",&c);
  printf("c = %c\n",c);
  scanf("%c",&c);
  printf("c = %c\n",c);

  return 0;
}
