#include "pile.h"
#include <stdlib.h>
#include <stdio.h>

int error1(char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

PILE InitPile() {
    return(NULL);
}

PILE Empiler(PILE pile, int elem) {
    ELEMPILE* p_haut_pile = (ELEMPILE*) malloc(sizeof(ELEMPILE));
    if(p_haut_pile == NULL) {
        error1("Impossible d'allouer un nouvel element.");
    }
    p_haut_pile->elem = elem;
    p_haut_pile->suivant = pile;
    return(p_haut_pile);
}

int Depiler(PILE* ppile) {
    if(*ppile == NULL) {
        error1("Impossible de depiler un element d'une pile vide.");
    }
    ELEMPILE* p_haut_pile = *ppile;
    int elem = p_haut_pile->elem;
    *ppile = p_haut_pile->suivant;
    free(p_haut_pile);
    return(elem);
}

void AfficherPile(PILE pile) {
    ELEMPILE* p_haut_pile;
    for(p_haut_pile = pile; p_haut_pile != NULL; p_haut_pile = p_haut_pile->suivant) {
        printf("%d ", p_haut_pile->elem);
    }
    printf("\n");
}