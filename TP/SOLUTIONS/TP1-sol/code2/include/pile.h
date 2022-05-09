#ifndef __PILE_H_
#define __PILE_H_

#include "pile_type.h"

int error1(char*);
PILE InitPile();

PILE Empiler(PILE, int);
int Depiler(PILE*);
void AfficherPile(PILE);

#endif