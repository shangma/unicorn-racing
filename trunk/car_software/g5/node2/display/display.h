/* Led drivers addresses */
#define LED0_7_ADDR 0xC0
#define LED8_15_ADDR 0xC2
#define SEG_ADDR 0xC4
#define LED_BUTTONS_ADDR 0xC6

/* Internal register selection */
#define INPUT0		0x0
#define INPUT1		0x01
#define PSC0		0x02
#define PWM0		0x03
#define PSC1		0x04
#define PWM1		0x05
#define LS0		0x06
#define LS1		0x07
#define LS2		0x08
#define LS3		0x09

/* Auto-increment flag */
#define AI		0x10

/* LED modes */
#define LED_OFF		0
#define LED_ON		1
#define LED_BLINK1 	2
#define LED_BLINK2	3


/* Are located in LS0 see data sheet for CAT9532 */
#define SEG_DOT 	0
#define SEG_MIDDLE 	2
#define SEG_UPPER_LEFT 	4
#define SEG_LOWER_LEFT 	6

/* Are located in LS1 see data sheet for CAT9532 */
#define SEG_BOTTOM 	0
#define SEG_LOWER_RIGHT	2
#define SEG_UPPER_RIGHT	4
#define SEG_TOP 	6

#define SEG_0(mode)	( test_display(SEG_ADDR, mode<<SEG_UPPER_LEFT |\
	mode<<SEG_LOWER_LEFT,\
	mode<<SEG_BOTTOM |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_TOP) )
#define SEG_1(mode)	( test_display(SEG_ADDR, 0, mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT) )
#define SEG_2(mode)	( test_display(SEG_ADDR, mode<<SEG_MIDDLE |\
	mode<<SEG_LOWER_LEFT,\
	mode<<SEG_TOP |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_BOTTOM) )
#define SEG_3(mode)	( test_display(SEG_ADDR, mode<<SEG_MIDDLE, mode<<SEG_TOP |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_BOTTOM) )
#define SEG_4(mode)	( test_display(SEG_ADDR, mode<<SEG_MIDDLE |\
	mode<<SEG_UPPER_LEFT,\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT) )
#define SEG_5(mode)	( test_display(SEG_ADDR, mode<<SEG_MIDDLE |\
	mode<<SEG_UPPER_LEFT,\
	mode<<SEG_TOP |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_BOTTOM) )
#define SEG_6(mode)	( test_display(SEG_ADDR, mode<<SEG_MIDDLE |\
	mode<<SEG_UPPER_LEFT |\
	mode<<SEG_LOWER_LEFT,\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_TOP |\
	mode<<SEG_BOTTOM) )
#define SEG_7(mode)	( test_display(SEG_ADDR, 0, mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_TOP |\
	mode<<SEG_UPPER_RIGHT) )
#define SEG_8(mode)	( test_display(SEG_ADDR, mode<<SEG_UPPER_LEFT |\
	mode<<SEG_MIDDLE |\
	mode<<SEG_LOWER_LEFT,\
	mode<<SEG_BOTTOM |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_TOP) )
#define SEG_9(mode)	( test_display(SEG_ADDR, mode<<SEG_UPPER_LEFT |\
	mode<<SEG_MIDDLE,\
	mode<<SEG_BOTTOM |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_TOP) )

#define RPM0	100
#define RPM1	1000
#define RPM2	2000
#define RPM3	4500
#define RPM4	5000
#define RPM5	5500
#define RPM6	6000
#define RPM7	6500
#define RPM8	7000
#define RPM9	7500
#define RPM10	8000
#define RPM11	8300
#define RPM12	8700
#define RPM13	9000
#define RPM14	9300
#define RPM15	9600
#define RPM16	10000

int test_display(int addr, int i, int j);

set_rpm(uint8_t rpm_low, uint8_t rpm_high, uint8_t mode);
uint8_t set_leds(int addr, uint16_t leds);
uint8_t set_blink_rate(int addr, uint8_t blink_nr, uint8_t blink_rate, uint8_t blink_duty_cycle);
