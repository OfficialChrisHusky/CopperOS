#include "String.h"

uint32 strlen(char* str) {

    uint32 i = 0;
    while (str[i]) i++;
    return i;

}

void reverse(char* str) {

    int32 c, i, j;
    for(i = 0, j = strlen(str) - 1; i < j; i++, j--) {

        c = str[i];
        str[i] = str[j];
        str[j] = c;

    }
    
}
void backspace(char* str) {

    str[strlen(str) - 1] = '\0';

}
void append(char* str, char character) {

    uint32 len = strlen(str);
    str[len] = character;
    str[len + 1] = '\0';

}

int strcmp(char* s1, char* s2) {

    uint32 i;
    for(i = 0; s1[i] == s2[i]; i++) {

        if (s1[i] == '\0') return 0;

    }

    return s1[i] - s2[i];

}