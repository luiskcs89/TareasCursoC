#include <stdio.h>
#include <stdint.h>
#include "func.h"

int main(int argc, char **argv){	
	if(argc == 2)
	{
		char buffer[16];
		uint32_t number = (uint32_t) strtoul(argv[1], 0, 0);
		if(number == 0)  errorandexit(*argv);
		numbertoip(number, buffer);
		printf("Address is %s\n", buffer);
	} else {
		errorandexit(*argv);
	}
}


