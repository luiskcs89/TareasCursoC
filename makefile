all: libnumtoip.so numbertoip numbertonetmask clean 
	LD_LIBRARY_PATH=$(CURDIR)
	export LD_LIBRARY_PATH

numbertoip: numbertoip.c func.c libnumtoip.so 
	cc -c numbertoip.c -o numbertoip.o
	cc -o numbertoip numbertoip.o -L. -lnumtoip

numbertonetmask: numbertonetmask.c func.c libnumtoip.so
	cc -c numbertonetmask.c -o numbertonetmask.o
	cc -o numbertonetmask numbertonetmask.o -L. -lnumtoip

libnumtoip.so: func.c func.h 
	cc -fPIC -c func.c 
	gcc -shared -olibnumtoip.so func.o

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
