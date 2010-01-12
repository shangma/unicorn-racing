//_____ M A C R O S ____________________________________________________________

//_____ D E F I N I T I O N S __________________________________________________

    // -------------- MCU LIB CONFIGURATION
#define FOSC           8000        // 8 MHz External cristal
#define F_CPU          (FOSC*1000) // Need for AVR GCC

    // -------------- CAN LIB CONFIGURATION
#define CAN_BAUDRATE   250        // in kBit
//#define CAN_BAUDRATE   CAN_AUTOBAUD

    // -------------- UART LIB CONFIGURATION
    // UART_0 with fixed Baudrate all application long
#define USE_TIMER16   TIMER16_1
#define USE_UART      UART_0
#define UART_BAUDRATE 38400

    // -------------- MISCELLANEOUS
    // Using TIMER_2 as RTC
#define USE_TIMER8       TIMER8_2
//#define RTC_TIMER        2      // See "board.h"
//#define RTC_CLOCK        32     // See "board.h"

//_____ D E C L A R A T I O N S ________________________________________________
