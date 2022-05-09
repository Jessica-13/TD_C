#include "pile_type.h"
#include "pile.h"
#include "hanoi.h"
#include <stdio.h>

#define N 10

int main(int argc, char** argv) {
    PILE src = InitPile();
    PILE interm = InitPile();
    PILE dest = InitPile();

    for(int i = N; i > 0; i--) {
        src = Empiler(src, i);
    }

    printf("-- Avant --\n");
    printf("Source : ");
    AfficherPile(src);
    printf("Interm.: ");
    AfficherPile(interm);
    printf("Dest.  : ");
    AfficherPile(dest);

    hanoi(&src, &interm, &dest, N);

    printf("-- Apres --\n");
    printf("Source : ");
    AfficherPile(src);
    printf("Interm.: ");
    AfficherPile(interm);
    printf("Dest.  : ");
    AfficherPile(dest);
}