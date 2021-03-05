#ifndef GPIOdriver_H
#define GPIOdriver_H

#include "TM4C123GH6PM.h"

typedef enum 
{
	
	PF2 = 0U,
	PF3 = 1U,
	PB3 = 2U,
	PC4 = 3U,
	PC5 = 4U,
	PC6 = 5U,
	PC7 = 6U,
	PD6 = 7U,
	PD7 = 8U,
	PF4 = 9U,
	
} GPIO_PORT;

typedef enum
{
	
	PD = 0U,
	PU = 1U,
	
} GPIO_PU_PD;

typedef enum
{
	
	LOW  = 0U,
	HIGH = 1U,
	
} GPIO_HI_LO;

void GPIO_Init();
void DigitalWrite(GPIO_PORT port_x , GPIO_HI_LO value);
int DigitalRead(GPIO_PORT port_x , GPIO_PU_PD state);

#endif

