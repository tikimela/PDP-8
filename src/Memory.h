
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

#endif //PDP_8_MEMORY_H
