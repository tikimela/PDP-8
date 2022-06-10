#include "math.h"
#include "Memory.h"


void CopyReg(int *a, int *b, int n, int m){
    //kopira iz jednog u drugi registar
    //a - to be copied; b - copy; n - word length; m - from where to start copying
    for(int i = m; i < n + m; i++){
        b[i] = a[i];
    }
}

int binToDec(int *bin, int n){
    int dec, j = 0;
    for(int i =  n - 1; i > 0; i--){
        dec += bin[i] * pow(2, j);
        j++;
    }
    return dec;
}

int AddressFetch(){
    //uzima adresu iz PC i stavlja u MAR
    CopyReg(PC,MAR,12,0);
    int address = binToDec(MAR,12);
    return address;
}

void ReadMem(){
    //cita liniju koda iz RAM-a sa adrese iz MAR-a
    CopyReg(RAM[AddressFetch()],MBR,16,0);
}

void OprAssign(){
    CopyReg(MBR,I,1,0);
    CopyReg(MBR,OPR,3,1);
}


