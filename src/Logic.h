
#ifndef PDP_8_LOGIC_H
#define PDP_8_LOGIC_H

//osnovna logicka kola

int AND(int a, int b){
    if(a == 1 && b == 1) return 1;
    else return 0;
}

int OR(int a, int b){
    if(a == 1 || b == 1) return 1;
    else return 0;
}

int NOT(int a){
    if(a == 0) return 1;
    else return 0;
}

int NAND(int a, int b){
    return NOT(AND(a,b));
}

int NOR(int a, int b){
    return NOT(OR(a,b));
}

int XOR(int a, int b){
    if(a == 1 && b == 1) return 0;
    else if(a == 0 && b == 0) return 0;
    else return 1;
}

int XNOR(int a, int b){
    return NOT(XOR(a,b));
}

#endif //PDP_8_LOGIC_H
