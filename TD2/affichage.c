// Q2 ) Afficher, les carrés des 30 premiers entiers
# include <stdio.h>

int main()
{
    int carre;
    int i;
    printf("Entrez un entier qui represente le nombre de carrés à calculer. i = ");
    scanf("%d",&i); //input
    printf("i = %d\n",i);

    printf("Les carrés des %d premiers entiers : \n", i);
    for( int j=0; j<i; j++)
    {
        carre = j*j;
        printf("%50d \n", carre);
    }
    printf("\n");

    return 0;
}