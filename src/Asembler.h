

#ifndef PDP_8_ASEMBLER_H
#define PDP_8_ASEMBLER_H

#include <stdbool.h>
#include "ControlUnit.h"

bool WordReader(char* line,int beginning, int end, int length, int address, int *pStartAddress, int *pAddress);
void LabelFixer(int startAddress);
void OperationChecker(char* opr, int address);
int CharCompare(char* opr, char* opr2,int len);
char* toWord(char* a, int pocetak, int n);
int IsNum(char* opr, int len);
void toRAM(char* a,int pocetak, int n, int address);
void BinToRAM(int* a, int pocetak, int n, int address);
void DecHexWord(char* word);
int StrToDec(char* word,int len);
int HexToDec(char* word,int len);

int* StrToBin(char* word, int len, int DecHex, int address, int *sumLen);
int* DecHexToBin(int sum, int address, int *sumLen);


typedef struct LabelAddress {
    char *label;
    int address;
} LabelAddress;

struct LabelList {
    LabelAddress* labelAddresses;
    int laCount;
    int laSize;

    LabelAddress* programLabels;
    int plCount;
    int plSize;
};

extern bool indirect;
extern struct LabelList LabelList;
extern bool potrVred;
extern bool orgVred;
extern int DecHex;
#endif //PDP_8_ASEMBLER_H
