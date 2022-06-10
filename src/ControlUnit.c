#include "ControlUnit.h"

void boot(){
    while(S){
        Decoder2x4(SC,t,S);
        Decoder3x8(OPR,q,S);
    }
}

