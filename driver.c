#include <stdio.h>
#include <string.h>
#include "calculator.h"

void pushElementsToStack(int numelements, char *elements[], struct Stack *elemStack)
{
    push(elemStack, TERMINATION); // last token is always termination, so push first
    for (int i = numelements; i >= 0; i--)
    {
        char *cur = elements[i];
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
}

// driver
int main(int argc, char *argv[])
{
    // create element stack
    struct Stack *elemStack = makeStack(argc);
    pushElementsToStack(argc - 1, argv, elemStack);

    // get answer
    struct Answer *ans = calculate(elemStack);

    // deal with results
    if (ans->isValid == 0)
    {
        fprintf(stderr, "Invalid Expression.\n");
        free(ans);
        exit(EXIT_FAILURE);
    }
    else if (ans->isValid == 1 && ans->result != INT_MIN)
    {
        fprintf(stdout, "Result: %d\n", ans->result);
        free(ans);
    }

    return 0;
}