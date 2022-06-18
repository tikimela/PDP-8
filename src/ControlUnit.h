#include "Memory.h"
#include "Arithmetic.h"
#include "Decoder.h"
#include <stdbool.h>
#include "Logic.h"
#include "Asembler.h"
#include "math.h"

#ifndef PDP_8_CONTROLUNIT_H
#define PDP_8_CONTROLUNIT_H



void fetchCycle();
void indirectCycle();
void MemoryExecuteCycle();
void RegisterExecuteCycle();
void interruptCycle();
void MemoryOprPicker();
void RegisterOprPicker();

#endif //PDP_8_CONTROLUNIT_H
