rpn: stack.o driver.o calculator.o
	gcc -Wall -std=c99 driver.o stack.o calculator.o -o rpn

driver.o: driver.c
	gcc -Wall -std=c99 -c driver.c

calculator.o: calculator.c calculator.h
	gcc -Wall -std=c99 -c calculator.c

stack.o: stack.c stack.h
	gcc -Wall -std=c99 -c stack.c

clean:
	rm -rf *.o rpn core;