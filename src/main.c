#include "PDP-8.h"
#include "getdel.h"

int main(int argc, char **argv) {

    if(argc > 1){
        Start(argv[1]);
    }
    else {
        UIStart();
    }



    return 0;
}
