#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "stack.h"

#define ADDITION -1
#define SUBTRACTION -2
#define MULTIPLICATION -3
#define DIVISION -4
#define TERMINATION -5

struct Answer
{
    int isValid; // 1 if expression was valid,  -1 if invalid
    int result;
};

// calculates answer to stack containing rpn expression elements
struct Answer *calculate(struct Stack *elemStack);

#endif