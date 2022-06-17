#include "stdio.h"
#include <errno.h>
#include "stdlib.h"
#include "stdbool.h"
#include <string.h>

bool getLine(char **lineptr, size_t *n, FILE *stream) {
    if (*lineptr == NULL || *n == 0) {
        *n = 120;
        *lineptr = calloc(*n, sizeof(char));
        if (*lineptr == NULL) {
            return false;
        }
    } else {
        memset(*lineptr, 0, *n);
    }

    int c;
    size_t count = 0;
    while(true) {
        c = getc(stream);
        if(c == '\n' || c == EOF) {
            *n = count;
            return true;
        }
        (*lineptr)[count] = c;
        count++;

        if(count > *n / 2) {
            *n *= 2;
            char* last = *lineptr;
            *lineptr = calloc(*n, sizeof(char));
            if (*lineptr == NULL) {
                return false;
            }
            memcpy(*lineptr, last, count);
        }
    }
}