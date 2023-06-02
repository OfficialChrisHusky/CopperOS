#include "Timer.h"

#include "Utils/Conversions.h"

#include "Drivers/Ports.h"

#include "Interrupts/ISR.h"

#include "Print.h"

uint32 tick = 0;
static void TimerCallback(Registers registers) {

    tick++;
    Print("Tick: ");

    char tickStr[256];
    IntToASCII(tick, tickStr);
    Print(tickStr);
    Print("\n");
    
}

void InitTimer(uint32 frequency) {
    
    RegisterInterruptHandler(IRQ0, TimerCallback);

    uint32 divisor = 1193180 / frequency;
    uint8 low  = (uint8) (divisor & 0xff);
    uint8 high = (uint8) ((divisor >> 8) & 0xff);

    PortByteOut(0x43, 0x36);
    PortByteOut(0x40, low);
    PortByteOut(0x40, high);

}