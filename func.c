#include "func.h"

/**
* Makes the conversion between an uint32_t and a IP formated
* string, the result of this operation is stored on buffer
* 
* Params: 
* number: The number from which the IP is goin to be extracted
* buffer: Place where the result is going to be stored
*/
int numbertoip(uint32_t number, char* buffer){
	uint32_t mask = 0xFF;
	sprintf(buffer, "%d.%d.%d.%d", ((number >> 24) & mask), 
		((number >> 16) & mask), ((number >> 8) & mask), (number & mask));
	return 1;
}

/*
* Extract the Subnet of a given IP based on his netmask, stores
* the formated string in the buffer parameter
*
* Params:
* number: The ip from which the subnet is going to be extracted
* maskp:  The Netmask of the IP
* buffer: Buffer where the result is going to be stored 
*/
int numbertosubnet(uint32_t number, uint32_t maskp, char* buffer){
	uint32_t tmpmask = number&maskp;
	numbertoip(tmpmask, buffer);
	return 1;
}

/*
* Converts an int value in a netmask 
* 
* Params:
* number: number of bytes of the mask
* buffer: Buffer where the result is going to be stored
* 
* Return: an int where the netmask is stored 
* (here we have 2 returns buffer and this one)
*/
uint32_t numbertonetmask(uint32_t number, char* buffer){
	uint32_t netmask = 0;
	number = 32-number;

	for(; number<32; number++){
		netmask |= (uint32_t)(1 << number);
	}	
	numbertoip(netmask, buffer);
	
	return netmask;
}

/*
* Reads an unsigned int fom the given string return 1 if sucessful
*/
int readnumber(const char *str, uint32_t *number){
	return sscanf(str, "%u", number);
}

