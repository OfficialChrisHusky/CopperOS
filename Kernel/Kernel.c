#include "Drivers/Ports.h"

void main() {

    PortByteOut(0x3d4, 14);
    int position = PortByteIn(0x3d5);
    position = position << 8;

    PortByteOut(0x3d4, 15);
    position += PortByteIn(0x3d5);

    int offsetFromVGA = position * 2;

    char* videoMemory = (char*) 0xb8000;
    videoMemory[offsetFromVGA] = 'X';
    videoMemory[offsetFromVGA + 1] = 0x0f;
    *videoMemory = 'H'; videoMemory += 2;
    *videoMemory = 'e'; videoMemory += 2;
    *videoMemory = 'l'; videoMemory += 2;
    *videoMemory = 'l'; videoMemory += 2;
    *videoMemory = 'o'; videoMemory += 2;
    *videoMemory = ','; videoMemory += 2;
    *videoMemory = ' '; videoMemory += 2;
    *videoMemory = 'W'; videoMemory += 2;
    *videoMemory = 'o'; videoMemory += 2;
    *videoMemory = 'r'; videoMemory += 2;
    *videoMemory = 'l'; videoMemory += 2;
    *videoMemory = 'd'; videoMemory += 2;
    *videoMemory = ' '; videoMemory += 2;
    *videoMemory = 'f'; videoMemory += 2;
    *videoMemory = 'r'; videoMemory += 2;
    *videoMemory = 'o'; videoMemory += 2;
    *videoMemory = 'm'; videoMemory += 2;
    *videoMemory = ' '; videoMemory += 2;
    *videoMemory = 't'; videoMemory += 2;
    *videoMemory = 'h'; videoMemory += 2;
    *videoMemory = 'e'; videoMemory += 2;
    *videoMemory = ' '; videoMemory += 2;
    *videoMemory = 'k'; videoMemory += 2;
    *videoMemory = 'e'; videoMemory += 2;
    *videoMemory = 'r'; videoMemory += 2;
    *videoMemory = 'n'; videoMemory += 2;
    *videoMemory = 'e'; videoMemory += 2;
    *videoMemory = 'l'; videoMemory += 2;
    *videoMemory = '!'; videoMemory += 2;

}