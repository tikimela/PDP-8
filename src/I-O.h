
#ifndef PDP_8_I_O_H
#define PDP_8_I_O_H

#include "inttypes.h"
#define  _POSIX_C_SOURCE 200809L
#include "stdio.h"
#include "stdlib.h"
#include <ctype.h>
#include "Asembler.h"


void DumpMemory();
void LoadProgram();
int trimLeft(char **text, size_t *length);
int trimRight(const char *text, size_t *length);
void printn(const char* string, size_t length);

#endif //PDP_8_I_O_H
