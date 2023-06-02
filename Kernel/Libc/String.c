#include "String.h"

uint32 strlen(char* str) {

    uint32 i = 0;
    while (str[i]) i++;
    return i;

}

void strrev(char* str) {

    int32 c, i, j;
    for(i = 0, j = strlen(str) - 1; i < j; i++, j--) {

        c = str[i];
        str[i] = str[j];
        str[j] = c;

    }
    
}