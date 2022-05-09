#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type_bigInt.h"
#include "util_bigInt.h"
#include "io_bigInt.h"

//#define DEBUG




/*!
************************************************
* \brief Additionne deux Grands Entiers
* \param  bN1 Grand Entier
* \param  bN2 Grand Entier
* \param  res le Grand Entier résultat
* \return  0 si l'addition est OK, 1 en cas d'overflow
* \warning res doit être déjà alloué,
* ************************************************/
int addBigInt(bigInt bN1,bigInt bN2,bigInt res)
{
  int i, retenue;

  retenue=0;
  for (i=0; i<TAILLEMAX; i++)
    {
      res[i]=bN1[i]+bN2[i]+retenue;
      if (res[i]>=10)
        {
          retenue=1;
          res[i]=res[i]-10;
        }
      else
        retenue=0;
    }

  if (retenue==1) 
    return 1;
  else
    return 0;
}


/*!
************************************************
* \brief Multiplie par 10 un Grand Entier
* \param  bN Grand Entier
* \param  res Le Grand Entier multiplié par 10
* \return  0 si l'addition est OK, 1 en cas d'overflow
* \warning  res doit être déjà alloué,
* ************************************************/
int times10BigInt(bigInt bN, bigInt res)
{
  int i,taille,overflow=0;

  taille=getNbChiffreBigInt(bN);
  if (taille>=TAILLEMAX-1)
    {
      fprintf(stderr,"Warning  overflow in x10 #nbDigit=%d\n",taille);
      taille=TAILLEMAX-2;
      overflow=1;
    }

  for (i=taille+1;i>=1;i--)
    {// Warning, bN and res can be the same
      res[i]=bN[i-1];
    }
  res[0]=0;
  if (overflow==1)
    return 1;
  else
    return 0;
}



/*!
************************************************
* \brief Multiplie deux Grand Entiers avec l'algorithme suivant:
* stocker les 10 valeurs j*bN2 pour 1<=j<=9
* Pour chaque chiffre j=bN1[i] de bN1, partant de i=0,
* multiplier  j*bN2 par 10^i et l'ajouter au resultat
* \param  bN1 Grand Entier
* \param  bN2 Grand Entier
* \param  res le grand entier bN1*bN2
* \result Un entier: 1 en cas d'overflos, O sinon
* \warning res doit être déjà alloué,
* ************************************************/
int mulBigInt(bigInt bN1,bigInt bN2,bigInt res)
{
  int i,j,k,tailleN1,overflow=0;
  bigInt bNT[10],bNTemp;;

  bNTemp=initBigInt();
  // ne pas oublier de remettre le resultat à zero
  zeroBigInt(res);
  tailleN1=getNbChiffreBigInt(bN1);

#ifdef DEBUG
  int tailleN2;

  tailleN2=getNbChiffreBigInt(bN2);
  fprintf(stdout,"bN1=");
  printBigInt(bN1);
  fprintf(stdout,"bN2=");
  printBigInt(bN2);
  fprintf(stdout,"tailleN1=%d\n",tailleN1);
  fprintf(stdout,"tailleN2=%d\n",tailleN2);
#endif

  for (i=0;i<10;i++)
  {
    bNT[i]=initBigInt();
    if (i>0)
      {//bNT[i] contains i*bN2
        overflow=overflow || addBigInt(bNT[i-1],bN2,bNT[i]);
      }
  }
  
#ifdef DEBUG
  for (j=0;j<=9;j++)
    {
      fprintf(stdout,"%d*bN2=",j);
      printBigInt(bNT[j]);
    }
#endif

  for (i=0;i<tailleN1;i++)
    {
      //bN1[i]*bN2
      copyBigInt(bNT[bN1[i]],bNTemp);
      for (k=1;k<=i;k++)
      {//10^i*bN1[i]*bN2
        overflow=overflow || times10BigInt(bNTemp,bNTemp);
      }
      overflow=overflow ||  addBigInt(res,bNTemp,res);
      
#ifdef DEBUG
      fprintf(stdout,"***********************************************\n");
      fprintf(stdout,"bN1[%d]=%d,  10^%d*bN2=",i,bN1[i],i);
      printBigInt(bNTemp);
      fprintf(stdout,"res=");
      printBigInt(res);
#endif
    }

  freeBigInt(bNTemp);
  for (j=0;j<10;j++)
    freeBigInt(bNT[j]);
    
  if (overflow) 
    {
      fprintf(stderr,"Warning  overflow in multiplication\n");
      return(1);
    }
  else 
    return 0;
 }


/* multiplication without memorizing intermediate results */
int mulBigInt2(bigInt bN1,bigInt bN2,bigInt res)
{
  int i,j,k,tailleN1,overflow=0;
  bigInt bNTemp; 

  bNTemp=initBigInt();
  zeroBigInt(res);
  tailleN1=getNbChiffreBigInt(bN1);

#ifdef DEBUG
  int tailleN2;

  tailleN2=getNbChiffreBigInt(bN2);
  fprintf(stdout,"bN1=");
  printBigInt(bN1);
  fprintf(stdout,"bN2=");
  printBigInt(bN2);
  fprintf(stdout,"tailleN1=%d\n",tailleN1);
  fprintf(stdout,"tailleN2=%d\n",tailleN2);
#endif


  for (i=0;i<tailleN1;i++)
    {
      zeroBigInt(bNTemp);
      //bN1[i]*bN2
      for (j=0;j<bN1[i];j++)
        {
          overflow=overflow || addBigInt(bNTemp,bN2,bNTemp);
        }

      for (k=1;k<=i;k++)
      {//10^i*bN1[i]*bN2
        overflow=overflow || times10BigInt(bNTemp,bNTemp);
      }
      overflow=overflow ||  addBigInt(res,bNTemp,res);
      
#ifdef DEBUG
      fprintf(stdout,"bN1[%d]=%d,  10^%d*bN2=",i,bN1[i],i);
      printBigInt(bNTemp);
      fprintf(stdout,"res=");
      printBigInt(res);
      fprintf(stdout,"***********************************************\n");
#endif
    }

  freeBigInt(bNTemp);

  if (overflow) 
    {
      fprintf(stderr,"Warning  overflow in multiplication\n");
      return(1);
    }
  else 
    return 0;
 }



/*!
************************************************
* \brief calcule la factoriel d'un bigInt: bN1! 
* \param  bN1 Grand Entier
* \param  res le Grand Entier résultat
* \return  0 si l'operation est OK, 1 en cas d'overflow
* \warning res doit être déjà alloué,
* ************************************************/
int factorielleBigInt(bigInt bN1,bigInt res)
{int i,taille,N1;
  bigInt bI,temp,un;

  temp=initBigInt();  //temp=0
  bI=initBigInt();  //bI=1 (=i)
  bI[0]=1;
  un=initBigInt();  //un=1;
  un[0]=1;
  res[0]=1;    //res=1

  taille=getNbChiffreBigInt(bN1);
  if (taille>10)
    {
      fprintf(stderr,"Sorry, factorial not implemented for more than 10 digit\n");
      return(-1);
    }
  N1=bigIntToInt(bN1);
  for (i=1;i<=N1;i++) {
    mulBigInt(res,bI,temp);
    copyBigInt(temp,res);
    addBigInt(bI,un,bI);
  }

  return 0;
}
    
