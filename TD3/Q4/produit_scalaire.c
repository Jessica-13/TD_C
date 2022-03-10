// Q4 : fonction qui calcule le produit scalaire de deux vecteurs entier de taille N
#include <stdio.h>

#define N 5

int produit_scalaire(int A[N], int B[N]){

    int RP = 0;
    
    for (int i = 0; i<N; i++){
        RP += A[i]*B[i];
    }

    return RP;
}

int main(){

    int A[N] = {1,1,1,1,1};
    int B[N] = {3,3,3,3,3};
    int RPF = produit_scalaire(A, B);
    printf("Le résultat du produit scalaire de A*B = %d\n", RPF);

    return 0;
}