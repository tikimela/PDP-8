#include "Asembler.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Arithmetic.h"

bool indirect = false;
bool potrVred = false;
bool orgVred = false;
struct LabelList LabelList = {.laCount = -1};
int korakLabela = 0;
int DecHex = -1;
//ne zaboravi da ocistis labelu nedje

void addLabelAddress(char *label, int len, int address) {
    if(LabelList.laCount > LabelList.laSize / 2) {
        LabelList.laSize = LabelList.laSize + min(1000, LabelList.laSize);

        LabelAddress* labelAddresses = LabelList.labelAddresses;
        LabelList.labelAddresses = calloc(LabelList.laSize, sizeof(LabelAddress));
        for(size_t i = 0;i < LabelList.laCount;i++) {
            LabelList.labelAddresses[i] = labelAddresses[i];
        }
        free(labelAddresses);
    }
    LabelList.labelAddresses[LabelList.laCount].label = calloc(len, sizeof(char));
    strncpy(LabelList.labelAddresses[LabelList.laCount].label, label, len);
    LabelList.labelAddresses[LabelList.laCount].address = address;
    LabelList.laCount++;
}

void addProgramLabel(char *label, int len, int address) {
    if(LabelList.plCount > LabelList.plSize / 2) {
        LabelList.plSize = LabelList.plSize + min(1000, LabelList.plSize);

        LabelAddress* labelAddresses = LabelList.programLabels;
        LabelList.programLabels = calloc(LabelList.plSize, sizeof(LabelAddress));
        for(size_t i = 0;i < LabelList.plCount;i++) {
            LabelList.programLabels[i] = labelAddresses[i];
        }
        free(labelAddresses);
    }
    LabelList.programLabels[LabelList.plCount].label = calloc(len, sizeof(char));
    strncpy(LabelList.programLabels[LabelList.plCount].label, label, len);
    LabelList.programLabels[LabelList.plCount].address = address;
    LabelList.plCount++;
}

void printn2(const char* string, size_t length) {
    for(size_t i = 0;i < length;i++) {
        fputc(string[i], stdout);
    }
}

bool WordReader(char* line,int beginning, int end, int length, int address, int *pStartAddress, int *pAddress){
    if(LabelList.laCount == -1) {
        LabelList.laCount = 0;
        LabelList.laSize = 20;
        LabelList.labelAddresses = calloc(LabelList.laSize, sizeof(LabelAddress));

        LabelList.plCount = 0;
        LabelList.plSize = 20;
        LabelList.programLabels = calloc(LabelList.plSize, sizeof(LabelAddress));
    }
    char* word = &line[beginning];
    int len = end - beginning;

    if(orgVred) {
        potrVred = false;
        orgVred = false;

        *pStartAddress = StrToDec(word, len);
        *pAddress = *pStartAddress;

        return false;
    }
    else if(korakLabela == 1) {
        korakLabela = 2;

        if(CharCompare(word, "DEC", 3) == 1) {
            DecHex = 0;
        } else {
            DecHex = 1;
        }
        return false;
    }
    else if(korakLabela == 2) {
        korakLabela = 0;
        printn2(word, len);
        printf("\n");

        int binLen = 0;
        int *bin = StrToBin(word, len, DecHex, address, &binLen);
        int start = binLen > 12 ? binLen - 12 : 0;
        int ramStart = binLen > 12 ? 0 : 12 - binLen;
        printf("\nArray: ");
        printArray(bin, binLen);

        BinToRAM(&bin[start], ramStart + 4, binLen > 12 ? 12 : binLen, address);
        return true;
    }
    else if(line[end - 1] == '*'){
        indirect = true;
        OperationChecker(word,address);
        return false;
    }
    else if(line[end - 1] == ','){
        addLabelAddress(word, len, address);
        korakLabela = 1;
        return false;
    }
    else if(CharCompare(word, "DEC", 3)){
        korakLabela = 2;
        DecHex = 0;
        return false;
    }
    else if(CharCompare(word, "HEX", 3)){
        korakLabela = 2;
        DecHex = 1;
        return false;
    }
    else if(potrVred == true) {
        potrVred = false;
        if(IsNum(word,len)) {
            int binLen = 0;
            int *bin = StrToBin(word, len, 0, address, &binLen);
            int start = binLen > 12 ? binLen - 12 : 0;
            int ramStart = binLen > 12 ? 0 : 12 - binLen;

            BinToRAM(&bin[start], ramStart + 4, binLen > 12 ? 12 : binLen, address);
            return true;
        }
        else {
            addProgramLabel(word, len, address);
            return true;
        }
    }
    else {
        indirect = false;
        OperationChecker(word,address);

        return !potrVred;
    }
}

void LabelFixer(int startAddress) {
    for(int i = 0;i < LabelList.plCount;i++) {
        LabelAddress *pl = &LabelList.programLabels[i];
        int len = strnlen(pl->label, 255);
        for(int j = 0;j < LabelList.laCount;j++) {
            LabelAddress *la = &LabelList.labelAddresses[j];
            if(CharCompare(pl->label, la->label, len) == 1) {
                int address = startAddress + pl->address;

                int binLen = 0;
                int *bin = DecHexToBin(la->address, address, &binLen);
                int start = binLen > 12 ? binLen - 12 : 0;
                int ramStart = binLen > 12 ? 0 : 12 - binLen;

                BinToRAM(&bin[start], ramStart + 4, binLen > 12 ? 12 : binLen, address);
                break;
            }
        }
    }
}

void OperationChecker(char* opr, int address){
    potrVred = false;

    //memory opr
    if(CharCompare(opr,"AND",3) == 1){
        if(indirect == true){
            toRAM("1000000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        else{
            toRAM("0000000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        return;
    }
    else if(CharCompare(opr,"ADD",3) == 1){
        if(indirect == true){
            toRAM("1001000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        else{
            toRAM("0001000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        return;
    }
    else if(CharCompare(opr,"LDA",3) == 1){
        if(indirect == true){
            toRAM("1010000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        else{
            toRAM("0010000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        return;
    }
    else if(CharCompare(opr,"STA",3) == 1){
        if(indirect == true){
            toRAM("1011000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        else{
            toRAM("0011000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        return;
    }
    else if(CharCompare(opr,"BUN",3) == 1){
        if(indirect == true){
            toRAM("1100000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        else{
            toRAM("0100000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        return;
    }
    else if(CharCompare(opr,"BSA",3) == 1){
        if(indirect == true){
            toRAM("1101000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        else{
            toRAM("0101000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        return;
    }
    else if(CharCompare(opr,"ISZ",3) == 1){
        if(indirect == true){
            toRAM("1110000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        else{
            toRAM("0110000000000000",0,WORD_SIZE,address);
            potrVred = true;
        }
        return;
    }

    //reg opr

    if(CharCompare(opr,"CLA",3) == 1){
        toRAM("0111100000000000",0,WORD_SIZE,address);

    }
    else if(CharCompare(opr,"CLE",3) == 1){
        toRAM("0111010000000000,",0,WORD_SIZE,address);
    }
    else if(CharCompare(opr,"CMA",3) == 1){
        toRAM("0111001000000000",0,WORD_SIZE,address);
    }
    else if(CharCompare(opr,"CME",3) == 1){
        toRAM("0111000100000000",0,WORD_SIZE,address);
    }
    else if(CharCompare(opr,"CIR",3) == 1){
        toRAM("0111000010000000",0,WORD_SIZE,address);
    }
    else if(CharCompare(opr,"CIL",3) == 1){
        toRAM("0111000001000000",0,WORD_SIZE,address);
    }
    else if(CharCompare(opr,"INC",3) == 1){
        toRAM("0111000000100000",0,WORD_SIZE,address);
    }
    else if(CharCompare(opr,"SPA",3) == 1){
        toRAM("0111000000010000",0,WORD_SIZE,address);
    }
    else if(CharCompare(opr,"SNA",3) == 1){
        toRAM("0111000000001000",0,WORD_SIZE,address);
    }
    else if(CharCompare(opr,"SZA",3) == 1){
        toRAM("0111000000000100",0,WORD_SIZE,address);
    }
    else if(CharCompare(opr,"SZE",3) == 1){
        toRAM("0111000000000010",0,WORD_SIZE,address);
    }
    else if(CharCompare(opr,"HLT",3) == 1){
        toRAM("0111000000000001",0,WORD_SIZE,address);
    }

    if(CharCompare(opr,"ORG",3) == 1){
        potrVred = true;
        orgVred = true;
        return;
    }

    if(CharCompare(opr,"END",3) == 1){
        potrVred = false;
        return;
    }
}




int CharCompare(char* opr, char* opr2,int len){
    for(int i = 0; i < len; i++){
        if(opr[i] != opr2[i]) return 0;
    }
    return 1;
}

int IsNum(char* opr, int len){
    int br = 0;
    char* abc = "ABCDEFabcdef";

    int start = opr[0] == '-' ? 1 : 0;
    for(int j = start; j < len; j++){
        for(int i = 0; i < 10; i++){
            if(opr[j] - '0' == i) br++;
        }
    }
    if(br == len){
        return 1;
    }

    for(int j = start; j < len; j++){
        for(int i = 0; i < 12; i++){
            if(opr[j] == abc[i]) br++;
        }
    }


    if(br == len){
        return 1;
    }
    else{
        return 0;
    }
}

void toRAM(char* a,int pocetak, int n, int address){
    for(int i = pocetak; i < n; i++){
        RAM[address][i] = a[i] - '0';
    }
}

void BinToRAM(int* a, int pocetak, int n, int address){
    for(int i = 0; i < n; i++){
        RAM[address][i + pocetak] = a[i];
    }
}

void DecHexWord(char* word){
    bool isDec = false;
    bool isHex = false;
    char* dec = "DEC";
    char* hex = "HEX";
    for(int i = 0; i < 3; i++){
        if(word[i] != dec[i]){
            isDec = false;
        }
        else{
            isDec = true;
        }

        if(word[i] != hex[i]){
            isHex = false;
        }
        else{
            isHex = true;
        }
    }

    if(isDec == true){
        DecHex = 0;
    }
    else if(isHex == true){
        DecHex = 1;
    }
    potrVred = true;
}

char* toWord(char* a, int pocetak, int end){
    char* temp;
    for(int i = pocetak; i < end; i++){
        temp[i] = a[i];
    }
    return temp;
}

int HexToDec(char* word,int len) {
    int sum = 0;
    int end = word[0] == '-' ? 1 : 0;
    for(int i = len - 1;i >= end; i--){
        if('0' <= word[i] && word[i] <= '9'){
            sum += (word[i] - '0') * pow(16, len - 1 - i);
        }
        else if(word[i] == 'A' || word[i] == 'a'){
            sum += 10 * pow(16, len - 1 - i);
        }
        else if(word[i] == 'B' || word[i] == 'b'){
            sum += 11 * pow(16, len - 1 - i);
        }
        else if(word[i] == 'C' || word[i] == 'c'){
            sum += 12 * pow(16, len - 1 - i);
        }
        else if(word[i] == 'D' || word[i] == 'd'){
            sum += 13 * pow(16, len - 1 - i);
        }
        else if(word[i] == 'E' || word[i] == 'e'){
            sum += 14 * pow(16, len - 1 - i);
        }
        else if(word[i] == 'F' || word[i] == 'f'){
            sum += 15 * pow(16, len - 1 - i);
        }
    }

    if(end) sum = -sum;

    return sum;
}

int StrToDec(char* word,int len) {
    int sum = 0;
    int end = word[0] == '-' ? 1 : 0;
    for(int i = len - 1;i >= end; i--){
        sum += (word[i] - '0') * pow(10, len - 1 - i);
    }

    if(end) sum = -sum;

    return sum;
}

int* StrToBin(char* word, int len, int DecHex, int address, int *sumLen) {
    int sum = DecHex == 0 ? StrToDec(word, len) : HexToDec(word, len);
    printn2(word, len);
    printf(", StrToBin sum: %d\n", sum);
    return DecHexToBin(sum, address, sumLen);
}

int* DecHexToBin(int sum, int address, int *sumLen) {
    printf("Sum: %d\n", sum);
    int negative = sum < 0;
    if(negative) sum = - sum;
    *sumLen = 12;
    int* bin = calloc(*sumLen, sizeof(int));

    int k = 0;
    while(sum != 0){
        if(*sumLen - 1 - k < 0) break;
        bin[*sumLen - 1 - k] = sum % 2;
        sum = sum / 2;
        k++;
    }

    printf("[%d] BN: ", negative);
    printArray(bin, *sumLen);

    if(negative) {
        Complement(bin, *sumLen);
        increment(bin, *sumLen);
    }

    printf("AN: ");
    printArray(bin, *sumLen);

    return bin;
}

