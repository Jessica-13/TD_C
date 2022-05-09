#include <stdio.h>
#define TAILLE 15
#define FALSE 0
#define TRUE 1


/*!
************************************************
* \brief verifie si une chaine de caractères de taille N
*   est un palindrome
* \param T tableau de N caractères (N>2)
* \param  N Taille du tableau 
* \result un entier (booleen)
**************************************************/    
int Palidrome (char T[], int N)
{int i,j;
 
//i est le pointeur sur le debut de la phrase 
//j est le pointeur sur la fin de la phrase, 
//on verifie que les lettres pointées par i et j sont les 
//mêmes. Si l'une des deux lettres est un blanc, on l'avale.
 i=0;
 j=N-1;
 while (i<=j) 
   { 
     if (T[i]==' ')
       i++;      //on avale les blanc en début
     else 
       if (T[j]==' ')
	 j--;     //on avale les blanc en fin
       else
	 if (T[i]!=T[j])
           {//on a deux caractères non blancs différents
	     return(FALSE);
	   }
	 else
	   { //on a deux caractères non blancs égaux
	     //on passe aux deux suivants:
	     i++;
	     j--;
	   }
   };
 // si on est arrivé la c'est que c'est un palyndrome.
 return(TRUE);
}


/*!
************************************************
* \brief  lit un tableau de TAILLE caractères au clavier
* détermine si c'est un palidrome
**************************************************/    
int main()
{int i;
 char input,T[TAILLE];

//lecture des TAILLE caractères au clavier 
 printf("Entrer %d caractères\n",TAILLE);
 for (i=0;i<TAILLE;i++)
   {
     scanf("%c",&input);
     T[i]=input;
   }


 //affichage du tableau
 printf("Tableau lu:\n");
 for (i=0;i<TAILLE;i++)
   {
     printf("%c",T[i]);
   }
 printf("\n");

 //est-ce un palindrome?
 if (Palidrome(T,TAILLE))
   printf("est un palindrome\n");
 else
   printf("n'est PAS un palindrome\n");
return(0);
}
