#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type_bigInt.h"
#include "util_bigInt.h"
#include "io_bigInt.h"

#define DEBUG1


int times10BigInt(bigInt bN,bigInt res){
  int i;
  for (i=TAILLEMAX-1; i>0; i--){
    res[i] = bN[i-1];
  }
  res[0] = 0;
  return 0;
}



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
  zeroBigInt(res);  // Pour effacer les variables temporelles
  int i;
  for (i=0; i<TAILLEMAX; i++)
  {
    //printf("i=%d bn!=%d bn2=%d res=%d\n",i,bN1[i],bN2[i],res[i]);
    if(bN1[i]+bN2[i]+res[i]<=9)
    {
      res[i] += (bN1[i]+bN2[i]);
    } else {
      if(i == TAILLEMAX-1){  // overflow
        res[i] = (bN1[i]+bN2[i]+res[i]) - 10;
        return 1;
      } else {
        res[i] = (bN1[i]+bN2[i]+res[i]) - 10;
        res[i+1] += 1;
      }
    //printf("fin i=%d bn!=%d bn2=%d res=%d\n",i,bN1[i],bN2[i],res[i]);
    }
  }
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
  bigInt bNTemp, bNTemp2, bNTemp3;
  bNTemp = initBigInt();
  bNTemp2 = initBigInt();
  bNTemp3 = initBigInt();
  int i, j, overflow = 0;
  for(i=0; i<getNbChiffreBigInt(bN1); i++){
    zeroBigInt(bNTemp);
    zeroBigInt(bNTemp2);
    zeroBigInt(bNTemp3);
    for(j=0; j<=(bN1[i]-1); j++){
      //bNTemp[j] = bN2[j] + bNTemp[j];
      addBigInt(bNTemp,bN2,bNTemp2);
      copyBigInt(bNTemp2,bNTemp);
    }
    for(j=0; j<i; j++){
      //bNTemp[j] = 10*bNTemp[j];
      times10BigInt(bNTemp,bNTemp2);
      copyBigInt(bNTemp2,bNTemp);
    } 
    overflow += addBigInt(res,bNTemp,bNTemp3);
    copyBigInt(bNTemp3,res);
  }
  freeBigInt(bNTemp);
  return overflow;
 }




int factorielleBigInt(bigInt bN1,bigInt res){
  int i;
  for(i=0; i<getNbChiffreBigInt(bN1); i++){
    
  }
}



