/*
 * File:    dll.c
 * Author:  Brett Heithold
 */

#include "dll.h"

typedef struct node {
    void *value;
    struct NODE *next;
    struct NODE *prev;
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
