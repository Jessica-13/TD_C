# include <stdlib.h>
# include <stdio.h> 
# include "arbre.h"

int main()
{
    ARBRE arbre, temp1, temp2, temp3;
    temp1 = creerArbre(10,NULL,NULL);
    temp2 = creerArbre(20,NULL,NULL);
    temp3 = creerArbre(50,temp2,NULL);
    arbre = creerArbre(30,temp1,temp3);
    fprintf(stdout,"filsdroit -> val = %d\n",arbre -> val);
    fprintf(stdout,"filsdroit -> val = %d\n",arbre -> filsDroit -> val);
    fprintf(stdout,"filsgauche -> val = %d\n",arbre -> filsGauche -> val);
    fprintf(stdout,"\n");

    fprintf(stdout,"arbre : \n");
    afficheArbre(arbre);
    fprintf(stdout,"\n");

    fprintf(stdout,"\n");
    fprintf(stdout,"hauteur arbre : %d\n", hauteurArbre(arbre));
    
}