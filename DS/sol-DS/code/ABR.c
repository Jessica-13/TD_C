#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
      int val;
      struct cell *filsDroit;
      struct cell *filsGauche;
     } CELL;
typedef CELL *ARBRE;

void afficheNoeudInterne(ARBRE arbre)
{
  if (arbre!=NULL)
    {
      if (arbre->filsDroit==NULL && arbre->filsGauche==NULL)
	return;
      else
	{
	  afficheNoeudInterne(arbre->filsGauche);
	  printf(" %d ",arbre->val);
	  afficheNoeudInterne(arbre->filsDroit);
	  return;
	}
    }
}

void afficherArbre(ARBRE arbre)
{
  if (arbre==NULL)
    return;
  afficherArbre(arbre->filsGauche);
  printf(" %d ",arbre->val);
  afficherArbre(arbre->filsDroit);
  return;
}

ARBRE nouvelArbre(ARBRE fg, ARBRE fd, int val)
{
  ARBRE new;

  new=(ARBRE)malloc(sizeof(CELL));
  if (new==NULL)
    exit(-1);
  new->filsDroit=fd;
  new->filsGauche=fg;
  new->val=val;
  return new;
}

int totalFeuille(ARBRE arbre)
{
  if (arbre!=NULL)
    {
      if (arbre->filsDroit==NULL && arbre->filsGauche==NULL)
	{
	  return(arbre->val);
	}
      else
	return(totalFeuille(arbre->filsDroit)+totalFeuille(arbre->filsGauche));
    }
  else
    return 0;
}

ARBRE insertionARBRE(ARBRE arbre, int val)
{
  ARBRE new;
  
  if (arbre==NULL)
    {
      new=nouvelArbre(NULL,NULL,val);
      return(new);
    }
  else
    {
      if (arbre->val > val)
	{
	  arbre->filsGauche=insertionARBRE(arbre->filsGauche,val);
	  return arbre;
	}
      else
	{
	  arbre->filsDroit=insertionARBRE(arbre->filsDroit,val);
	  return arbre;
	}
    }
}


int main()
{
  ARBRE a1,a2,a3,a4,a5,arbre;


  a1=nouvelArbre(NULL,NULL,6);
  a2=nouvelArbre(a1,NULL,8);
  a3=nouvelArbre(NULL,NULL,13);
  a4=nouvelArbre(a2,a3,12);

  a1=nouvelArbre(NULL,NULL,2);
  a5=nouvelArbre(a1,a4,3);

  a1=nouvelArbre(NULL,NULL,21);
  a2=nouvelArbre(NULL,NULL,26);
  a3=nouvelArbre(a1,a2,25);

  arbre=nouvelArbre(a5,a3,20);

  printf("arbre: -----------------\n");
  afficherArbre(arbre);
  printf("\n------------------------\n");
  afficheNoeudInterne(arbre);
  printf("\n------------------------\n");
  printf("totalfeuille: %d\n",totalFeuille(arbre));

  arbre=NULL;
  
  arbre=insertionARBRE(arbre,20);
  arbre=insertionARBRE(arbre,3);
  arbre=insertionARBRE(arbre,25);
  arbre=insertionARBRE(arbre,2);
  arbre=insertionARBRE(arbre,12);
  arbre=insertionARBRE(arbre,21);
  arbre=insertionARBRE(arbre,26);
  arbre=insertionARBRE(arbre,8);
  arbre=insertionARBRE(arbre,13);
  arbre=insertionARBRE(arbre,6);
  
  printf("arbre: -----------------\n");
  afficherArbre(arbre);
  printf("\n------------------------\n");

  return 0;

}
