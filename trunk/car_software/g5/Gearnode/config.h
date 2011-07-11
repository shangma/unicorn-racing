/*********************************************
 * Config header
 *********************************************/

// UART
#define USART_BAUDRATE 115200
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) 

// POS Filter
#define FILTERKONSTANTPOS 0.95
// Current Sense Filter
#define FILTERKONSTANTCURRENT 0.95
// PWM Filter
#define FILTERKONSTANTPWM 0.1

// Force control ref
#define FREF 35

// PWM duty Max
#define DUTYMAX 2047

// CPU clock
#define F_CPU 11059200

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

#define AON PORTA|= (1<<PA0)
#define AOF PORTA&=~ (1<<PA0)

#define BON PORTA|=(1<<PA1)
#define BOF PORTA&=~ (1<<PA1)

#define AENA PORTA|= (1<<PA2)
#define ADIS PORTA&=~ (1<<PA2)

#define BENA PORTA|=(1<<PA3)
#define BDIS PORTA&=~(1<<PA3)

#define CW 0
#define CCW 1

#define UD 0
#define IND 1
