#pragma once

#include "Core/Types.h"

#define KERNEL_SELECTOR 0x08

typedef struct {
    
    uint16 offsetLow;
    uint16 selector;

    //THIS IS ALWAYS SUPPOSED TO BE ZERO!
    uint8 alwaysZeroDoNotUse;

    uint8 flags;
    uint16 offsetHigh;

} __attribute__((packed)) IDTGate;

typedef struct {

    uint16 limit;
    uint32 base;

} __attribute__ ((packed)) IDTRegister;

#define IDT_ENTRIES 256
IDTGate idt[IDT_ENTRIES];
IDTRegister idtRegister;

void SetIDTGate(uint32 index, uint32 handler);
void SetIDT();