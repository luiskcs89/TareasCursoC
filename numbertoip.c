#include <stdio.h>
#include <stdint.h>

char *numbertoip(uint32_t number);

int main(int argc, char **argv){
	numbertoip((uint32_t) 0x00FF00FF);
}


char *numbertoip(uint32_t number){
	uint32_t mask = 0xFF;
	
	printf("%d.", ((number >> 24) & mask));
	printf("%d.", ((number >> 16) & mask));
	printf("%d.", ((number >> 8) & mask));
	printf("%d\n", (number & mask));

	return NULL;
}

