# include <stdlib.h>
# include <stdio.h> 
# include "arbre_type.h"

ARBRE creerArbre(int val, ARBRE filsGauche, ARBRE filsDroit)
{
    ARBRE temp;
    temp = (ARBRE)malloc(sizeof(NOEUD));
    temp -> val = val;
    temp -> filsGauche = filsGauche;
    temp -> filsDroit = filsDroit;

    return(temp);
}

int afficheArbre(ARBRE arbre)
{   
    fprintf(stdout,"(");
    
    if (arbre -> filsGauche != NULL)
        afficheArbre(arbre -> filsGauche);
        

    fprintf(stdout,"%d",arbre -> val);

    if (arbre -> filsDroit != NULL)
        afficheArbre(arbre -> filsDroit);
    
    //fprintf(stdout,"%d",arbre -> val); # ça donne cel : ((10)(20)30)

    fprintf(stdout,")");
}



int hauteurArbre(ARBRE arbre)
{
    if (arbre == NULL)
        return 0;
   
    int left = hauteurArbre(arbre -> filsGauche);
    int right = hauteurArbre(arbre -> filsDroit);
   
    return ((left > right ? left : right) + 1);
    
}