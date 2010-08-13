/*********************************************
 * Function prototypes
 *********************************************/

// OI
void ioinit(void);

// UART
void uartinit(void);
void sendtekst(char*);

void counter0Init(void);

// Software interrupt
void pcintInit(void);

// PWM functions
void pwm8Init(void);
void pwm16Init(void);
void PWM_duty_cycle_A_set(unsigned int);
void PWM_duty_cycle_B_set(unsigned int);
void PWM_duty_cycle_A16_set(unsigned int);

// ADC
void adcInit(unsigned int);
void adcStop(void);

// Controllers
void gearPosController(unsigned int);
void motorControl(unsigned short int ret, unsigned short int speed, unsigned int pos);

// Debugging
void debugging(void);

// Hbro
void hbroEnable(unsigned short int enable);
