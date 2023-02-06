#include <stdio.h>

typedef struct Stacks {
    int *stackPtr;
    int *elements;
    int size;
    int maxSize;
} Stack;

void initStack(Stack *s, int n); // Initialise a given pointer to the size n
int pop(Stack *s, int *n); // Remove and return last 
int push(Stack *s, int n); // Push element 
