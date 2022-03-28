# include <stdio.h>

int factorielle(int n)
{
    int i, fact=1;

    for (i = 1; i<=n; i++)
        fact *= i;

    return fact;
}

int main()
{
    int num = 10;
    int x = factorielle(num);     
    printf("La fatorielle de %d est : %d\n", num, x);
}