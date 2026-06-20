/*
Using the TM4C123GH6PM header file provided by TI
*/
#include <TM4C123GH6PM.h>

// Use AHB on GPIO port F as it's faster and better for this purpose
#define AHB_PORTF (1U << 5) 

// Defining bits corresponding to RGB values
#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)

int main()
{
	SYSCTL->GPIOHBCTL = AHB_PORTF;
	
	// Base Address -> Offset
	SYSCTL->RCGCGPIO = (1U << 5); // Fifth bit set
	GPIOF_AHB->DIR = LED_RED | LED_BLUE | LED_GREEN; // bits 3:1 correspond to pins 3,2,1 
	GPIOF_AHB->DEN = LED_RED | LED_BLUE | LED_GREEN; // bits 3:1 correspond to pins 3,2,1 

	GPIOF_AHB->DATA = LED_RED; // Clear everything and turn on red LED

	while(1)
	{
		volatile int counter = 0;
		GPIOF_AHB->DATA |= LED_BLUE; // Keep current state and turn on blue LED
		while(counter < 1000000)
		{
			counter++;
		}
		GPIOF_AHB->DATA &= ~LED_BLUE; // Turn off only the blue LED
		while(counter > 1)
		{
			counter--;
		}
	}
	return 0;
}
