/*
 * File:    dll.c
 * Author:  Brett Heithold
 */

#include "dll.h"
#include <stdlib.h>
#include <assert.h>

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
static void addToBack(DLL *items, void *value);
static void insertAtIndex(DLL *items,int, void *value);
static void *removeFromFront(DLL *items);
static void *removeFromBack(DLL *items);
static void *removeFromIndex(DLL *items, int index);
static NODE *getNodeAtIndex(DLL *items, int index);

struct DLL {
    NODE *head;
    NODE *tail;
    int size;

    // Public methods
    void (*display)(void *, FILE *);
    void (*free)(void *);
    
    // Private methods
    void (*addToFront)(DLL *, void *);
    void (*addToBack)(DLL *, void *);
    void (*insertAtIndex)(DLL *,int, void *);
    void *(*removeFromFront)(DLL *);
    void *(*removeFromBack)(DLL *);
    void *(*removeFromIndex)(DLL *, int);
    NODE *(*getNodeAtIndex)(DLL *, int);
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
    items->addToBack = addToBack;
    items->insertAtIndex = insertAtIndex;
    items->removeFromFront = removeFromFront;
    items->removeFromBack = removeFromBack;
    items->removeFromIndex = removeFromIndex;
    items->getNodeAtIndex = getNodeAtIndex;
    return items;
}

void insertDLL(DLL *items, int index, void *value) {
    assert(items != 0);
    assert(index >= 0 && index <= items->size);
    if (index == 0) {
        // Value is to be added at the front of the list
        items->addToFront(items, value);
    }
    else if (index == items->size) {
        // Value is to be added at the back of the list
        items->addToBack(items, value);
    }
    else {
        // Value is to be inserted at an index between 1 and items->size - 1
        items->insertAtIndex(items, index, value);
    }
}

void *removeDLL(DLL *items, int index) {
    assert(items != 0);
    assert(items->size > 0);
    assert(index >= 0 && index < items->size);
    void *oldValue;
    if (index == 0) {
        // Remove from front
        oldValue = items->removeFromFront(items);
    }
    else if (index == items->size - 1) {
        // Remove from back
        oldValue = items->removeFromBack(items);
    }
    else {
        // Remove from index
        oldValue = items->removeFromIndex(items, index);
    }
    return oldValue;
}

int sizeDLL(DLL *items) {
    assert(items != 0);
    return items->size;
}

void *getDLL(DLL *items, int index) {
    // TODO: Can I do better?
    assert(items != 0);
    assert(index >= 0 && index < items->size);
    if (index == 0) {
        return getNODEvalue(items->head);
    }
    else if (index == items->size - 1) {
        return getNODEvalue(items->tail);
    }
    else {
        NODE *curr = items->head;
        while (index > 0) {
            curr = getNODEnext(curr);
            index--;
        }
        return getNODEvalue(curr);
    }
}

void displayDLL(DLL *items, FILE *fp) {
    assert(items != 0);
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

void addToBack(DLL *items, void *value) {
    assert(items != 0);
    if (items->size == 0) {
        // List is empty
        items->addToFront(items, value);
    }
    else {
        NODE *n = newNODE(value, NULL, items->tail);
        setNODEnext(items->tail, n);
        items->tail = n;
    }
    items->size++;
}

void insertAtIndex(DLL *items, int index, void *value) {
    assert(items != 0);
    assert(index >= 0 && index <= items->size);
    if (index == 0) {
        items->addToFront(items, value);
    }
    else if (index == items->size) {
        items->addToBack(items, value);
    }
    else {
        NODE *curr = items->head;
        while (index > 1) {
            curr = curr->next;
            index--;
        }
        NODE *n = newNODE(value, curr->next, curr);
        setNODEprev(curr->next, n);
        setNODEnext(curr, n);
        items->size++;
    }
}

void *removeFromFront(DLL *items) {
    assert(items != 0);
    NODE *oldHead = items->head;
    void *oldValue = getNODEvalue(oldHead);
    items->head = getNODEnext(oldHead);
    items->size--;
    if (items->size == 0) {
        // List is going empty
        items->tail = NULL;
    }
    free(oldHead);
    return oldValue;
}

void *removeFromBack(DLL *items) {
    assert(items != 0);
    void *oldValue;
    if (items->size == 1) {
        // List is going empty
        oldValue = items->removeFromFront(items);
    }
    else {
        NODE *curr = getNODEprev(items->tail); // get next to last node
        oldValue = getNODEvalue(items->tail);
        free(items->tail);
        items->tail = curr;
        setNODEnext(curr, NULL);
        items->size--;
    }
    return oldValue;
}

void *removeFromIndex(DLL *items, int index) {
    assert(items != 0);
    void *oldValue;
    if (index == 0) {
        oldValue = items->removeFromFront(items);
    }
    else if (index == items->size - 1) {
        oldValue = items->removeFromBack(items);
    }
    else {
        // get node prev to index
        NODE *curr = getNodeAtIndex(items, index - 1);
        NODE *oldNode = getNODEnext(curr);
        oldValue = getNODEvalue(oldNode);
        setNODEnext(curr, getNODEnext(oldNode));
        setNODEprev(getNODEnext(oldNode), curr);
        items->size--;
        if (items->size == 0) {
            // List went empty
            items->head = NULL;
            items->tail = NULL;
        }
        free(oldNode);
    }
    return oldValue;
}

NODE *getNodeAtIndex(DLL *items, int index) {
    NODE *curr = items->head;
    while (index > 0) {
        curr = getNODEnext(curr);
        index--;
    }
    return curr;
}
