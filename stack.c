#include "stack.h"

void initStack(Stack *s, int n) {
    s->elements = (int *) malloc(sizeof(int) * n); // Allocate memory to the stack
    s->stackPtr = s->elements; // Set the stackptr to the start of the stack
    s->size = 0;
    s->maxSize = n;
}

// Stack s to be pushed to and int n to be pushed
int push(Stack *s, int n) {
    if (s->size < s->maxSize) {
        // Set value of ptr to n
        s->stackPtr = n;
        // Increment ptr
        s->stackPtr ++;
        // Increment size of s
        s->size ++;
        return 1;
    } else {
        return 0;
    }
}

// Stack s to be popped and n to store popped val
int pop(Stack *s, int *n) {
    if (s->size != 0) {
        // Decrease the stack pointer by one
        s->stackPtr --;
        // Get the element by dereferencing the pointer
        n = *s->stackPtr;
        s->size --;
        return 1;
    } else {
        return 0;
    }
}

