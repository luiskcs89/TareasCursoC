all: numbertoip numbertonetmask clean 

numbertoip: numbertoip.c func.c
	cc -c numbertoip.c -o numbertoip.o
	cc -c func.c -o func.o
	cc -o numbertoip numbertoip.o func.o

numbertonetmask: numbertonetmask.c func.c
	cc -c numbertonetmask.c -o numbertonetmask.o
	cc -c func.c -o func.o
	cc -o numbertonetmask numbertonetmask.o func.o

.PHONY: clean
clean:
	rm -f *.o

