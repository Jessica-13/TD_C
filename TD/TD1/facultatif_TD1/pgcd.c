/******************************************************/
/*  fichier pgcd.c                                    */
/******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pgcd.h"
//#define DEBUG // pour debugger

int pgcd (int a, int b)
{
  int res;

#ifdef DEBUG
  fprintf(stdout,"Entree dans pgcd: a=%d, b=%d\n",a,b);
#endif
  if (a>b)
    {
      if (a%b==0) 
        res=b;
      else
        res=pgcd(b,a%b);
    }
    else
      {
        if (b%a==0) 
          res=a;
        else
          res=pgcd(a,b%a);
      }
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
      fprintf(stdout,"Usage: pgcd a b\n avec a et b entier\n");
      exit(1);
    }
  aString=(char *)malloc(10*sizeof(char));
  bString=(char *)malloc(10*sizeof(char));
  strcpy(aString,argv[1]);
  strcpy(bString,argv[2]);
  a=atoi(aString);
  b=atoi(bString);
  res=pgcd(a,b);
  fprintf(stdout,"Le pgcd de %d et %d est... ",a,b);
  fprintf(stdout,"%d\n",res);
  return(0);
}

  
