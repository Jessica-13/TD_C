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

