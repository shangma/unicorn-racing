#define TO_CAN	1
#define TO_SD	2
#define TO_XBEE 4

enum valueID {
	empty,			// 0
	fuelPressure,		// 1
	statusLapCount,		// 2
	statusInjSum,		// 3
	lastGearShift,		// 4
	motorOilTemp,		// 5
	oilPressure,		// 6
	statusTime,		// 7
	statusLapTime,		// 8
	gearOilTemp,		// 9
	statusTraction,		// 10
	statusGas,		// 11
	statusLambdaV2,		// 12
	statusCamTrigP1,	// 13
	statusCamTrigP2,	// 14
	statusChokerAdd,	// 15
	statusLambdaPWM,	// 16
	waterTemp,		// 17
	airTemp,		// 18
	potmeter,		// 19
	rpm,			// 20
	triggerErr,		// 21
	camAngle1,		// 22
	camAngle2,		// 23
	roadSpeed,		// 24
	mapSensor,		// 25
	batteryV,		// 26
	lambdaV,		// 27
	load,			// 28
	injectorTime,		// 29
	ignitionTime,		// 30
	dwellTime,		// 31
	gX,			// 32
	gY,			// 33
	gZ,			// 34
	motorFlags,		// 35
	outBits,		// 36
	time,			// 37
	gear,			// 38
	FWheelL,		// 39
	FWheelR,		// 40
	BWheelL,		// 41
	BWheelR,		// 42
	ValueIdLength		// 43
};

typedef struct {
	uint8_t length;		/* Length of data in bits eg. 8, 10 or some other length */
	uint8_t action;		/* bit 0 = CANSend, bit 1 = SDSave, bit 2 = Xbee */
} valueObject;

/* Remember to set a queue size in comm.h large enough to hold enough data 
 * based on how many values from the ecu that are send via xbee */
static const valueObject valueObjects[] =	{0, 0,	// empty 
						16, 0,	// fuelPressure
						16, 0,	// statusLapCount
						16, 0,	// statusInjSum
						16, 0,	// lastGearShift
						16, 0,	// motorOilTemp
						16, 0,	// oilPressure
						16, 0,	// statusTime
						16, 0,	// statusLapTime
						16, 0,	// gearOilTemp
						16, 0,	// statusTraction
						16, 0,	// statusGas
						16, 0,	// statusLambdaV2
						16, 0,	// statusCamTrigP1
						16, 0,	// statusCamTrigP2
						16, 0,	// statusChokerAdd
						16, 0,	// statusLambdaPWM
						16, 0,	// waterTemp
						16, 0,	// airTemp
						16, 0,	// potmeter
						16, TO_CAN | TO_XBEE,	// rpm
						16, 0,	// triggerErr
						16, 0,	// camAngle1
						16, 0,	// camAngle2
						16, 0,	// roadSpeed
						16, 0,	// mapSensor
						16, 0,	// batteryV
						16, 0,	// lambdaV
						16, 0,	// load
						16, 0,	// injectorTime
						16, 0,	// ignitionTime
						16, 0,	// dwellTime
						16, 0,	// gX
						16, 0,	// gY
						16, 0,	// gZ
						8, 0,	// motorFlags
						8, 0,	// outBits
						8, 0,	// time
						8, TO_XBEE,	// gear
						16, TO_XBEE, // FWheelL
						16, 0, // FWheelR
						16, 0, // BWheelL
						16, 0}; // BWheelR

