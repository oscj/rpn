# RPN Calculator

This is a simple implementation of a [Reverse Polish Notation Calculator (RPN)](https://en.wikipedia.org/wiki/Reverse_Polish_notation) written in C.

## Running:

1. Compile:
```bash
make clean
```

2. Execute:
```bash
./rpn <your_rpn_expression_here>
```

## Example:

Let's say we have the following notation in RPN: __5 2 - 10 +__

In algebraic notation, this expression evaluates to (5 - 2) + 10

To get the result of this expression using this program, you would execute the following command:

```bash
./rpn 5 2 - 10 +
```