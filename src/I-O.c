#include "I-O.h"
#include "Memory.h"

void DumpMemory(){
    FILE* file = fopen("Dump.bin","w");

    for(int i = 0; i < 4096; i++){

        uint16_t byte = 0;

        if(RAM[i][0] == 1){
            byte = byte | 1UL << 15;
        }
        if(RAM[i][1] == 1){
            byte = byte | 1UL << 14;
        }
        if(RAM[i][2] == 1){
            byte = byte | 1UL << 13;
        }
        if(RAM[i][3] == 1){
            byte = byte | 1UL << 12;
        }
        if(RAM[i][4] == 1){
            byte = byte | 1UL << 11;
        }
        if(RAM[i][5] == 1){
            byte = byte | 1UL << 10;
        }
        if(RAM[i][6] == 1){
            byte = byte | 1UL << 9;
        }
        if(RAM[i][7] == 1){
            byte = byte | 1UL << 8;
        }
        if(RAM[i][8] == 1){
            byte = byte | 1UL << 7;
        }
        if(RAM[i][9] == 1){
            byte = byte | 1UL << 6;
        }
        if(RAM[i][10] == 1){
            byte = byte | 1UL << 5;
        }
        if(RAM[i][11] == 1){
            byte = byte | 1UL << 4;
        }
        if(RAM[i][12] == 1){
            byte = byte | 1UL << 3;
        }
        if(RAM[i][13] == 1){
            byte = byte | 1UL << 2;
        }
        if(RAM[i][14] == 1){
            byte = byte | 1UL << 1;
        }
        if(RAM[i][15] == 1){
            byte = byte | 1UL << 0;
        }
        uint16_t result;
        result = byte >> 8;
        result += (byte & 0xFF) << 8;

        fwrite(&result, sizeof(uint16_t), 1, file);
    }

    fclose(file);

}

void LoadProgram() {
    FILE* file = fopen("Program.bin", "r");
    fseek(file, 0, SEEK_END);
    long FileLength = ftell(file);
    rewind(file);

    for(int i = 0; i < FileLength / 2; i++) {
        uint16_t byte = 0;
        fread(&byte, sizeof(uint16_t), 1, file);

        RAM[i][0] = (byte >> 7) & 1U;
        RAM[i][1] = (byte >> 6) & 1U;
        RAM[i][2] = (byte >> 5) & 1U;
        RAM[i][3] = (byte >> 4) & 1U;
        RAM[i][4] = (byte >> 3) & 1U;
        RAM[i][5] = (byte >> 2) & 1U;
        RAM[i][6] = (byte >> 1) & 1U;
        RAM[i][7] = (byte >> 0) & 1U;
        RAM[i][8] = (byte >> 15) & 1U;
        RAM[i][9] = (byte >> 14) & 1U;
        RAM[i][10] = (byte >> 13) & 1U;
        RAM[i][11] = (byte >> 12) & 1U;
        RAM[i][12] = (byte >> 11) & 1U;
        RAM[i][13] = (byte >> 10) & 1U;
        RAM[i][14] = (byte >> 9) & 1U;
        RAM[i][15] = (byte >> 8) & 1U;
    }

    fclose(file);
    S = true;
}