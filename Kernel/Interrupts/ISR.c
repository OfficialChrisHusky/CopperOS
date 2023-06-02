#include "ISR.h"
#include "Interrupts/IDT.h"

#include "Utils/Conversions.h"

#include "Print.h"

char* exceptionMessages[32] = {

    "Division by zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"

};

void InstallISR() {

    SetIDTGate( 0, (uint32) isr0);
    SetIDTGate( 1, (uint32) isr1);
    SetIDTGate( 2, (uint32) isr2);
    SetIDTGate( 3, (uint32) isr3);
    SetIDTGate( 4, (uint32) isr4);
    SetIDTGate( 5, (uint32) isr5);
    SetIDTGate( 6, (uint32) isr6);
    SetIDTGate( 7, (uint32) isr7);
    SetIDTGate( 8, (uint32) isr8);
    SetIDTGate( 9, (uint32) isr9);
    SetIDTGate(10, (uint32) isr10);
    SetIDTGate(11, (uint32) isr11);
    SetIDTGate(12, (uint32) isr12);
    SetIDTGate(13, (uint32) isr13);
    SetIDTGate(14, (uint32) isr14);
    SetIDTGate(15, (uint32) isr15);
    SetIDTGate(16, (uint32) isr16);
    SetIDTGate(17, (uint32) isr17);
    SetIDTGate(18, (uint32) isr18);
    SetIDTGate(19, (uint32) isr19);
    SetIDTGate(20, (uint32) isr20);
    SetIDTGate(21, (uint32) isr21);
    SetIDTGate(22, (uint32) isr22);
    SetIDTGate(23, (uint32) isr23);
    SetIDTGate(24, (uint32) isr24);
    SetIDTGate(25, (uint32) isr25);
    SetIDTGate(26, (uint32) isr26);
    SetIDTGate(27, (uint32) isr27);
    SetIDTGate(28, (uint32) isr28);
    SetIDTGate(29, (uint32) isr29);
    SetIDTGate(30, (uint32) isr30);
    SetIDTGate(31, (uint32) isr31);

    SetIDT();

}

void ISRHandler(Registers registers) {

    Print("Received interrupt ");
    
    char interruptNum[3];
    IntToASCII(registers.interruptNum, interruptNum);
    Print(interruptNum);
    Print(": ");

    Print(exceptionMessages[registers.interruptNum]);
    Print("\n");

}