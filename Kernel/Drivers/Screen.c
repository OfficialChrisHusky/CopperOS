#include "Screen.h"
#include "Drivers/Graphics.h"

void ClearScreen() {

    unsigned int size = COLS * ROWS;
    unsigned char* screen = (unsigned char*) VIDEO_MEMORY;

    unsigned int i;
    for(i = 0; i < size; i++) {

        screen[i * 2] = ' ';
        screen[i * 2 + 1] = WHITE_ON_BLACK;

    }

}