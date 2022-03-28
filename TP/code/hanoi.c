#include <stdio.h>
#include <stdlib.h>

#include "pile_type.h"
#include "pile.h"
//#include "hanoi.h"

int deplacer(PILE *source, PILE *dest)
{
    PILE src = *source;
    PILE des = *dest;
    if(src == NULL)
    {
        return error1("Il n'y a pas de pile");
    }

    if(des != NULL && src -> elem > des -> elem)
    {
        return error1("On ne peut poser une rondelle que sur une rondelle de plus gros diamètre.");
    }

    int val = Depiler(source); // On prend la rondelle de la pile source

    des = Empiler(des, val); // On pose la rondelle sulla pile déstination
    *dest = des;    // Sinon on a l'erreur : Il n'y a pas de pile
    return(0);
}

int hanoi(PILE *depart,PILE *passage, PILE *arrive,int N)
{
    if(N != 0)
    {
        hanoi(depart, arrive, passage, N - 1);
        deplacer(depart, arrive);

        /*
        printf("Pile 1\n");
        afficherPile(*depart);

        printf("\nPile 2\n");
        afficherPile(*passage);
        
        printf("\nPile 3\n");
        afficherPile(*arrive);
        printf("\n");
        */

        hanoi(passage, depart, arrive, N - 1);
    }

    return(0);
}