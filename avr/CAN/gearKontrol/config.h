/*********************************************
 * Config header
 *********************************************/

// UART
#define USART_BAUDRATE 230400
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) 

// UART Transmit queue
#define UARTQUEUESIZE 7

// CPU clock
#define F_CPU 18432000

#define ADCtotnum 2

// Counter0 prescaler
#define counter0prescale0 0
#define counter0prescale1 1
#define counter0prescale8 2
#define counter0prescale64 3
#define counter0prescale256 4
#define counter0prescale1024 5

// PWM 16 bit duty Max
#define dutymax 2047

// Gear ADC pos, Min/Max
#define GearPosMax 600
#define GearPosMiddle 576
#define GearPosMin 562
#define GearMiddleDeadZone 10

#define AON PORTA|= (1<<PA7)
#define AOFF PORTA&=~ (1<<PA7)

#define BON PORTA|=(1<<PA4)
#define BOFF PORTA&=~(1<<PA4)

#define AENA PORTA|= (1<<PA6)
#define ADIS PORTA&=~ (1<<PA6)

#define BENA PORTA|=(1<<PA5)
#define BDIS PORTA&=~(1<<PA5)

#define CW 0
#define CCW 1

#define softwareTrig PORTC^=(1<<PORTC7)

#define GEAROP 1
#define GEARNED 2

// Force (current) safety limit
#define GEARFORCEMAX 220
#define GEARFORCEMAXTIMEOUT1 70
#define GEARFORCECRITICALMAX 250
#define GEARFORCEREF 200

// Gear Stock Timeout
#define GEARSTOCKTIMEOUT1 200 //281 pr tick pr sec
#define GEARSTOCKTIMEOUT2 600 

// Current filter
#define FILTERKONSTANT 0.5
