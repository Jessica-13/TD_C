#include <stdio.h> 
#include <stdlib.h>
#include "type_personne.h"

PERSONNE CreerPersonne(){
    PERSONNE *newPersonne;
    newPersonne = (PERSONNE *)malloc(sizeof(PERSONNE));
    
    //if (NewPersonne == NULL){exit(-1);}
    for(int i = 0; i<sizeof(newPersonne->Nom);i++){
        newPersonne->Nom[i] = ' ';
    }

    newPersonne->Annee_naissance = 2000;
    return *newPersonne; 
}

void afficherPersonne(PERSONNE individu){
    fprintf(stdout,"INFORMATIONS\n");
    fprintf(stdout,"Le nom est : %s\n",individu.Nom);
    fprintf(stdout,"L'année de naissance est : %d\n",individu.Annee_naissance);
}

int saisirPersonne(PERSONNE *individu){
    //PERSONNE *pourInput;
    //pourInput = individu;
    fprintf(stdout,"Nom : ");
    fgets(individu -> Nom,30,stdin);
    fprintf(stdout,"Année de naissance : ");

    // Vider le buffer d’entrée
    int c;
    while ( ((c = getchar()) != '\n') && c != EOF){};

    scanf("%d",&individu -> Annee_naissance);

    // Vider le buffer d’entrée
    c = 0;
    while ( ((c = getchar()) != '\n') && c != EOF){};

    return 0;
}

LISTE ajouterPersonne(LISTE groupe, char *nomIndividu, int agelndividu){
    CELLULE *newCellule;
    newCellule = (CELLULE *)malloc(sizeof(CELLULE));
    if (newCellule == 0)
    {
        fprintf(stderr,"AjouterElem: plus de place mémoire");
        exit(-1);
    }

    PERSONNE *nouvellePersonne;
    nouvellePersonne = (PERSONNE *)malloc(sizeof(PERSONNE));

    for(int i = 0; i<sizeof(nouvellePersonne->Nom);i++){
        nouvellePersonne->Nom[i] = nomIndividu[i];
    }

    //nouvellePersonne -> Nom[sizeof(nomIndividu)] = nomIndividu;
    nouvellePersonne -> Annee_naissance = agelndividu;

    newCellule -> entree = *nouvellePersonne;
    newCellule -> suivant = groupe;
    return newCellule;
}




int main()
{
    int err;
    PERSONNE personne1 = CreerPersonne();
    fprintf(stdout,"Personne 1 \n");
    afficherPersonne(personne1);

    fprintf(stdout,"Personne 2 \n");
    PERSONNE personne2 = CreerPersonne();
    afficherPersonne(personne2);

    fprintf(stdout,"Ajouter info \n");
    err = saisirPersonne(&personne2);
    fprintf(stdout,"Personne 2 aprés modif \n");
    afficherPersonne(personne2);


    return 0;
}