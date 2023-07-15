#include "Timer.h"

#include "Drivers/Ports.h"

#include "Interrupts/ISR.h"

#include "Libc/Function.h"

#include "Utils/Conversions.h"
#include "Utils/Print.h"

uint32 tick = 0;
static void TimerCallback(Registers registers) {

    tick++;
    UNUSED(registers);
    
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