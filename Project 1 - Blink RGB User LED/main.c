#define PINF_CLOCK_ENABLE (*((volatile unsigned int*)0x400FE608u))
#define GPIODIR_F (*((volatile unsigned int*)0x40025400u))
#define GPIODEN_F (*((volatile unsigned int*)0x4002551Cu))
#define GPIODATA_F (*((volatile unsigned int*)0x40025038u)) // Exact register associated with Pins F1,F2,F3

int main()
{

	PINF_CLOCK_ENABLE = 0x20u; // Enable clock gating for Pin F
	volatile unsigned int delay = PINF_CLOCK_ENABLE; // dummy operation to waste time
	for(delay = 0; delay<10;delay++){} // dummy operation to waste time
	GPIODIR_F = 0x0eu; // Only set pins 1,2,3 as output
	GPIODEN_F = 0x0eu; // Only digitally enable pins 1,2,3 

	while(1)
	{
		for(delay = 0;delay<1000000;delay++){} // delay
		GPIODATA_F = 0x02u; // 00000010 = 0x02 (red)
		for(delay = 0;delay<1000000;delay++){} // delay
		GPIODATA_F = 0x00u; // 00000000 = 0x00 (off)
		for(delay = 0;delay<1000000;delay++){} // delay
		GPIODATA_F = 0x04u; // 00000100 = 0x04 (blue)
		for(delay = 0;delay<1000000;delay++){} // delay
		GPIODATA_F = 0x00u; // 00000000 = 0x00 (off)
		for(delay = 0;delay<1000000;delay++){} // delay
		GPIODATA_F = 0x08u; // 00001000 = 0x00 (green)
		for(delay = 0;delay<1000000;delay++){} // delay
		GPIODATA_F = 0x00u; // 00000000 = 0x00 (off)
	}
		
	return 0;
}
