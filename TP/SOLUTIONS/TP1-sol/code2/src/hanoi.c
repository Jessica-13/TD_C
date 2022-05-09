#include "hanoi.h"
#include "pile.h"
#include <stdlib.h>

int deplacer(PILE* psrc, PILE* pdest) {
    // int elem = Depiler(psrc);
    // *pdest = Empiler(*pdest, elem);

    if(*psrc == NULL) {
        error1("Impossible de deplacer depuis une pile vide.");
    }
    ELEMPILE* p_haut = *psrc;
    *psrc = p_haut->suivant;
    p_haut->suivant = *pdest;
    *pdest = p_haut;
    return(0);
}

int hanoi(PILE* psrc, PILE* pinterm, PILE* pdest, int nombre) {
    if(nombre > 0) {
        hanoi(psrc, pdest, pinterm, nombre - 1);
        deplacer(psrc, pdest);
        hanoi(pinterm, psrc, pdest, nombre - 1);
    }
    return(0);
}