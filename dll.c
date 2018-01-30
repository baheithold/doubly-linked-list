/*
 * File:    dll.c
 * Author:  Brett Heithold
 */

#include "dll.h"

typedef struct node {
    void *value;
    struct node *next;
    struct node *prev;
} NODE;

NODE *newNODE(void *value, NODE *next, NODE *prev) {
    NODE *n = malloc(sizeof(NODE));
    assert(n != 0);
    n->value = value;
    n->next = next;
    n->prev = prev;
    return n;
}

// Private DLL method prototypes
static void addToFront(DLL *items, void *value);

struct DLL {
    NODE *head;
    int size;

    // Public methods
    void (*display)(void *, FILE *);
    void (*free)(void *);
    
    // Private methods
    void (*addToFront)(DLL *, void *);
};

DLL *newDLL(void (*d)(void *, FILE *), void (*f)(void *)) {
    DLL *items = malloc(sizeof(DLL));
    assert(items != 0);
    items->head = NULL;
    items->size = 0;
    items->display = d;
    items->free = f;
    items->addToFront = addToFront;
    return items;
}

void insertDLL(DLL *items, int index, void *value) {
    assert(items != 0);
    assert(index >= 0 && index <= items->size);
}

int sizeDLL(DLL *items) {
    assert(items != 0);
    return items->size;
}


/************************* Private Methods **************************/

void addToFront(DLL *items, void *value) {
    assert(items != 0);
    items->head = newNODE(value, items->head, NULL);
    if (items->size == 0) {
        // List was empty before insertion
        items->tail = items->head;
    }
    items->size++;
}
