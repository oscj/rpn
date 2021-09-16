#ifndef STACK_H
#define STACK_H

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

struct Stack* makeStack(int maxSize);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
int push(struct Stack* stack, int elem);
int pop(struct Stack* stack);
int peek(struct Stack* stack);
void erase(struct Stack *stack);
#endif