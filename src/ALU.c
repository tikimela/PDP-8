#include <stdlib.h>
#include "ALU.h"
#include "logic.h"


monoSumVal wholeSum(int a, int b, int carry){
    //potpuni sabirac
//    z(x, y) = x XOR y XOR p
//    q(x, y) = [(x XOR y) AND p] OR [x AND y]

    monoSumVal c;
    c.monoSum = XOR(XOR(a, b), carry);
    c.monoCarry = OR(AND(XOR(a, b), carry), AND(a, b));
    return c;
}

int add(int *a, int *b, int *f, int carry, int n){
    for(int i = n; i >= 0; i--){
        monoSumVal d = wholeSum(a[i], b[i], carry);
        f[i] = d.monoSum;
        carry = d.monoCarry;
    }
    return carry;
}

void increment(int *a,int n){
    int b[n];
    for(int i = 0; i < n; i++){
        b[i] = 0;
    }
    b[n-1] = 1;

    add(a,b,a,0,n);
}
