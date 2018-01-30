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

void *getNODEvalue(NODE *n) {
    return n->value;
}

void setNODEvalue(NODE *n, void *value) {
    n->value = value;
}

NODE *getNODEnext(NODE *n) {
    return n->next;
}

void setNODEnext(NODE *n, NODE *newNext) {
    assert(n != 0);
    n->next = newNext;
}

NODE *getNODEprev(NODE *n) {
    return n->prev;
}

void setNODEprev(NODE *n, NODE *newPrev) {
    assert(n != 0);
    n->prev = newPrev;
}

// Private DLL method prototypes
static void addToFront(DLL *items, void *value);

struct DLL {
    NODE *head;
    NODE *tail;
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
    items->tail = NULL;
    items->size = 0;
    items->display = d;
    items->free = f;
    items->addToFront = addToFront;
    return items;
}

void insertDLL(DLL *items, int index, void *value) {
    assert(items != 0);
    assert(index >= 0 && index <= items->size);
    if (index == 0) {
        // Value is to be added at the front of the list
        items->addToFront(items, value);
    }
}

int sizeDLL(DLL *items) {
    assert(items != 0);
    return items->size;
}

void displayDLL(DLL *items, FILE *fp) {
    fprintf(fp, "{{");
    NODE *curr = items->head;
    while (curr != NULL) {
        items->display(getNODEvalue(curr), fp);
        curr = curr->next;
        if (curr != NULL) {
            fprintf(fp, ",");
        }
    }
    fprintf(fp, "}}");
}


/************************* Private Methods **************************/

void addToFront(DLL *items, void *value) {
    assert(items != 0);
    NODE *n = newNODE(value, items->head, NULL);
    if (items->size == 0) {
        // List is empty, set head and tail to same node
        items->head = n;
        items->tail = n;
    }
    else {
        // List is non-empty
        setNODEprev(items->head, n);
        items->head = n;
    }
    items->size++;
}
