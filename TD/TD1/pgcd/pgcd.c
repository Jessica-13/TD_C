// PGCD(a,b) renvoi le plus grand commun diviseur de deux entiers

# include <stdio.h>

int pgcd(int a, int b)
{
    int res;

    if (a > b)
        if (a % b == 0)
            res = b;
        else
            res = pgcd(b, a%b);
    else
        if (b % a == 0)
            res = a;
        else
            res = pgcd(a, b%a);
    return res;
}


