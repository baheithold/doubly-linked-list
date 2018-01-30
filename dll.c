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

struct DLL {
    NODE *head;
    int size;

    void (*display)(void *, FILE *);
    void (*free)(void *);
};

DLL *newDLL(void (*d)(void *, FILE *), void (*f)(void *)) {
    DLL *items = malloc(sizeof(DLL));
    assert(items != 0);
    items->head = NULL;
    items->size = 0;
    items->display = d;
    items->free = f;
    return items;
}
