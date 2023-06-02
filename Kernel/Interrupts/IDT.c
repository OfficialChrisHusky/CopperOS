#include "IDT.h"

void SetIDTGate(uint32 index, uint32 handler) {

    idt[index].offsetLow = LOW16(handler);
    idt[index].selector = KERNEL_SELECTOR;
    idt[index].alwaysZeroDoNotUse = 0;
    idt[index].flags = 0x8e;
    idt[index].offsetHigh = HIGH16(handler);

}

void SetIDT() {

    idtRegister.base = (uint32) &idt;
    idtRegister.limit = IDT_ENTRIES * sizeof(IDTGate) - 1;

    __asm__ __volatile__("lidtl (%0)" : : "r" (&idtRegister));

}