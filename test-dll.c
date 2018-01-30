/*
 *  File:   test-dll.c
 *  Author: Brett Heithold
 */

#include "integer.h"
#include "dll.h"

int main(void) {

    DLL *items = newDLL(displayINTEGER, freeINTEGER);

    insertDLL(items, 0, newINTEGER(1));
    insertDLL(items, 0, newINTEGER(9));
    insertDLL(items, 0, newINTEGER(2));
    insertDLL(items, 0, newINTEGER(6));
    insertDLL(items, 0, newINTEGER(5));

    displayDLL(items, stdout);
    printf("\n");

    return 0;
}
