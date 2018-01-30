/*
 *  File:   test-dll.c
 *  Author: Brett Heithold
 */

#include "integer.h"
#include "dll.h"

int main(void) {

    DLL *items = newDLL(displayINTEGER, freeINTEGER);

    return 0;
}
