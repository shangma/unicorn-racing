/*-------------------------------------------------------*
 *------------- Defines for display behavior ------------*
 *-------------------------------------------------------*/ 
/* Define rpm intervals */
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

/* Define blink behavior for rpm > RPM16 */
#define RPM16_RATE		100.	// Hz
#define RPM16_DUTYCYCLE 	2.	// %

/* Define rpm leds brightness */
#define RPM_LED_DUTYCYCLE 	2.	// %

/* Define 7 SEG brightness */
#define SEG_DUTYCYCLE 	2.	// %

/* Define indicator leds brightness */
#define SEG_DUTYCYCLE 	2.	// %

/*-----------------------------------------------------------*
 *--------------- Defines for hardware ----------------------*
 *-----------------------------------------------------------*/

/*--------------------------------- Display layout ------------------------------*
 *								                 *
 *  * = LED, x = button                                                          *
 *                                                                               * 
 *  | RPM LED 0-7           | RPM LED 8-15         | 7-SEG   | Indicator& buttons* 
 *  | LED0_7_ADDR           | LED8_15_ADDR         | SEG_ADDR| LED_BUTTONS_ADDR  *
 *  ____________________________________________________________________________ *
 * |                                                |    |    1  2  3    1   2  |*
 * | 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 |    |    *  *  *    *   *  |* 				
 * | *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * |    |    4  5  6    x   x  |*
 * ||   Green   |  yellow   |    Red    |   Blue   ||____|    *  *  *    1   2  |*
 * |__________________________________________________________Indicator___But___|*
 *									         *
 *-------------------------------------------------------------------------------*/

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

/* Rpm leds */
/* LED0_7_ADDR */
#define LED_RPM0	0
#define LED_RPM1	2
#define LED_RPM2	4
#define LED_RPM3	6
#define LED_RPM4	8
#define LED_RPM5	10
#define LED_RPM6	12
#define LED_RPM7	14

/* LED8_15_ADDR */
#define LED_RPM8	0
#define LED_RPM9	2
#define LED_RPM10	4
#define LED_RPM11	6
#define LED_RPM12	8
#define LED_RPM13	10
#define LED_RPM14	12
#define LED_RPM15	14

/* Buttons leds*/
#define LED_BUTTON_1	2
#define LED_BUTTON_2	0

/* Indicator leds */
#define LED_INDI1	14
#define LED_INDI2	12
#define LED_INDI3	10
#define LED_INDI4	8
#define LED_INDI5	6
#define LED_INDI6	4	

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


/* 7-SEG display functions */
#define SEG_OFF()	(set_seg(SEG_ADDR, 0, 0))

#define SEG_OFF(mode)	(set_seg(SEG_ADDR, mode<<SEG_DOT, 0))

#define SEG_0(mode)	( set_seg(SEG_ADDR, mode<<SEG_UPPER_LEFT |\
	mode<<SEG_LOWER_LEFT,\
	mode<<SEG_BOTTOM |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_TOP) )
#define SEG_1(mode)	( set_seg(SEG_ADDR, 0, mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT) )
#define SEG_2(mode)	( set_seg(SEG_ADDR, mode<<SEG_MIDDLE |\
	mode<<SEG_LOWER_LEFT,\
	mode<<SEG_TOP |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_BOTTOM) )
#define SEG_3(mode)	( set_seg(SEG_ADDR, mode<<SEG_MIDDLE, mode<<SEG_TOP |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_BOTTOM) )
#define SEG_4(mode)	( set_seg(SEG_ADDR, mode<<SEG_MIDDLE |\
	mode<<SEG_UPPER_LEFT,\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT) )
#define SEG_5(mode)	( set_seg(SEG_ADDR, mode<<SEG_MIDDLE |\
	mode<<SEG_UPPER_LEFT,\
	mode<<SEG_TOP |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_BOTTOM) )
#define SEG_6(mode)	( set_seg(SEG_ADDR, mode<<SEG_MIDDLE |\
	mode<<SEG_UPPER_LEFT |\
	mode<<SEG_LOWER_LEFT,\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_TOP |\
	mode<<SEG_BOTTOM) )
#define SEG_7(mode)	( set_seg(SEG_ADDR, 0, mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_TOP |\
	mode<<SEG_UPPER_RIGHT) )
#define SEG_8(mode)	( set_seg(SEG_ADDR, mode<<SEG_UPPER_LEFT |\
	mode<<SEG_MIDDLE |\
	mode<<SEG_LOWER_LEFT,\
	mode<<SEG_BOTTOM |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_TOP) )
#define SEG_9(mode)	( set_seg(SEG_ADDR, mode<<SEG_UPPER_LEFT |\
	mode<<SEG_MIDDLE,\
	mode<<SEG_BOTTOM |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_TOP) )

/*--------------------------------------------------------------------*
 *------------------------- Vars used for display --------------------*
 *--------------------------------------------------------------------*/
/* Buttons */
#define BUTTON1		1
#define BUTTON2		2

extern uint16_t indi_leds_state;	// Indicator leds state
extern uint8_t buttons_state;		// Display buttons state

display_test(void);
int test_display(int addr, int i, int j);
uint8_t get_buttons(int addr);
int8_t set_seg(int addr, uint8_t i, uint8_t j);
set_rpm(uint16_t rpm, uint8_t mode);
int8_t set_leds(int addr, uint16_t leds);
int8_t set_blink_rate(int addr, uint8_t blink_nr, uint8_t blink_rate, uint8_t blink_duty_cycle);
