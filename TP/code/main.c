#include <stdio.h>
#include <time.h>   /* time_t, time, ctime */ 

#include "pile.h"
#include "hanoi.h"

#define N 9
 
/*!***********************************************
* \brief  Programme de test des fonction du module pile.c
**************************************************/    

int main(int argc,char **argv)	
{
  // Pour le temps
  clock_t
    temps_initial, /* Temps initial en micro-secondes */
    temps_final; /* Temps final en micro-secondes */
  float
    temps_cpu; /* Temps total en secondes */


  PILE pile1 = NULL;
  PILE pile2 = NULL;
  PILE pile3 = NULL;
  int val,i;

  // TEST FONCTION ERROR1
  //error1("COUCOU");

  fprintf(stdout,"/********** test de pile d'entier *************\n");

  for (i = N; i > 0; i--)
    {
      val = i;
      pile1 = Empiler(pile1,val);
    }
  fprintf(stdout,"après mise en place d'une pile de taille %d\n",N);

  printf("\n\n"); // Pour la forme
  printf("Pile 1 : \n");
  afficherPile(pile1);
  printf("Pile 2 : \n");
  afficherPile(pile2);
  printf("Pile 3 : \n");
  afficherPile(pile3);
  printf("\n\n"); // Pour la forme

  fprintf(stdout,"/**** fin du programme de test de pile d'entier **\n");

  // On appelle la fonction hanoi
  temps_initial = clock ();
  hanoi(&pile1, &pile2, &pile3, N);   // Passage adapté
  temps_final = clock ();

  fprintf(stdout,"Résultat finale après hanoi \n");

  printf("\n\n"); // Pour la forme
  printf("Pile 1 : \n");
  afficherPile(pile1);
  printf("Pile 2 : \n");
  afficherPile(pile2);
  printf("Pile 3 : \n");
  afficherPile(pile3);
  printf("\n\n"); // Pour la forme

  temps_cpu = (temps_final - temps_initial) * 1e-6;
  fprintf(stdout,"Temps : %f s\n", temps_cpu);
  /*
  N = 9 : 0.006819 s
  N = 20 : 11.237398 s
  N = 30 : 
  */

  return 0;
 
}


/*
  pile1=InitPile();
  for (int i = N ; i > 0 ; i--)
  {
    pile1=Empiler(pile1,i);
  }
  pile2=InitPile();
  pile3=InitPile();
}
*/
