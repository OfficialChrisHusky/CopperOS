#include "Conversions.h"

#include "Libc/String.h"

void IntToASCII(int number, char* out) {

    int i, sign;
    if((sign = number) < 0) number = -number;

    i = 0;
    do {

        out[i++] = number % 10 + '0';

    } while((number /= 10) > 0);

    if(sign < 0) out[i++] = '-';
    out[i] = 0;

    reverse(out);

}