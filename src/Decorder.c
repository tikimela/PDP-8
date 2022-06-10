#include "Decoder.h"

void Decoder2x4(int a[2],int b[4],int e){
    if (!a[0] && !a[1] && e == 1) {
        b[0] = 1;
    }
    else b[0] = 0;

    if (!a[0] && a[1] && e == 1) {
        b[1] = 1;
    }
    else b[1] = 0;

    if (a[0] && !a[1] && e == 1) {
        b[2] = 1;
    }
    else b[2] = 0;

    if (a[0] && a[1] && e == 1) {
        b[3] = 1;
    }
    else b[3] = 0;
}

void Decoder3x8(int a[3],int b[8], int e){
    if (!a[0] && !a[1] && !a[2] && e == 1) {
        b[0] = 1;
    }
    else b[0] = 0;

    if (!a[0] && !a[1] && a[2] && e == 1) {
        b[1] = 1;
    }
    else b[1] = 0;

    if (!a[0] && a[1] && !a[2] && e == 1) {
        b[2] = 1;
    }
    else b[2] = 0;

    if (!a[0] && a[1] && a[2] && e == 1) {
        b[3] = 1;
    }
    else b[3] = 0;

    if (a[0] && !a[1] && !a[2] && e == 1) {
        b[4] = 1;
    }
    else b[4] = 0;

    if (a[0] && !a[1] && a[2] && e == 1) {
        b[5] = 1;
    }
    else b[5] = 0;

    if (a[0] && a[1] && !a[2] && e == 1) {
        b[6] = 1;
    }
    else b[6] = 0;

    if (a[0] && a[1] && a[2] && e == 1) {
        b[7] = 1;
    }
    else b[7] = 0;
}
