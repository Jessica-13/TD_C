#include <stdio.h>
#include <stdlib.h>

#include "type_bigInt.h"
#include "util_bigInt.h"
#include "io_bigInt.h"
#include "bigInt.h"


void  errorT(const char *mess)
{
  fprintf(stdout,"Error in testing: %s\n",mess);
  exit(-1);
}



void generateBinopFile(char *fileIn,char* fileOut,int (*func)(bigInt,bigInt,bigInt))
{
  FILE *fichIn,*fichOut;
  bigInt bN1,bN2,bN3;
  int finit=FALSE,chiffre;

  fichIn=fopen(fileIn,"r");
  if (fichIn==NULL) errorT("testOnFile: test file not found");
  fichOut=fopen(fileOut,"w");
  if (fichOut==NULL) errorT("testOnFile: test out file not found");
  

  

  while (!finit)
    {
      bN1=initBigInt();
      bN2=initBigInt();
      bN3=initBigInt();
      chiffre=readBigInt(fichIn,bN1);
      printBigInt(bN1);      
      chiffre=readBigInt(fichIn,bN2);
      printBigInt(bN2);      

      func(bN1,bN2,bN3);
      printBigInt(bN3);      
      
      writeBigInt(fichOut,bN1);
      writeBigInt(fichOut,bN2);
      writeBigInt(fichOut,bN3);
      fprintf(fichOut,"\n");
      freeBigInt(bN1);
      freeBigInt(bN2);
      freeBigInt(bN3);
      if (chiffre==EOF)
	finit=TRUE;
    }
  fprintf(stdout,"file %s generated...\n",fileOut);
  fclose(fichIn);
  fclose(fichOut);
}

void generateUnopFile(char *fileIn,char* fileOut,int (*func)(bigInt,bigInt))
{
  FILE *fichIn,*fichOut;
  bigInt bN1,bN2;
  int finit=FALSE,chiffre;

  fichIn=fopen(fileIn,"r");
  if (fichIn==NULL) errorT("testOnFile: test file not found");
  fichOut=fopen(fileOut,"w");
  if (fichOut==NULL) errorT("testOnFile: test out file not found");
  

  

  while (!finit)
    {
      bN1=initBigInt();
      bN2=initBigInt();
      chiffre=readBigInt(fichIn,bN1);
      printBigInt(bN1);      

      func(bN1,bN2);
      printBigInt(bN2);      
      
      writeBigInt(fichOut,bN1);
      writeBigInt(fichOut,bN2);
      fprintf(fichOut,"\n");
      freeBigInt(bN1);
      freeBigInt(bN2);
      if (chiffre==EOF)
	finit=TRUE;
    }
  fprintf(stdout,"file %s generated...\n",fileOut);
  fclose(fichIn);
  fclose(fichOut);
}

int main()
{
  fprintf(stdout,"generating Testfiles:\n ");
  //  testBinopFile("dataTestAdd.txt",addBigInt);
  //generateBinopFile("dataAddIn.txt","dataAddOut.txt",addBigInt);
  //generateBinopFile("dataMulIn.txt","dataMulOut.txt",mulBigInt);
  //testBinopFile("dataTestMul.txt",mulBigInt);
  generateUnopFile("dataFactorielleIn.txt","dataFactorielleOut.txt",factorielleBigInt);
  return(0);
}

