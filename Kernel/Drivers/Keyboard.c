#include "Keyboard.h"
#include "Drivers/Ports.h"

#include "Interrupts/ISR.h"

#include "Print.h"

void PrintLetter(uint8 scancode);

static void KeyboardCallback(Registers registers) {

    uint8 scancode = PortByteIn(0x60);
    
    char* ascii;
    IntToASCII(scancode, ascii);
    Print("Keyboard scancode: ");
    Print(ascii);

    Print(", ");
    PrintLetter(scancode);

    Print("\n");

}
void InitKeyboard() {

    RegisterInterruptHandler(IRQ1, KeyboardCallback);

}

void PrintLetter(uint8 scancode) {

    switch (scancode) {

        case 0x0:
            Print("ERROR");
            break;
        case 0x1:
            Print("Escape");
            break;
        case 0x2:
            Print("1");
            break;
        case 0x3:
            Print("2");
            break;
        case 0x4:
            Print("3");
            break;
        case 0x5:
            Print("4");
            break;
        case 0x6:
            Print("5");
            break;
        case 0x7:
            Print("6");
            break;
        case 0x8:
            Print("7");
            break;
        case 0x9:
            Print("8");
            break;
        case 0x0A:
            Print("9");
            break;
        case 0x0B:
            Print("0");
            break;
        case 0x0C:
            Print("-");
            break;
        case 0x0D:
            Print("+");
            break;
        case 0x0E:
            Print("Backspace");
            break;
        case 0x0F:
            Print("Tab");
            break;
        case 0x10:
            Print("Q");
            break;
        case 0x11:
            Print("W");
            break;
        case 0x12:
            Print("E");
            break;
        case 0x13:
            Print("R");
            break;
        case 0x14:
            Print("T");
            break;
        case 0x15:
            Print("Y");
            break;
        case 0x16:
            Print("U");
            break;
        case 0x17:
            Print("I");
            break;
        case 0x18:
            Print("O");
            break;
        case 0x19:
            Print("P");
            break;
		case 0x1A:
			Print("[");
			break;
		case 0x1B:
			Print("]");
			break;
		case 0x1C:
			Print("Enter");
			break;
		case 0x1D:
			Print("Left Ctrl");
			break;
		case 0x1E:
			Print("A");
			break;
		case 0x1F:
			Print("S");
			break;
        case 0x20:
            Print("D");
            break;
        case 0x21:
            Print("F");
            break;
        case 0x22:
            Print("G");
            break;
        case 0x23:
            Print("H");
            break;
        case 0x24:
            Print("J");
            break;
        case 0x25:
            Print("K");
            break;
        case 0x26:
            Print("L");
            break;
        case 0x27:
            Print(";");
            break;
        case 0x28:
            Print("'");
            break;
        case 0x29:
            Print("`");
            break;
		case 0x2A:
			Print("Left Shift");
			break;
		case 0x2B:
			Print("\\");
			break;
		case 0x2C:
			Print("Z");
			break;
		case 0x2D:
			Print("X");
			break;
		case 0x2E:
			Print("C");
			break;
		case 0x2F:
			Print("V");
			break;
        case 0x30:
            Print("B");
            break;
        case 0x31:
            Print("N");
            break;
        case 0x32:
            Print("M");
            break;
        case 0x33:
            Print(",");
            break;
        case 0x34:
            Print(".");
            break;
        case 0x35:
            Print("/");
            break;
        case 0x36:
            Print("Righ shift");
            break;
        case 0x37:
            Print("Keypad *");
            break;
        case 0x38:
            Print("Left Alt");
            break;
        case 0x39:
            Print("Space");
            break;
        default:
            if (scancode <= 0x7f) {

                Print("Unknown key down");

            } else if (scancode <= 0x39 + 0x80) {

                Print("Key up ");
                PrintLetter(scancode - 0x80);

            } else
                Print("Unknown key up");

            break;
    }

}