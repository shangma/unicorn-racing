/* LED modes */
#define LED_OFF		0
#define LED_ON		1
#define LED_BLINK1 	2
#define LED_BLINK2	3

#define SEG_ADDR 0xC4

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

#define SEG_0(mode)	( test_display(mode<<SEG_UPPER_LEFT |\
	mode<<SEG_LOWER_LEFT,\
	mode<<SEG_BOTTOM |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_TOP) )
#define SEG_1(mode)	( test_display(0, mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT) )
#define SEG_2(mode)	( test_display(mode<<SEG_MIDDLE |\
	mode<<SEG_LOWER_LEFT,\
	mode<<SEG_TOP |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_BOTTOM) )
#define SEG_3(mode)	( test_display(mode<<SEG_MIDDLE, mode<<SEG_TOP |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_BOTTOM) )
#define SEG_4(mode)	( test_display(mode<<SEG_MIDDLE |\
	mode<<SEG_UPPER_LEFT,\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT) )
#define SEG_5(mode)	( test_display(mode<<SEG_MIDDLE |\
	mode<<SEG_UPPER_LEFT,\
	mode<<SEG_TOP |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_BOTTOM) )
#define SEG_6(mode)	( test_display(mode<<SEG_MIDDLE |\
	mode<<SEG_UPPER_LEFT |\
	mode<<SEG_LOWER_LEFT,\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_TOP |\
	mode<<SEG_BOTTOM) )
#define SEG_7(mode)	( test_display(0, mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_TOP |\
	mode<<SEG_UPPER_RIGHT) )
#define SEG_8(mode)	( test_display(mode<<SEG_UPPER_LEFT |\
	mode<<SEG_MIDDLE |\
	mode<<SEG_LOWER_LEFT,\
	mode<<SEG_BOTTOM |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_TOP) )
#define SEG_9(mode)	( test_display(mode<<SEG_UPPER_LEFT |\
	mode<<SEG_MIDDLE,\
	mode<<SEG_BOTTOM |\
	mode<<SEG_LOWER_RIGHT |\
	mode<<SEG_UPPER_RIGHT |\
	mode<<SEG_TOP) )
int test_display( int i, int j);
