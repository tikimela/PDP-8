#ifndef PDP_8_ARITHMETIC_H
#define PDP_8_ARITHMETIC_H

#include "Logic.h"

typedef struct monoSumVal{
    int monoSum, monoCarry;
} monoSumVal;

typedef struct sumVal {
    int *sum;
    int carry;
} sumVal;

monoSumVal sum(int a, int b);

monoSumVal wholeSum(int a, int b, int carry);

int add(int *a, int *b, int *f, int carry, int n);

void increment(int *a,int n);

#endif //PDP_8_ARITHMETIC_H
