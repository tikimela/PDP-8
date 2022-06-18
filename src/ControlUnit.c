#include "ControlUnit.h"

void fetchCycle(){
    if(t[0] == 1){
        AddressFetch();
    }
    else if(t[1] == 1){
        CopyReg(RAM[Address()],MBR,WORD_SIZE);
        increment(PC,12);
    }
    else if(t[2] == 1){
        OprAssign();
    }
    else if(t[3] == 1){
        if(q[7] == 1 && I == 1){
            R = 1;
        }
        else{
            F = 1;
        }
    }
}

void indirectCycle(){
    if(t[0] == 1){
        ValueFetch();
    }
    else if(t[1] == 1){
        CopyReg(RAM[Address()],MBR,WORD_SIZE);
    }
    else if(t[2] == 1){
    }
    else if(t[3] == 1){
        F = 1;
        R = 0;
    }
}

void MemoryExecuteCycle(){
    if(t[0] == 1){
        ValueFetch();
    }
    else if(t[1] == 1){
        CopyReg(RAM[Address()],MBR,WORD_SIZE);
    }
    else if(t[2] == 1){
        MemoryOprPicker();
    }
    else if(t[3] == 1){
        F = 0;
    }
}

void RegisterExecuteCycle(){

    if(t[3] != 1) {
        return;
    }
    else{
        RegisterOprPicker();
    }
}


void interruptCycle(){

}

void MemoryOprPicker(){
    if(q[0] == 1){
        //AND
        for(int i = 0; i < WORD_SIZE; i++){
            AC[i] = AND(MBR[i],AC[i]);
        }
    }
    else if(q[1] == 1){
        //ADD
        E = add(&AC[4],&MBR[4],&AC[4],0,12);
    }
    else if(q[2] == 1){
        //LDA
        CopyReg(RAM[Address()],AC,WORD_SIZE);
    }
    else if(q[3] == 1){
        //STA
        CopyReg(AC,RAM[Address()],WORD_SIZE);
    }
    else if(q[4] == 1){
        //BUN
        CopyReg(&MBR[4],PC,12);
    }
    else if(q[5] == 1){
        //BSA
        CopyReg(PC,RAM[Address()]+4,12);
        increment(MAR,12);
        CopyReg(MAR,PC,12);
    }
    else if(q[6] == 1){
        //ISz
        increment(RAM[Address()],WORD_SIZE);
        if(IsZero(RAM[Address()],WORD_SIZE) == 1){
            increment(PC,12);
        }
    }
}

void RegisterOprPicker(){

    if(MBR[4] == 1){
        //CLA
        Clear(AC,WORD_SIZE);
    }
    else if(MBR[5] == 1){
        //CLE
        E = 0;
    }
    else if(MBR[6] == 1){
        //CMA
        Complement(AC,WORD_SIZE);
    }
    else if(MBR[7] == 1){
        //CME
        Complement(&E,1);
    }
    else if(MBR[8] == 1){
        //CIR
        CirculateShift(0);
    }
    else if(MBR[9] == 1){
        //CIL
        CirculateShift(1);
    }
    else if(MBR[10] == 1){
        //INC
        increment(AC,WORD_SIZE);
    }
    else if(MBR[11] == 1){
        //SPA
        if(IsPositive(AC) == 1){
            increment(PC,12);
        }
    }
    else if(MBR[12] == 1){
        //SNA
        if(IsPositive(AC) == 0){
            increment(PC,12);
        }
    }
    else if(MBR[13] == 1){
        //SZA
        if(IsZero(AC,WORD_SIZE)){
            increment(PC,12);
        }
    }
    else if(MBR[14] == 1){
        //SZE
        if(E == 0){
            increment(PC,12);
        }
    }
    else if(MBR[15] == 1){
        //HLT
        S = false;
    }
}