#include "ControlUnit.h"

void fetchCycle(){
    if(t[0] == 1){
        AddressFetch();
    }
    else if(t[1] == 1){
        CopyReg(RAM[Address()],MBR,WORD_SIZE,0);
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
        CopyReg(RAM[Address()],MBR,WORD_SIZE,0);
    }
    else if(t[2] == 1){
    }
    else if(t[3] == 1){
        F = 1;
        R = 0;
    }
}

void executeCycle(){
    if(t[0] == 1){
        ValueFetch();
    }
    else if(t[1] == 1){
        CopyReg(RAM[Address()],MBR,WORD_SIZE,0);
    }
    else if(t[2] == 1){

    }
    else if(t[3] == 1){
        F = 0;
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
        E = add(AC,MBR,AC,0,WORD_SIZE);
    }
    else if(q[2] == 1){
        //LDA
        CopyReg(RAM[Address()],AC,WORD_SIZE,0);
    }
    else if(q[3] == 1){
        //STA
        CopyReg(AC,RAM[Address()],WORD_SIZE,0);
    }
    else if(q[4] == 1){
        //BUN
        CopyReg(MBR,PC,12,4);
    }
    else if(q[5] == 1){
        //BSA
        CopyReg(PC,RAM[Address()],12,0);
        increment(Address(),12);
        CopyReg(Address(),PC,12,0);
    }
    else if(q[6] == 1){
        //ISz
        increment(RAM[Address()],WORD_SIZE);
        if(RAM[Address()] == 0){
            increment(PC,12);
        }
    }
}