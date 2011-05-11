#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include "func.h"

int main(int argc, char **argv){
	if(argc == 3)
	{
		errno=0;
		char netbuffer[16];
		char maskbuffer[16];

		uint32_t number = (uint32_t) strtoul(argv[1], 0, 0);
		if(errno)
		{
			fprintf(stderr, "%s needs two arguments (unsigned int)\n", argv[0]);
			exit(-1);
		}
		uint32_t numbermask = (uint32_t) strtoul(argv[2], 0, 0);
		if(errno)
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

