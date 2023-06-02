#pragma once

typedef unsigned int   uint32;
typedef          int    int32;
typedef unsigned short uint16;
typedef          short  int16;
typedef unsigned char  uint8;
typedef          char   int8;

#define  LOW16(addr) (uint16) ((addr) & 0xffff)
#define HIGH16(addr) (uint16) (((addr) >> 16) & 0xffff)