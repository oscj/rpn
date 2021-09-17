#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "stack.h"

#define ADDITION -1
#define SUBTRACTION -2
#define MULTIPLICATION -3
#define DIVISION -4
#define TERMINATION -5


// calculates answer to stack containing rpn expression elements
int* calculate(struct Stack *elemStack);

#endif