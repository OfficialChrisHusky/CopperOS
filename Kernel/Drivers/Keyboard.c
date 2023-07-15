#include "Keyboard.h"
#include "Drivers/Ports.h"

#include "Libc/String.h"
#include "Libc/Function.h"

#include "Interrupts/ISR.h"

#include "Utils/Print.h"

#include "Core/Kernel.h"

#define BACKSPACE 0x0e
#define ENTER 0x1c

#define SCANCODE_MAX 57
const char* scancodeName[] = { "ERROR", "Esc", "1", "2", "3", "4", "5", "6", 
    "7", "8", "9", "0", "-", "=", "Backspace", "Tab", "Q", "W", "E", 
        "R", "T", "Y", "U", "I", "O", "P", "[", "]", "Enter", "Lctrl", 
        "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`", 
        "LShift", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".", 
        "/", "RShift", "Keypad *", "LAlt", "Spacebar"};
const char scancodeASCII[] = { '?', '?', '1', '2', '3', '4', '5', '6',     
    '7', '8', '9', '0', '-', '=', '?', '?', 'q', 'w', 'e', 'r', 't', 'z', 
        'u', 'i', 'o', 'p', '[', ']', '?', '?', 'a', 's', 'd', 'f', 'g', 
        'h', 'j', 'k', 'l', ';', '\'', '`', '?', '\\', 'y', 'x', 'c', 'v', 
        'b', 'n', 'm', ',', '.', '/', '?', '?', '?', ' '};

static char keyBuffer[256];

static void KeyboardCallback(Registers registers) {

    uint8 scancode = PortByteIn(0x60);

    if (scancode > SCANCODE_MAX) return;
    if (scancode == BACKSPACE) {

        backspace(keyBuffer);
        PrintBackspace();

    } else if (scancode == ENTER) {

        Print("\n");
        UserInput(keyBuffer);
        keyBuffer[0] = '\0';

    } else {

        char letter = scancodeASCII[(int) scancode];
        char str[2] = { letter, '\0' };

        append(keyBuffer, letter);
        Print(str);

    }

    UNUSED(registers);
    
}
void InitKeyboard() {
    
    RegisterInterruptHandler(IRQ1, KeyboardCallback);

}