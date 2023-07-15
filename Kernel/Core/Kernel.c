#include "Drivers/Graphics.h"
#include "Drivers/Screen.h"
#include "Drivers/Ports.h"
#include "Drivers/Keyboard.h"

#include "Interrupts/ISR.h"

#include "Libc/String.h"

#include "Utils/Print.h"
#include "Utils/Timer.h"

void main() {

    InstallISR();
    InstallIRQ();
    
    ClearScreen(WHITE_ON_BLACK);

    PrintAt("Hello, World from inside the Kernel!\n", (COLS - 36) / 2, 0);
    PrintAt("Type \'end\' to halt the cpu\n", (COLS - 26) / 2, 1);
    Print(">");

    while(1) {

        //

    }

}

void UserInput(char* input) {

    if (strcmp(input, "end") == 0) {

        Print("Stopping the CPU. Goodbye Cruel world!\n");
        asm volatile("hlt");

    }

    Print("You said: ");
    Print(input);
    Print("\n>");

}