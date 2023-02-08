#include <stdio.h>

typedef struct Stacks {
    float *stackPtr;
    float *elements;
    int size;
    int maxSize;
} Stack;

void initStack(Stack *s, int n); // Initialise a given pointer to the size n
int pop(Stack *s, float *n); // Remove and return last 
int push(Stack *s, float n); // Push element 
