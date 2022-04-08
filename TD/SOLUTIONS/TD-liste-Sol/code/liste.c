#include <stdio.h>
#include <stdlib.h>

#include "liste_type.h"
#include "liste.h"


/*!
************************************************
* \brief ajouter un element dans une liste triee
*    et renvoyer la nouvelle liste
* \param liste adresse d'une liste 
* \param val un entier a ajouter à la liste triee
* \return Modifie La liste, insère l'élément inséré
* \return retourne la nouvelle liste
**************************************************/    
LISTE insertionListeTriee(LISTE liste1, int val)
{
  return (LISTE)NULL;
}

/*!
************************************************
* \brief ajouter un element dans une liste triee
* \param pliste adresse d'une liste 
* \param val un entier a ajouter à la liste triee
* \warning On passe un pointeur sur une liste (donc un pointeur
*   sur un pointeur sur un element)
* \return Modifie La liste, insère l'élément inséré
**************************************************/    
void insertionListeTriee2 (LISTE *pliste, int val)	
{ 
  return;
}

/*!
************************************************
* \brief affiche une liste d'entier
* \param liste une liste d'entier
**************************************************/    
void afficherListe(LISTE liste)	
{
  ELEMLISTE *visitor;
 
 visitor=liste;
 while(visitor!=0)
   {
     fprintf(stdout,"|%d|",visitor->elem);
     visitor=visitor->suivant;
   }
 fprintf(stdout,"|--\n");
}	





 


/*! \brief program de test du module liste chainée
 */ 
 int main(int argc,char **argv)	
{
  LISTE liste1,liste2;

 fprintf(stdout,"/********** test rapide des fonctions de base *************\n");

 liste1=NULL;
 fprintf(stdout,"Listes triés créées avec insertionListeTriee\n");
 liste1=NULL;
 liste1=insertionListeTriee(liste1,1);
 liste1=insertionListeTriee(liste1,4);
 liste1=insertionListeTriee(liste1,5);
 liste1=insertionListeTriee(liste1,2);
 fprintf(stdout,"liste1:");
 afficherListe(liste1);
 fprintf(stdout,"Listes triés créées avec insertionListeTriee2\n");
 liste2=NULL;
 insertionListeTriee2(&liste2,2);
 insertionListeTriee2(&liste2,4);
 insertionListeTriee2(&liste2,7);
 insertionListeTriee2(&liste2,-1);
 fprintf(stdout,"liste2:");
 afficherListe(liste2);
 

}




