#include "Drivers/Graphics.h"
#include "Drivers/Screen.h"
#include "Drivers/Ports.h"

#include "Print.h"

void main() {

    ClearScreen(WHITE_ON_BLACK);
    Print("Hello, World from inside the Kernel!", (COLS - 36) / 2, 0, WHITE_ON_BLACK);

    while (1) {

        // Main OS loop

    }

}