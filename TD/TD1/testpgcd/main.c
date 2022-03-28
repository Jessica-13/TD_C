# include <stdio.h>
# include "pgcd.h"

int main ()
{
    int valPgcd;

    valPgcd = pgcd(3,6);

    printf("Valeur du pgcd %d\n", valPgcd);

    return (0);
}