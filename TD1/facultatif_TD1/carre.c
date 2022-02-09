/******************************************************/
/*  fichier pgcd.c                                    */
/******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carre.h"
//#define DEBUG // pour debugger

int carre (int a, int space)
{
  int i,temp,res;

  for (i=0;i<space;i++) fprintf(stdout," ");
  fprintf(stdout," Appel de carre(%d)\n",a);

  if (a==1)
    res=1;
  else
    {
      temp=carre(a-1,space+3);
      res=temp+2*a-1;
    }

  for (i=0;i<space;i++) fprintf(stdout," ");
  fprintf(stdout," Retour de carre(%d)=%d\n",a,res);
  
  return(res);
}

/*********************************************************/
/* fonction main: passage en argument des parametres     */
/*********************************************************/
        
int main(int  argc, char *argv[])
{
  char *aString;
  int a,res;

  if (argc!=2)
    {
      fprintf(stdout,"Usage: carre a \n avec a entier");
      exit(1);
    }
  aString=(char *)malloc(10*sizeof(char));
  strcpy(aString,argv[1]);
  a=atoi(aString);
  res=carre(a,0);
  fprintf(stdout,"Le carre de %d  est... ",a);
  fprintf(stdout,"%d\n",res);
  return(0);
}

  
