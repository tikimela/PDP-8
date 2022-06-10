
#ifndef PDP_8_MEMORY_H
#define PDP_8_MEMORY_H
#define WORD_SIZE 16


int PC[12];

int I;
int OPR[3];
int MAR[12];

int MBR[WORD_SIZE];

int E;
int AC[16];

int RAM[4096][WORD_SIZE];

int F;
int R;
int SC [2] = {0,0};
int t[4] = {0, 0, 0, 0};
int FR[2] = {0,0};
int q[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int binToDec(int *bin, int n);



void CopyReg(int *a, int *b, int n, int m);
int AddressFetch();
void ReadMem();
void OprAssign();

#endif //PDP_8_MEMORY_H
