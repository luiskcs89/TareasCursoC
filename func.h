#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdint.h>

int numbertoip(uint32_t number, char* buffer);
int numbertosubnet(uint32_t number, uint32_t mask, char* buffer);
uint32_t numbertonetmask(uint32_t number, char* buffer);

#endif
