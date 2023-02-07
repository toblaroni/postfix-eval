TARGETS := main
FLAGS := -g -std=c99 -Wall
MAINS := stack.o main.o

main:		${MAINS}
	gcc ${FLAGS} -o main main.o stack.o

main.o:		main.c stack.c stack.h
	gcc ${FLAGS} -c -o main.o main.c

stack.o:	stack.c stack.h
	gcc ${FLAGS} -c -o stack.o stack.c

clean:
	rm ${TARGETS} ${MAINS}
