#include <stdio.h>

int main()
{
  int i = 3, j = 6;
  int *p1, *p2;
  int *d1,*d2;

  p1 = &i;
  p2 = &j;
  printf("*p1 = %d \n", *p1);
  printf("p1 = %p \n", p1);

  *p1 = *p2; // i = j , on manipule directement la variable 

  printf("*p1 = %d \n", *p1);
  printf("p1 = %p \n", p1);
  printf("&p1 = %p \n", &p1);

  printf("*p2 = %d \n",*p2);
  printf("p2 = %p\n",p2);
  printf("&p2 = %p \n", &p2);

    
  printf("i= %d \n", i);
  printf("j = %d \n", j);



  // TEST
  d1=&*p1;
  d2=&*p2;

  printf("*d1 = %d \n", *d1);
  printf("d1 = %p\n",d1);

  printf("*d1 = %d \n", *d1);
  printf("d2 = %p\n",d2);
}
