#include "func.h"
#include <stdio.h>

void func2(int mas[0][8], int N, int M){

    for (int i = 0; i < M; ++i) {
        int max = mas[i][0];

        for (int j = 0; j < N; ++j)
            if(abs(mas[i][j]) > abs(max))
                max = mas[i][j];

        for (int j = 0; j < N; ++j)
            if(mas[i][j] == max)
                mas[i][j] *= -1;
    }
}