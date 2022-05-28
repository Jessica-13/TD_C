#ifndef PERSONNE_H 
#define PERSONNE_H 

struct personne {
    char Nom[30];
    int Annee_naissance;
    };
typedef struct personne PERSONNE;

#endif


#ifndef CELLULE_H 
#define CELLULE_H 

struct cell {
    PERSONNE entree;
    struct cell *suivant;
    } ;
typedef struct cell CELLULE;

typedef CELLULE *LISTE;

#endif