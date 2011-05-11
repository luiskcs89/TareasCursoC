#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include "func.h"

int main(int argc, char **argv){
	if(argc == 3)
	{
		char netbuffer[16];
		char maskbuffer[16];
		uint32_t number, numbermask;
		int result = readnumber(argv[1], &number);
		
		if(result != 1)
		{
			fprintf(stderr, "%s needs two arguments (unsigned int)\n", argv[0]);
			exit(-1);
		}
		result = readnumber(argv[2], &numbermask);
		if(result != 1)
		{
			fprintf(stderr, "%s needs two arguments (unsigned int)\n", argv[0]);
			exit(-1);
		}
		uint32_t mask = numbertonetmask(numbermask, maskbuffer);
		numbertosubnet(number, mask, netbuffer);

		printf("Network is %s\n, ", netbuffer);
		printf("Mask is %s\n", maskbuffer);
	} else {
		fprintf(stderr, "%s needs two arguments (unsigned int)\n", argv[0]);
		exit(-1);
	}
}

