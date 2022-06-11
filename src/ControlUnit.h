#include "Memory.h"
#include "Arithmetic.h"
#include "Decoder.h"
#include <stdbool.h>
#include "Logic.h"

#ifndef PDP_8_CONTROLUNIT_H
#define PDP_8_CONTROLUNIT_H

bool S = false;

void fetchCycle();
void indirectCycle();
void executeCycle();
void interruptCycle();

#endif //PDP_8_CONTROLUNIT_H
