#include "I-O.h"
#include "Memory.h"

void DumpMemory(){

    FILE* file = fopen("Dump.bin","w");

    for(int i = 0; i < 4096 * WORD_SIZE; i = i+8){

        uint8_t byte = 0;

        if(RAM[i+0] == 1){
            byte = byte | 1UL << 7;
        }
        if(RAM[i+1] == 1){
            byte = byte | 1UL << 6;
        }
        if(RAM[i+2] == 1){
            byte = byte | 1UL << 5;
        }
        if(RAM[i+3] == 1){
            byte = byte | 1UL << 4;
        }
        if(RAM[i+4] == 1){
            byte = byte | 1UL << 3;
        }
        if(RAM[i+5] == 1){
            byte = byte | 1UL << 2;
        }
        if(RAM[i+6] == 1){
            byte = byte | 1UL << 1;
        }
        if(RAM[i+7] == 1){
            byte = byte | 1UL << 0;
        }
    }

    fclose(file);

}

