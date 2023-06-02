#include "Drivers/Graphics.h"
#include "Drivers/Screen.h"
#include "Drivers/Ports.h"

#include "Interrupts/ISR.h"

#include "Print.h"

void main() {

    InstallISR();
    ClearScreen(WHITE_ON_BLACK);
    PrintAt("Hello, World from inside the Kernel!\n", (COLS - 36) / 2, 0);

    __asm__ __volatile__("int $0");
    Print("Test after Interrup 0!\n");
    __asm__ __volatile__("int $2");
    __asm__ __volatile__("int $3");

    while (1) {

        // Main OS loop

    }

}

void DivisionByZero() {

    Print("WHAT ARE YOU DOING MY GUY");

}