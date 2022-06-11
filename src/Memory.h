
#ifndef PDP_8_MEMORY_H
#define PDP_8_MEMORY_H
#define WORD_SIZE 16 //google kaze da je PDP - 8 12bit - ni racunar a ne 16 te za svaki slucaj da mogu da promijenim

#include "stdbool.h"

extern int PC[12];

extern int I;
extern int OPR[3];
extern int MAR[12];

extern int MBR[WORD_SIZE];

extern int E;
extern int AC[WORD_SIZE];

extern int RAM[4096][WORD_SIZE];

extern bool S;
extern int F;
extern int R;
extern int SC[2];
extern int t[4];
extern int FR[2];
extern int q[8];
extern int c[4];


int binToDec(int *bin, int n);
void CopyReg(int *a, int *b, int n);
void AddressFetch();
void ValueFetch();
int Address();
//void ReadMem();
void OprAssign();
int IsZero(int *a, int n);
void Clear(int *a, int n);
void Complement(int *a, int n);
void CirculateShift(int n);
int IsPositive(int *a);

#endif //PDP_8_MEMORY_H
