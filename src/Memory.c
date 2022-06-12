#include "math.h"
#include "Memory.h"

int PC[12];

int I;
int OPR[3];
int MAR[12];

int MBR[WORD_SIZE];

int E;
int AC[WORD_SIZE];

int RAM[4096][WORD_SIZE];

bool S = false;
int F;
int R;
int SC [2] = {0,0};
int t[4] = {0, 0, 0, 0};
int FR[2] = {0,0};
int q[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int c[4] = {0, 0, 0, 0};
bool isThereFile = false;

void CopyReg(int *a, int *b, int n){
    //kopira iz jednog u drugi registar
    //a - to be copied; b - copy; n - word length;
    for(int i = 0; i < n; i++){
        b[i] = a[i];
    }
}

int binToDec(int *bin, int n){
    int dec = 0, j = 0;
    for(int i =  n - 1; i > 0; i--){
        dec += bin[i] * pow(2, j);
        j++;
    }
    return dec;
}

void AddressFetch(){
    //uzima adresu iz PC i stavlja u MAR
    CopyReg(PC,MAR,12);
}

void ValueFetch(){
    //for indirect cycle
    CopyReg(&MBR[4],MAR,12);
}

int Address(){
    int address = binToDec(MAR,12);
    return address;
}

int IsZero(int *a, int n){
    for(int i = 0; i < n; i++){
        if(a[i] != 0){
            return 0;
        }
    }
    return 1;
}

/*void ReadMem(function()){
    //cita liniju koda iz RAM-a sa adrese iz MAR-a
    CopyReg(RAM[AddressFetch()],MBR,16,0);
}*/

void OprAssign(){
    CopyReg(MBR,&I,1);
    CopyReg(&MBR[1],OPR,3);
}

void Clear(int *a, int n){
    for(int i = 0; i < n; i++){
        a[i] = 0;
    }
}

void ClearMem(){
    for(int i = 0; i < 4096; i++){
        for(int j = 0; j < WORD_SIZE; j++){
            RAM[i][j] = 0;
        }
    }
    Clear(PC,12);
    Clear(OPR,3);
    Clear(MAR,12);
    Clear(MBR,WORD_SIZE);
    Clear(AC,WORD_SIZE);
    Clear(SC,2);
    Clear(t,4);
    Clear(FR,2);
    Clear(q,8);
    Clear(c,4);
    I = 0;
    E = 0;
    F = 0;
    R = 0;
    isThereFile = false;
}

void Complement(int *a, int n){
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            a[i] = 0;
        }
        else{
            a[i] = 1;
        }
    }
}

void CirculateShift(int n){
    //n - 0 right, n - 1 left
    int b [WORD_SIZE];

    if(n == 0){
        b[0] = E;
        E = AC[WORD_SIZE - 1];

        for(int i = 1; i < WORD_SIZE ; i++){
            b[i] = AC[i-1];
        }
    }
    else if(n == 1){
        b[WORD_SIZE-1] = E;
        E = AC[0];

        for(int i = 0; i < WORD_SIZE - 1; i++){
            b[i] = AC[i+1];
        }
    }

    CopyReg(b,AC,WORD_SIZE);
}

int IsPositive(int *a){
    if(a[0] == 0){
        return 1;
    }
    else{
        return 0;
    }
}



