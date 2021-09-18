#include <stdio.h>
#include "calculator.h"

void pushOperand(struct Stack *calcStack, int curr)
{
    push(calcStack, curr);
    return;
}

void add(struct Stack *calcStack)
{
    int first = pop(calcStack);
    int second = pop(calcStack);
    int res = first + second;
    push(calcStack, res);
}

void subtract(struct Stack *calcStack)
{
    int second = pop(calcStack);
    int first = pop(calcStack);
    int res = first - second;
    push(calcStack, res);
}

void multiply(struct Stack *calcStack)
{
    int first = pop(calcStack);
    int second = pop(calcStack);
    int res = first * second;
    push(calcStack, res);
}

void divide(struct Stack *calcStack)
{
    int second = pop(calcStack);
    int first = pop(calcStack);
    int res = first / second;
    push(calcStack, res);
}

struct Answer *terminate(struct Stack *calcStack, struct Stack *elemStack)
{
    // TODO: determine if expression was valid
    int validStack = calcStack->top == 0;
    int calcResult = pop(calcStack);
    erase(calcStack);
    erase(elemStack);
    struct Answer *ans = malloc(sizeof(struct Answer));
    ans->result = calcResult;
    ans->isValid = validStack;
    return ans;
}

struct Answer *calculate(struct Stack *elemStack)
{
    struct Stack *calcStack = makeStack(elemStack->maxSize);
    while (!isEmpty(elemStack))
    {
        int curr = pop(elemStack);
        switch (curr)
        {
        case ADDITION:
            add(calcStack);
            break;
        case SUBTRACTION:
            subtract(calcStack);
            break;
        case MULTIPLICATION:
            multiply(calcStack);
        case DIVISION:
            divide(calcStack);
        case TERMINATION:
            return terminate(calcStack, elemStack);
        default:
            pushOperand(calcStack, curr);
            break;
        }
    }

    struct Answer *ans = malloc(sizeof(struct Answer));
    ans->isValid = -1;
    ans->result = INT_MIN;
    return ans;
}
