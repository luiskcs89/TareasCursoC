#include <stdio.h>
#include <stdint.h>

int numbertoip(uint32_t number, char* buffer);

int main(int argc, char **argv){
	char buffer[15];
	numbertoip((uint32_t) 0xFFFFFFFF, buffer);
	printf(buffer);
	printf("\n");
}


int numbertoip(uint32_t number, char* buffer){
	uint32_t mask = 0xFF;
	sprintf(buffer, "%d.%d.%d.%d", ((number >> 24) & mask), ((number >> 16) & mask), ((number >> 8) & mask), (number & mask));
	return 1;
}

int numbertonetmask(int32_t number, char* buffer){
	int32_t netmask = 0;
	number = 32-number;

	for(; number<32; number++){
		netmask |= (uint32_t)(1 << number);
	}	
	numbertoip(netmask, buffer);
	
	return 1;
}
