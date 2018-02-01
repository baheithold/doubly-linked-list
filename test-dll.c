/*
 *  File:   test-dll.c
 *  Author: Brett Heithold
 */

#include "integer.h"
#include "dll.h"

int main(void) {

    DLL *items = newDLL(displayINTEGER, freeINTEGER);

    insertDLL(items, sizeDLL(items), newINTEGER(5));
    insertDLL(items, sizeDLL(items), newINTEGER(6));
    insertDLL(items, sizeDLL(items), newINTEGER(2));
    insertDLL(items, sizeDLL(items), newINTEGER(9));
    insertDLL(items, sizeDLL(items), newINTEGER(1));

    INTEGER *i = removeDLL(items, 0);
    freeINTEGER(i);

    printf("List Size: %d\n", sizeDLL(items));
    displayDLL(items, stdout);
    printf("\n");

    freeDLL(items);
    return 0;
}
