#include "stack.h"

struct Stack *makeStack(int maxSize)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->maxSize = maxSize;
    stack->top = -1;
    stack->array = (int *)malloc(stack->maxSize * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->maxSize - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int push(struct Stack *stack, int elem)
{
    if (isFull(stack))
    {
        return 0;
    }

    stack->array[++stack->top] = elem;
    return 1;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return INT_MIN;
    }

    int res = stack->array[stack->top];
    stack->top--;
    return res;
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return INT_MIN;
    }

    return stack->array[stack->top];
}

void erase(struct Stack *stack)
{
    free(stack->array);
    free(stack);
}