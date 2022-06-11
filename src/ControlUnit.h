#include "Memory.h"
#include "ALU.h"
#include "Decoder.h"
#include <stdbool.h>

#ifndef PDP_8_CONTROLUNIT_H
#define PDP_8_CONTROLUNIT_H

bool S = false;

void fetchCycle();
void indirectCycle();
void executeCycle();
void interruptCycle();

#endif //PDP_8_CONTROLUNIT_H
