#include <stdio.h>

int main(){
    int M=4;
    int i,J;
    int A[4][4];
    A[0][0]=2;
    A[0][1]=4;
    A[0][2]=6;
    A[0][3]=8;
    A[1][0]=5;
    A[1][1]=6;
    A[1][2]=7;
    A[1][3]=8;
    A[2][0]=8;
    A[2][1]=6;
    A[2][2]=4;
    A[2][3]=2;
    A[3][0]=8;
    A[3][1]=7;
    A[3][2]=6;
    A[3][3]=5;

    for (i=0;i<M;i++) {
        A[i][i]=1;
        A[i][M-i-1]=1;
    }
    printf("-------------------------\n");
    
    for (i = 0; i < M; i++)
    {
        for (J = 0; J < M; J++)
        {
            printf("%d ", A[i][J]);
        }
        printf("\n");
    }
    return 0;
}