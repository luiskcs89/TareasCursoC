#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include "func.h"

int main(int argc, char **argv){	
	if(argc == 2)
	{
		errno = 0;
		char buffer[16];
		uint32_t number = (uint32_t) strtoul(argv[1], 0, 0);
		if(errno)
		{
			fprintf(stderr, "%s needs one argument (unsigned int)\n", argv[0]);
			exit(-1);
		}
		numbertoip(number, buffer);
		printf("Address is %s\n", buffer);
	} else {
		fprintf(stderr, "%s needs one argument (unsigned int)\n", argv[0]);
		exit(-1);
	}
}


