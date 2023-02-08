#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

int dPop(Stack *s, int *n, int *m);

int main(int argc, char **argv) {
    if (argc > 2) return -1;

    // Get the expression from the input
    char *expression = argv[1];
    unsigned long len = strlen(expression);

    // Make and initialise stack to the size of the expression
    Stack *s = (Stack *) malloc(sizeof(Stack));
    initStack(s, len);

    for (int i = 0; i < len; i++) {
        char c = expression[i];
        switch (c) {
            case '+': 
            {
                int val1, val2; // values to hold the popped numbers

                // Check Operands are correct, pop the stack and assign to val1 and val2
                if (!dPop(s, &val1, &val2)) return -1;

                // Add numbers together and add result to stack
                printf("Adding numbers %i and %i together\n", val1, val2);
                val1 += val2;
                push(s, val1);

                break;
            }
            case '-':
            {
                int val1, val2; // values to hold the popped numbers

                // Check Operands are correct, pop the stack and assign to val1 and val2
                if (!dPop(s, &val1, &val2)) return -1;

                // Add numbers together and add result to stack
                printf("Subtracting %i from %i\n", val1, val2);
                val2 -= val1;
                push(s, val2);

                break;
            }
            case '*':
            {
                int val1, val2; // values to hold the popped numbers

                // Check Operands are correct, pop the stack and assign to val1 and val2
                if (!dPop(s, &val1, &val2)) return -1;

                // Add numbers together and add result to stack
                printf("Multiplying numbers %i and %i together\n", val1, val2);
                val1 *= val2;
                push(s, val1);

                break;
            }
            case '/':
            {
                int val1, val2; // values to hold the popped numbers

                // Check Operands are correct, pop the stack and assign to val1 and val2
                if (!dPop(s, &val1, &val2)) return -1;

                // Add numbers together and add result to stack
                printf("Dividing %i by %i\n", val2, val1);
                val2 /= val1;
                push(s, val2);

                break;
            }
            default:
            {
                // Check it's a digit
                if (!isdigit(c)) {
                    printf("Illegal character %c\n", c);
                    return -1;
                }
                int num = atoi(&c);
                push(s, num); // Add the number to the stack (Non numerical c vals will add 0)
                printf("Adding %i to stack\n", num);
            }
        }
    }

    // Print the number in the stack
    int result;
    pop(s, &result);
    printf("Final sum = %i\n", result);

    return 0;
}

// Checks two values 
int dPop(Stack *s, int *val1, int *val2) {
    // Pop the stack twice
    int popOne = pop(s, val1);
    int popTwo = pop(s, val2);

    if (popOne == 0 || popTwo == 0) {
        printf("Incorrect number of operands\n");
        return 0;
    }
    return 1;
}
