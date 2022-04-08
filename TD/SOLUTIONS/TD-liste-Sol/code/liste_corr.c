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
  ELEMLISTE *newelem;  
  LISTE res;
  LISTE finListe;

   if (liste1==NULL) 
   {
     // creation d'un nouvel element
     newelem=(ELEMLISTE *)malloc(sizeof(ELEMLISTE));
     if (newelem==0)
       {
	 printf("insertionListeTriee: plus de place mémoire");
	 exit(EXIT_FAILURE);
       }
     newelem->elem=val;
     newelem->suivant=liste1;
     res=newelem;
     return res;
   }
 else
   if (liste1->elem > val)
     {//la valeur doit être insérée au début de la liste
       newelem=(ELEMLISTE *)malloc(sizeof(ELEMLISTE));
       if (newelem==0)
	 {
	   printf("insertionListeTriee: plus de place mémoire");
	   exit(EXIT_FAILURE);
	 }
       newelem->elem=val;
       newelem->suivant=liste1;
       res=newelem;
       return res;
     }
   else
     {// la valeur doit être insérée après le premier element
       finListe=liste1->suivant;
       //appel recursif, finListe est modifiée par la procédure
       finListe=insertionListeTriee(finListe,val);
       //liste conserve son premier element
       liste1->suivant=finListe;
       res=liste1;
       return res;
     }
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
  ELEMLISTE *newelem;  
  LISTE finListe;
  
 if (*pliste==NULL) 
   {
     // creation d'un nouvel element
     newelem=(ELEMLISTE *)malloc(sizeof(ELEMLISTE));
     if (newelem==0)
       {
	 printf("insertionListeTriee2: plus de place mémoire");
	 exit(EXIT_FAILURE);
       }
     newelem->elem=val;
     newelem->suivant=*pliste;
     //on fait pointer pliste vers newelem
     *pliste=newelem;
     return;
   }
 else
   if ((*pliste)->elem > val)
     {//la valeur doit être insérée au début de la liste
       newelem=(ELEMLISTE *)malloc(sizeof(ELEMLISTE));
       if (newelem==0)
	 {
	   printf("insertionListeTriee2: plus de place mémoire");
	   exit(EXIT_FAILURE);
	 }
       newelem->elem=val;
       newelem->suivant=*pliste;
       *pliste=newelem;
       return;
     }
   else
     {// la valeur doit être insérée après le premier element
       finListe=(*pliste)->suivant;
       //appel recursif, finListe est modifiée par la procédure
       insertionListeTriee2(&finListe,val);
       //liste conserve son premier element
       (*pliste)->suivant=finListe;
       return;
     }
}



/*!
************************************************
* \brief fusion de deux listes triées,
* \param pliste1 adresse de la liste1 
* \param pliste2 adresse de la liste2 
* \return  la liste1 contient tous les éléments triés
* \return  la liste2 est vide
**************************************************/    
void fusion (LISTE *pliste1, LISTE *pliste2)	
{  LISTE   LL1, LL2;  

 if (*pliste2==NULL) 
   {//rien a faire
     return;
   }
 if (*pliste1==NULL) 
   {//list1<-list2
     *pliste1=*pliste2;
     *pliste2=(LISTE)NULL;
     return;
   }
 if ((*pliste1)->elem>(*pliste2)->elem)
   {//on insere un element de liste 2 dans liste1
     LL2=((*pliste2)->suivant);
     // appel recursif: on fusionne le reste dans liste1
     fusion(pliste1,&LL2);
     //*pliste1 est maintenant  la liste triée qui contient
     // tous les éléments sauf le premier de liste2
     // On met le 1er elt de liste2 au debut de liste1
     (*pliste2)->suivant=*pliste1;
     *pliste1=*pliste2;
     //mise a jour de liste2 (elle doit etre vide normalement)
     *pliste2=(LISTE)NULL;
   }
 else
   {//on laisse le premier element dans liste1
     LL1=((*pliste1)->suivant);
     // appel recursif: on fusionne le reste dans LL1
     fusion(&LL1,pliste2);
     //LL1 est maintenant la liste triée qui contient
     // tous les éléments sauf le premier de liste1
     (*pliste1)->suivant=LL1;
     //mise a jour de liste2 (elle doit etre vide normalement)
     *pliste2=(LISTE)NULL;
   }
 return;
}
     

int viderListe(LISTE *pliste1)
{
  int res;
  LISTE first;
  if (*pliste1==NULL)
    return 0;
  else
    {
      first=*pliste1;
      res=viderListe(&((*pliste1)->suivant));
      free(first);
      return res+1;
    }
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
 afficherListe(liste2);
 fprintf(stdout,"Après fusion avec fusion\n");
 fusion(&liste1,&liste2);
 fprintf(stdout,"liste1:");
 afficherListe(liste1);
 fprintf(stdout,"liste2:");
 afficherListe(liste2);
 fprintf(stdout,"netoyage: %d element supprimes\n",viderListe(&liste1));
 

}




