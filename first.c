#include "func.h"
#include <stdio.h>

void func(int mas[], int N){
    int max = mas[0];

    for (int i = 0; i < N; ++i)
        if(abs(mas[i]) > abs(max))
            max = mas[i];

    for (int i = 0; i < N; ++i)
        if(mas[i] == max)
            mas[i] *= -1;
}

void output_array(int mas[], int N){
    printf("array: ");
    for (int i = 0; i < N; ++i)
        printf("%d ", mas[i]);
}

void input_array(int mas[], int N){
    printf("Введите %d целых чисел:\n", N);
    for (int i = 0; i < N; i++) {
        printf("%d: ", i);
        scanf("%d", &mas[i]);
    }
}

