#include "calculator.h"

void operand(struct Stack *calcStack, int curr)
{
    push(calcStack, curr);
    return;
}

void addition(struct Stack *calcStack)
{
    int first = pop(calcStack);
    int second = pop(calcStack);
    int res = first + second;
    push(calcStack, res);
}

void subtraction(struct Stack *calcStack)
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

int* terminate(struct Stack *calcStack, struct Stack *elemStack)
{
    // TODO: determine if expression was valid
    int validStack = calcStack->top == 0;
    int calcResult = pop(calcStack);
    erase(calcStack);
    erase(elemStack);
    int *res = malloc(sizeof(int) * 2);
    res[0] = calcResult;
    res[1] = validStack;
    return res;
}

int* calculate(struct Stack *elemStack)
{
    struct Stack *calcStack = makeStack(elemStack->maxSize);
    for (int i = 0; i <= elemStack->top; i++)
    {
        int curr = elemStack->array[i];

        switch (curr)
        {
        case ADDITION:
            addition(calcStack);
            break;
        case SUBTRACTION:
            subtraction(calcStack);
            break;
        case MULTIPLICATION:
            multiply(calcStack);
        case DIVISION:
            divide(calcStack);
        case TERMINATION:
            return terminate(calcStack, elemStack);
        default:
            operand(calcStack, curr);
            break;
        }
    }

    int *res = malloc(sizeof(int) * 2);
    res[0] = INT_MIN;
    res[1] = -1;
    return res;
}
