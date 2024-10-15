#include "header.h"

volatile int counter = 0;

int main(void)
{	
	
	NVICTimer2Config();
	NVICTimer3Config();
	
	ClockSetting();
	LiptInitialization();
	
	Timer0Config();
	//for( int i = 0; i <100000; i++);
	
	Timer2InterruptConfig();
	Timer2Config();
	
	Timer3InterruptConfig();
	Timer3Config();
	
	LEDConfig();
	
	while(1)
	{
		if(counter == 1)
		{
			SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, CLEAR_BIT);
		}
		if (counter == 2)
		{
			SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, SET_BIT); 
			counter = 0;
		}
	}
}

void LPIT0_Ch2_IRQHandler (void)
{
	//counter++;
	SetOrClearBit((unsigned int*) LIPT_MSR, 2, SET_BIT);  // Channel 2 Timmer flag
}

void LPIT0_Ch3_IRQHandler (void)
{
	counter++;
	SetOrClearBit((unsigned int*) LIPT_MSR, 3, SET_BIT);  // Channel 2 Timmer flag
}