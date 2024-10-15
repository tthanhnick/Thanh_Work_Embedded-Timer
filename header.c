#include "header.h"

void SetOrClearBit(unsigned int *address, unsigned char position, unsigned char action)
{
	if (action == SET_BIT)
	{
		*address |= (1U<<position);
	}
	else
	{
		*address &= ~(1U<<position);
	}
	return;
}

void SetOrClearMultiBit(unsigned int *address, unsigned char position, unsigned int mask, unsigned char action)
{
	if (action == SET_BIT)
	{
		*address |= (mask<<position);
	}
	else
	{
		*address &= ~(mask<<position);
	}
	return;
}

void LEDConfig (void)
{
	SetOrClearBit((unsigned int*) PCC_PORTD, 30u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) PORT_PCR15, 8u, 1u, SET_BIT);
	SetOrClearBit((unsigned int*) GPIOD_PDDR, 15u, SET_BIT); 
	
	SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, SET_BIT); 
}

void SW3Config (void)
{
	SetOrClearBit((unsigned int*) PCC_PORTC, 30u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) PORT_PCR13, 8u, 1u, SET_BIT);
	SetOrClearBit((unsigned int*) GPIOD_PDDR, 13u, CLEAR_BIT);
	
	SetOrClearMultiBit((unsigned int*) GPIOD_PDOR, 15u, 1u, SET_BIT);
}

void SW3Toggle (void)
{
	unsigned int state = ((*(unsigned int*)GPIOC_PDIR) & (1 << 13));
	if (state)
	{
		SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, CLEAR_BIT); 
	}
	else
	{
		SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, SET_BIT); 
	}
}

void SysTick(void)
{
	SetOrClearBit((unsigned int*) SYSTICK_CTRL, 0, CLEAR_BIT);
	SetOrClearMultiBit((unsigned int*) SYSTICK_VAL, 0, 0, SET_BIT);
	SetOrClearMultiBit((unsigned int*) SYSTICK_LOAD, 0, 4800000-1, SET_BIT);
	SetOrClearBit((unsigned int*) SYSTICK_CTRL, 0, SET_BIT);
	SetOrClearBit((unsigned int*) SYSTICK_CTRL, 2, SET_BIT);
	SetOrClearBit((unsigned int*) SYSTICK_CTRL, 1, SET_BIT);
}

void ClockSetting(void)
{
	SetOrClearMultiBit((unsigned int*) PCC_LIPT, 24u, 7u, SET_BIT); //128KHz 0b111
	SetOrClearBit((unsigned int*) PCC_LIPT, 30u, SET_BIT); //CGC
}

void LiptInitialization(void)
{
	SetOrClearBit((unsigned int*) LIPT_MCR, 0u, SET_BIT); //Module clock
	SetOrClearBit((unsigned int*) LIPT_MCR, 3u, SET_BIT); //Debug enable
}

void Timer0Config(void)
{
	SetOrClearMultiBit((unsigned int*) LIPT_TCTRL0, 2u, 0u, SET_BIT); //32 bit Periodic 0b00
	SetOrClearBit((unsigned int*) LIPT_TCTRL0, 0u, SET_BIT); //Timer enable
}

void NVICTimer2Config(void)
{ 
	// 50 Mod 32
	SetOrClearBit((unsigned int*) NVIC_INTERRUPT, 18, SET_BIT);  // Enable NVIC interrupt LIPT channel 2
}

void Timer2InterruptConfig(void)
{
	SetOrClearBit((unsigned int*) LIPT_MIER, 2, SET_BIT);  // Enable Timer channel 2
}

void Timer2Config(void)
{
	SetOrClearMultiBit((unsigned int*) LIPT_TVAL2, 0u, 64000-1, SET_BIT);  // Enable Timer channel 2 0.5s
	SetOrClearMultiBit((unsigned int*) LIPT_TCTRL2, 2u, 0u, SET_BIT); //32 bit Periodic 0b00
	SetOrClearBit((unsigned int*) LIPT_TCTRL2, 0u, SET_BIT); //Timer enable
}

void NVICTimer3Config(void)
{
	// 51 Mod 32
	SetOrClearBit((unsigned int*) NVIC_INTERRUPT, 19, SET_BIT);  // Enable NVIC interrupt LIPT channel 3
}

void Timer3InterruptConfig(void)
{
	SetOrClearBit((unsigned int*) LIPT_MIER, 3, SET_BIT);  // Enable Timer channel 3
}

void Timer3Config(void)
{
	SetOrClearMultiBit((unsigned int*) LIPT_TVAL3, 0u, 128000-1, SET_BIT);  // Enable Timer channe 1s
	SetOrClearMultiBit((unsigned int*) LIPT_TCTRL3, 2u, 0b00, SET_BIT); //32 bit Periodic 0b00
	SetOrClearBit((unsigned int*) LIPT_TCTRL3, 0u, SET_BIT); //Timer enable
}