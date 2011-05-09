#include "func.h"

int numbertoip(uint32_t number, char* buffer){
	uint32_t mask = 0xFF;
	sprintf(buffer, "%d.%d.%d.%d", ((number >> 24) & mask), ((number >> 16) & mask), ((number >> 8) & mask), (number & mask));
	return 1;
}

int numbertosubnet(uint32_t number, uint32_t maskp, char* buffer){
	uint32_t tmpmask = number&maskp;
	numbertoip(tmpmask, buffer);
	return 1;
}

uint32_t numbertonetmask(uint32_t number, char* buffer){
	uint32_t netmask = 0;
	number = 32-number;

	for(; number<32; number++){
		netmask |= (uint32_t)(1 << number);
	}	
	numbertoip(netmask, buffer);
	
	return netmask;
}
