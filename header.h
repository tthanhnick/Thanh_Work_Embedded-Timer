#define SET_BIT 1
#define CLEAR_BIT 0

#define PCC_PORTD (0x40065000u + 0x130u) //PORTD PIN 15
#define PORT_PCR15 (0x4004C000u + 0x3Cu)
#define GPIOD_PDDR (0x400FF0C0u + 0x14u)
#define GPIOD_PDOR (0x400FF0C0u + 0x0u)

#define PCC_PORTC (0x40065000u + 0x12Cu) //PORTC PIN 13 
#define PORT_PCR13 (0x4004B000u + 0x34u)
#define GPIOC_PDDR (0x400FF080u + 0x14u)
#define GPIOC_PDIR (0x400FF080u + 0x10u)

#define SYSTICK_CTRL (0xE000E010)
#define SYSTICK_LOAD (0xE000E014)
#define SYSTICK_VAL (0xE000E018)

#define PCC_LIPT (0x40065000u + 0xDCu) // PCC LIPT Enable
#define LIPT_MCR (0x40037000u + 0x8u) //LIPT MCR

#define LIPT_TCTRL0 (0x40037000u + 0x28u) //LIPT TCTRL0
#define LIPT_CVAL0 (0x40037000u + 0x24u) //LIPT CVAL0

#define LIPT_MIER (0x40037000u + 0x10u) //LIPT MIER
#define LIPT_MSR (0x40037000u + 0xCu) //LIPT MSR

#define LIPT_TCTRL2 (0x40037000u + 0x48u) //LIPT TCTRL2
#define LIPT_TVAL2 (0x40037000u + 0x40u) //LIPT TVAL2

#define NVIC_INTERRUPT (0xE000E100u + 4*1) // NVIC Interrupt ID n*4
// NVIC Interrupt LIPT 50 div 32 = 1 
// NVIC Interrupt LIPT 51 div 32 = 1

#define LIPT_TCTRL3 (0x40037000u + 0x58u) //LIPT TCTRL3
#define LIPT_TVAL3 (0x40037000u + 0x50u) //LIPT TVAL2

void SetOrClearBit(unsigned int *address, unsigned char position, unsigned char action);
void SetOrClearMultiBit(unsigned int *address, unsigned char position, unsigned int mask, unsigned char action);

void LEDConfig (void);
void SW3Config (void);
void SW3Toggle (void);
void SysTick(void);

void ClockSetting(void);
void LiptInitialization(void);
void Timer0Config(void);

void NVICTimer2Config(void); 
void Timer2InterruptConfig(void);
void Timer2Config(void);

void NVICTimer3Config(void); 
void Timer3InterruptConfig(void);
void Timer3Config(void);