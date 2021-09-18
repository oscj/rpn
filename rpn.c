#include <stdio.h>
#include <string.h>
#include "calculator.h"

// driver
int main(int argc, char *argv[])
{
    struct Stack *elemStack = makeStack(argc);
    push(elemStack, TERMINATION); // know when to terminate
    // last to first to push to stack in order for popping
    for (int i = argc - 1; i >= 0; i--)
    {
        char *cur = argv[i];
        if (*cur == '+')
        {
            push(elemStack, ADDITION);
        }
        else if (*cur == '-')
        {
            push(elemStack, SUBTRACTION);
        }
        else if (*cur == '*')
        {
            push(elemStack, MULTIPLICATION);
        }
        else if (*cur == '/')
        {
            push(elemStack, DIVISION);
        }
        else if (atoi(cur) >= 0)
        {
            int elem = atoi(cur);
            push(elemStack, elem);
        }
        else
        {
            fprintf(stderr, "Invalid token: %c\n", *cur);
            exit(EXIT_FAILURE);
        }
    }


    struct Answer *ans = calculate(elemStack);

    if (ans->isValid == -1)
    {
        fprintf(stderr, "Invalid Expression.\n");
        free(ans);
        exit(EXIT_FAILURE);
    }
    else if (ans->isValid == 1)
    {
        fprintf(stdout, "Result: %d", ans->result);
        free(ans);
    }

    return 0;
}