rpn: stack.o rpn.o calculator.o
	gcc -Wall -std=c99 rpn.o stack.o calculator.o -o rpn

rpn.o: rpn.c
	gcc -Wall -std=c99 -c rpn.c

calculator.o: calculator.c calculator.h
	gcc -Wall -std=c99 -c calculator.c

stack.o: stack.c stack.h
	gcc -Wall -std=c99 -c stack.c

clean:
	rm -rf *.o rpn core;