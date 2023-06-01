#include "Drivers/Graphics.h"
#include "Drivers/Screen.h"
#include "Drivers/Ports.h"

#include "Print.h"

void main() {

    ClearScreen();
    Print("Hello, World from inside the Kernel!", (COLS - 36) / 2, 0);

}