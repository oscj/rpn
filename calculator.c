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
    int loopValid = isEmpty(elemStack) == 0;
    while (loopValid)
    {
        int curr = pop(elemStack);
        switch (curr)
        {
        case ADDITION:
            if (calcStack->top == 0)
            {
                loopValid = 0;
                break;
            }
            add(calcStack);
            break;
        case SUBTRACTION:
            if (calcStack->top == 0)
            {
                loopValid = 0;
                break;
            }
            subtract(calcStack);
            break;
        case MULTIPLICATION:
            if (calcStack->top == 0)
            {
                loopValid = 0;
                break;
            }
            multiply(calcStack);
        case DIVISION:
            if (calcStack->top == 0)
            {
                loopValid = 0;
                break;
            }
            divide(calcStack);
        case TERMINATION:
            return terminate(calcStack, elemStack);
        default:
            pushOperand(calcStack, curr);
            break;
        }
    }

    struct Answer *answer = malloc(sizeof(struct Answer));
    answer->isValid = 0;
    answer->result = INT_MIN;
    erase(elemStack);
    erase(calcStack);
    return answer;
}
