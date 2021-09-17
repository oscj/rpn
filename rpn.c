#include <stdio.h>
#include <string.h>
#include "calculator.h"

// driver
int main(int argc, char *argv[])
{
    struct Stack *elemStack = makeStack(argc);
    for (int i = 1; i < argc; i++)
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

    push(elemStack, TERMINATION);

    int *res = calculate(elemStack);

    if (res[1] == 0)
    {
        fprintf(stderr, "Invalid Expression.\n");
        free(res);
        exit(EXIT_FAILURE);
    }
    else if (res[1] == 1)
    {
        fprintf(stdout, "Result: %d", res[0]);
        free(res);
    }

    return 0;
}