#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

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
                // Pop the stack twice
                int popOne = pop(s, &val1);
                int popTwo = pop(s, &val2);

                if (popOne == 0 || popTwo == 0) {
                    printf("Incorrect number of operands\n");
                    return 1;
                }
                
                // Add numbers together and add result to stack
                val1 += val2;
                push(s, val1);
                break;
            }
            case '-':
                printf("Minus Sign\n");
                break;
            case '*':
                printf("Multiply Sign\n");
                break;
            case '/':
                printf("Divide Sign\n");
                break;
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
