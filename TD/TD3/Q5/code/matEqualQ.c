#include <stdio.h>
#include <stdbool.h>


#define N 15

bool matEqualQ(int A[N][N], int B[N][N]){

    bool resTest = false;
    int test = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i][j] != B[i][j]){
                test ++;
            }
        }
    }
    if(resTest == 0){
        resTest = true;
    }
    return resTest;
}