#pragma once

#define CURSOR_CTRL 0x3d4
#define CURSOR_DATA 0x3d5

unsigned char PortByteIn(unsigned short port);
void PortByteOut(unsigned short port, unsigned char data);

unsigned short PortWordIn(unsigned short port);
void PortWordOut(unsigned short port, unsigned short data);