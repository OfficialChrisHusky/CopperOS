#include "Ports.h"

unsigned char PortByteIn(unsigned short port) {
    
    unsigned char ret;
    __asm__("in %%dx, %%al" : "=a" (ret) : "d" (port));
    return ret;

}

void PortByteOut(unsigned short port, unsigned char data) {

    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));

}

unsigned short PortWordIn(unsigned short port) {

    unsigned short ret;
    __asm__("in %%dx, %%al" : "=a" (ret) : "d" (port));
    return ret;

}

void PortWordOut(unsigned short port, unsigned short data) {

    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));

}