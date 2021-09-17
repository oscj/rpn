#ifndef STACK_H
#define STACK_H

#include <limits.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int maxSize;
    int *array;
};

// Create stack w/ of size max size
struct Stack *makeStack(int maxSize);

// Check if stack is full, 1 true, 0 false
int isFull(struct Stack *stack);

// Check if stack is empty, 1 true, 0 false
int isEmpty(struct Stack *stack);

// Pushes element onto stack. Returns 1 if successful, 0 if not
int push(struct Stack *stack, int elem);

// Pops element off stack
int pop(struct Stack *stack);

// Returns top element of stack
int peek(struct Stack *stack);

// Frees stack
void erase(struct Stack *stack);
#endif