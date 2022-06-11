#include "ControlUnit.h"


void boot(){
    while(S){
        Decoder2x4(SC,t,S);
        Decoder3x8(OPR,q,S);
        FR[0] = F;
        FR[1] = R;
        Decoder2x4(FR,c,S);

        if(c[0] == 1){
            fetchCycle();
        }
        else if(c[1] == 1){
            indirectCycle();
        }
        else if(c[2] == 1){
            if(q[7] == 1){
                RegisterExecuteCycle();
            }
            else{
                MemoryExecuteCycle();
            }
        }
        else if(c[3] == 1){
            interruptCycle();
        }
        increment(SC,2);
    }
}
