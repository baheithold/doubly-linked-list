/*
 *  File:   test-dll.c
 *  Author: Brett Heithold
 */

#include "integer.h"
#include "dll.h"

int main(void) {

    DLL *recipient = newDLL(displayINTEGER, freeINTEGER);
    DLL *donor = newDLL(displayINTEGER, freeINTEGER);

    insertDLL(recipient, sizeDLL(recipient), newINTEGER(1));
    insertDLL(recipient, sizeDLL(recipient), newINTEGER(2));
    insertDLL(recipient, sizeDLL(recipient), newINTEGER(3));
    insertDLL(donor, sizeDLL(donor), newINTEGER(4));
    insertDLL(donor, sizeDLL(donor), newINTEGER(5));
    insertDLL(donor, sizeDLL(donor), newINTEGER(6));

    printf("Recipient before union: ");
    displayDLL(recipient, stdout);
    printf("\n");
    printf("Donor before union: ");
    displayDLL(donor, stdout);
    printf("\n");

    unionDLL(recipient, donor);
    printf("Recipient after union: ");
    displayDLL(recipient, stdout);
    printf("\n");
    printf("Donor after union: ");
    displayDLL(donor, stdout);
    printf("\n");

    freeDLL(recipient);
    freeDLL(donor);
    return 0;
}
