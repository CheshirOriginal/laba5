#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "load.h"

#ifdef __linux__
    #define ADD_PREFIX_AND_SUFFIX(input) ("./" #input ".so")
#else
    #define ADD_PREFIX_AND_SUFFIX(input) ("" #input ".dll")
#endif


const int N1 = 35;
const int N2 = 9;
const int M = 8;

void input_array(int *mas, int N){
    printf("array: ");
    for (int i = 0; i < N; ++i)
        printf("%d ", mas[i]);
}

void input_matrix(int mas[][8], int N, int M){
    printf("matrix:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            printf("%d ", mas[i][j]);
        printf("\n");
    }
}

int main() {
    int A[N1], B[N2][M];
    int a=0,b=1;
void *l;
    srand(time(NULL));

    printf("Choose library:\n1-first(array).\n2-second(matrix),\n3-quit\n");
    while(b)
    {
        scanf("%d",&a);
        if(a==1){
            for (int i = 0; i < N1; ++i) {
                A[i] = rand()%101 - 50;
            }
            input_array(A, N1);
            ArrayFunction f1 = (ArrayFunction) Load(ADD_PREFIX_AND_SUFFIX(libARR), &l, "func1");
            f1(A, N1);
            closeLib(l);
            input_array(A, N1);


        }
        if(a==2){
            for (int i = 0; i < N2; ++i) {
                for (int j = 0; j < M; ++j) {
                    B[i][j] = rand()%101 - 50;
                }
            }
            input_matrix(B, N2, M);
            MatrixFunction f2 = (MatrixFunction) Load(ADD_PREFIX_AND_SUFFIX(libMAT), &l, "func2");
            f2(B, N2, M);
            closeLib(l);

            input_matrix(B, N2, M);

        }
        if(a==3)
            b=0;
    }


    system("pause");
    return 0;
}
