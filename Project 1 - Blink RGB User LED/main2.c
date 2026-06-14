/*
Using the TM4C123GH6PM header file provided by TI
*/
#include <TM4C123GH6PM.h>

int main()
{
	// Base Address -> Offset
	SYSCTL->RCGCGPIO = 0x20U;
	GPIOF->DIR = 0x0EU; // bits 3:1 correspond to pins 3,2,1 
	GPIOF->DEN = 0x0EU; // bits 3:1 correspond to pins 3,2,1 
	GPIOF->DATA  = 0x0EU; // 0000.0000 0000.1110 (WHITE)

	while(1)
	{

	}
	return 0;
}
