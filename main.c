#include <stdio.h>
#include "stack.h"
#include <string.h>

int main(int argc, char **argv) {
    if (argc > 2) return -1;


    // Get the expression from the input
    char *expression = argv[1];
    unsigned long len = strlen(expression);

    // Make and initialise stack to the size of the expression
    Stack s;
    initStack(&s, len);

    for (int i = 0; i < len; i++) {
        switch (expression[i]) {
            case '+':
                printf("Plus sign\n");
                break;
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
                printf("Other\n");
        }
    }

    return 0;
}
