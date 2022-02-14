// Lecture d'un flottant au clavier et affichage à l’écran
# include <stdio.h>

int main()
{
    float valFloat;
    printf("Entrez un flottant. f = ");
    scanf("%f",&valFloat);
    printf("La valeur float rentrée est : %f",valFloat);
    printf("\n");

    // Vider le buffer d’entrée
    int c;
    while ( ((c = getchar()) != '\n') && c != EOF){};

    char valChar;
    printf("Entrez un char. c = ");
    scanf("%c",&valChar);
    printf("La valeur char rentrée est : %c\n",valChar);

    // Vider le buffer d’entrée
    while ( ((c = getchar()) != '\n') && c != EOF){};

    char chaine[80];
    printf("Entrez une chaîne de caractères: ");
    fgets(chaine,80,stdin);
    printf("La chaîne lue est : %s\n", chaine);

    printf("\n");

    return 0;
}