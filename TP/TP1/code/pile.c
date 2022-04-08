#include <stdio.h>
#include <stdlib.h>

#include "pile_type.h"
//#include "pile.h"

  
int error1(char *message)
{
   printf("ERROR : %s\n", message);
   exit(-1);
}	


PILE Empiler (PILE pile, int elem)
{
    PILE new = malloc(sizeof(*new));
    new -> elem = elem;
    new -> suivant = pile;

    return new;
}

// Car une fonction C ne peux pas modifier un argument.
/* Cette fonction renvoyant déjà l’éléménet dépilé, 
elle ne peut en même temps renvoyer la pile modifiée. */
int Depiler(PILE* ppile)
{
    PILE pile = *ppile;
    if(pile == NULL)
    {
        return(error1("Pile vide"));
    }

    int val = pile -> elem;
    PILE buffer = pile;
    *ppile = pile -> suivant;

    free(buffer);
    return val;
}	


void afficherPile (PILE pile)
{
    /*
    ELEMPILE *ElemCourant;
    while(ElemCourant != 0){
        fprintf(stdout,"%d ",ElemCourant -> elem);
        ElemCourant = ElemCourant -> suivant;
    }
    printf("\n");
    */
    
    while(pile != NULL)
    {
        printf("%d ", pile -> elem);
        pile = pile -> suivant;
    }
    printf("\n");
    
}