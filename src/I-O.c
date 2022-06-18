#include "I-O.h"
#include "Memory.h"
#include "getdel.h"
#include <string.h>

void printArray(int *arr, int n) {
    for(int i = 0;i < n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void DumpMemory(char *output){
    FILE* file = fopen(output,"w");

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
        uint16_t result = 0;
        result = byte >> 8;
        result += (byte & 0xFF) << 8;

        if(i < 12) {
            printf("Result: %6" PRIu16 ", byte: %6" PRIu16 ", Bytes: ", result, byte);
            printArray(RAM[i], WORD_SIZE);
        }

        fwrite(&result, sizeof(uint16_t), 1, file);
    }

    fclose(file);
    isThereFile = false;
}

void LoadProgram(char *input) {
    isThereFile = true;
    FILE *in = fopen(input, "r");

    char *lineStart = NULL;
    size_t length = 0;

    int startAddress = 0;
    int address = startAddress;

    while(getLine(&lineStart, &length, in)) {
        char *line = lineStart;
        trimRight(line, &length);
        if(length == 0) continue;
        trimLeft(&line, &length);

        size_t start = 0;
        for(size_t i = 0;i < length;i++) {
            if(i > 0 && line[i - 1] == ',' && !isspace(line[i])) {
                if(WordReader(line, start, i, length, address, &startAddress, &address)) address++;
                start = i;
                continue;
            }

            if(!isspace(line[i])) continue;
            if(WordReader(line, start, i, length, address, &startAddress, &address)) address++;
            start = i + 1;
        }
        if(WordReader(line, start, length, length, address, &startAddress, &address)) address++;
    }

    LabelFixer(startAddress);

    fclose(in);
    isThereFile = true;
    S = true;
}

int trimLeft(char **text, size_t *length) {
    size_t i = 0;
    while(isspace((*text)[0]) && *length) {
        (*text)++;
        (*length)--;
        i++;
    }
    return i;
}
int trimRight(const char *text, size_t *length) {
    if(*length == 0) return 0;
    size_t i = 0;
    while(isspace(text[*length - 1]) && *length) {
        (*length)--;
        i++;
    }
    return i;
}

void printn(const char* string, size_t length) {
    for(size_t i = 0;i < length;i++) {
        fputc(string[i], stdout);
    }
}