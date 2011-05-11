all: libnumtoip.so numbertoip numbertonetmask clean 

numbertoip: numbertoip.c func.c libnumtoip.so 
	cc -g3 -c numbertoip.c -o numbertoip.o
	cc -g3 -o numbertoip numbertoip.o -L. -lnumtoip

numbertonetmask: numbertonetmask.c func.c libnumtoip.so
	cc -g3 -c numbertonetmask.c -o numbertonetmask.o
	cc -g3 -o numbertonetmask numbertonetmask.o -L. -lnumtoip

libnumtoip.so: func.c func.h 
	cc -g3 -fPIC -c func.c 
	gcc  -shared -olibnumtoip.so func.o

.PHONY: clean install uninstall
clean:
	rm -f *.o

install: numbertoip numbertonetmask
	cp numbertoip /usr/bin/
	cp numbertonetmask /usr/bin/
	cp libnumtoip.so /usr/lib/
	
uninstall: 
	rm -f /usr/bin/numbertoip
	rm -f /usr/bin/numbertonetmask
	rm -f /usr/lib/libnumtoip.so
