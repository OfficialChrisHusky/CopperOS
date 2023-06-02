#include "Drivers/Graphics.h"
#include "Drivers/Screen.h"
#include "Drivers/Ports.h"
#include "Drivers/Keyboard.h"

#include "Interrupts/ISR.h"

#include "Print.h"
#include "Timer.h"

void main() {

    InstallISR();
    ClearScreen(WHITE_ON_BLACK);
    PrintAt("Hello, World from inside the Kernel!\n", (COLS - 36) / 2, 0);

    asm volatile("sti");
    InitKeyboard();

    while(1) {

        //

    }

}

void DivisionByZero() {

    Print("WHAT ARE YOU DOING MY GUY");

}