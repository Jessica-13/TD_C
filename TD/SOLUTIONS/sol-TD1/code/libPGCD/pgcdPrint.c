/******************************************************/
/*  fichier pgcd.c                                    */
/******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pgcd.h"
//#define DEBUG // pour debugger

/* pgcdPrint, calcule le Pgcd et imprime 
  les parametre et le resultat avec 'space'
  espace devant */
int pgcdPrint (int a, int b,int space)
{
  int i,res;

  for (i=0;i<space;i++) fprintf(stdout," ");
  fprintf(stdout," Appel de pgcd(%d,%d)\n",a,b);
  if (a>b)
    {
      if (a%b==0) 
        res=b;
      else
        res=pgcdPrint(b,a%b,space+4);
    }
    else
      {
        if (b%a==0) 
          res=a;
        else
          res=pgcdPrint(a,b%a,space+4);
      }
  for (i=0;i<space;i++) fprintf(stdout," ");
  fprintf(stdout," retour de pgcd(%d,%d)=%d\n",a,b,res);
  return(res);
}

/*********************************************************/
/* fonction main: passage en argument des parametres     */
/*********************************************************/
        
int main(int  argc, char *argv[])
{
  char *aString, *bString;
  int a,b,res;

  if (argc!=3)
    {
      fprintf(stdout,"Usage: pgcd a b\n avec a et b entier");
      exit(1);
    }
  aString=(char *)malloc(10*sizeof(char));
  bString=(char *)malloc(10*sizeof(char));
  strcpy(aString,argv[1]);
  strcpy(bString,argv[2]);
  a=atoi(aString);
  b=atoi(bString);
  res=pgcdPrint(a,b,0);
  fprintf(stdout,"Le pgcd de %d et %d est... ",a,b);
  fprintf(stdout,"%d\n",res);
  return(0);
}

  
