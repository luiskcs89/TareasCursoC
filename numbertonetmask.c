#include <stdio.h>
#include <stdint.h>
#include "func.h"

int main(int argc, char **argv){
	if(argc > 1)
	{
		int i;
		for(i = 1; i < argc; i++)
		{
			char buffer[15];
			char* end;
			uint32_t number = (uint32_t) strtoul(argv[i], 0, 0);
			numbertonetmask(number, buffer);
			printf(buffer);
			printf("\n");
		}
	} else {
		printf("No arguments\n");
	}
}

