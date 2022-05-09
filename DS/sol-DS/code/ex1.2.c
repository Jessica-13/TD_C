/******************************************************/
/*  fichier gprofTest.c                               */
/******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int space;
  

int cnp (int n, int k)
{
  int i,temp1,temp2,res;
  
#ifdef DEBUG
  space++;
  for (i=0;i<space;i++) fprintf(stdout," ");
  fprintf(stdout,"Appel CNP n=%d k=%d \n",n,k);
#endif 
  if ((k==n)||(k==0))
    res=1;
  else
    {
      temp1=cnp(n-1,k-1);
      temp2=cnp(n-1,k);
      res=temp1+temp2;
    }
   
#ifdef DEBUG
  for (i=0;i<space;i++) fprintf(stdout," ");
  fprintf(stdout,"Resultat CNP n=%d k=%d vaut %d\n",n,k,res);
  space--;
#endif  
  return(res);
}

/*********************************************************/
/* fonction main: passage en argument des parametres     */
/*********************************************************/
        
int main(int  argc, char *argv[])
{
   int i,nbIter,res;
  
  space = 0;
  
  res=cnp(10,7);
  nbIter = 10;
  printf("C(%d,%d)=%d\n",10,7,res);
  for (i=1;i<nbIter; i++)
    {
      res=cnp(i,i/3);
    }
  printf("C(%d,%d)=%d\n",i,i/3,res);
 
  return(0);
}

  
