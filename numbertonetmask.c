#include <stdio.h>
#include <stdint.h>
#include "func.h"

int main(int argc, char **argv){
	if(argc == 3)
	{
		char netbuffer[16];
		char maskbuffer[16];
		uint32_t number = (uint32_t) strtoul(argv[1], 0, 0);
		uint32_t numbermask = (uint32_t) strtoul(argv[2], 0, 0);
		uint32_t mask = numbertonetmask(numbermask, maskbuffer);
		numbertosubnet(number, mask, netbuffer);
		printf("Network is %s\n, ", netbuffer);
		printf("Mask is %s\n", maskbuffer);
	} else {
		printf("%s needs two arguments (unsigned int)\n", *argv);
	}
}

