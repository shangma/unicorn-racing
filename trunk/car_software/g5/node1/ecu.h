/*****************************************************************************************
*									ECU svar								   		     *
* For at få en streng med data fra ecu'en skal der sendes strengen ecu_data. 			 *
* Svaret afkodes efter tabellen herunder.												 *
+----------------------------------------------------------------------------------------+
|		Navn	|		Beskrivelse			|  Byte nr	| Length | 		gain	| offset |
+----------------------------------------------------------------------------------------+
| fuel pressure	|							|     0		|	2	 |	  0			|	0	 |
| motor oil temp|	Temp i ?				|	  8		|	2	 |	  0			|	0	 |
| water temp. 	|	Temp i ?				|	 46		|	2	 | -150,0/3840	|	120	 |
| rpm 			|	Omdrejninger i sek.		|	 54		|	2	 |	  0,9408	|	0	 |
+----------------------------------------------------------------------------------------+
*/

/* Streng der skal sendes til ecu for at få data */
static const char ecu_data[10] = {0x12,0x34,0x56,0x78,0x17,0x08,0,0,0,0};

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
	ValueIdLength		// 38
};

typedef struct {
	uint8_t length;
	enum valueID id;
} ECUValueObject;

static const ECUValueObject ECUObjects[] =	{2,fuelPressure,
						2,statusLapCount,
						2,statusInjSum,
						2,lastGearShift,
						2,motorOilTemp,
						2,oilPressure,
						4,statusTime,
						4,statusLapTime,
						2,gearOilTemp,
						2,statusTraction,
						2,statusGas,
						2,statusLambdaV2,
						2,statusCamTrigP1,
						2,statusCamTrigP2,
						2,statusChokerAdd,
						2,statusLambdaPWM,
						10,empty,
						2,waterTemp,
						2,airTemp,
						2,potmeter,
						2,empty,
						2,rpm,
						2,triggerErr,
						2,camAngle1,
						2,camAngle2,
						2,roadSpeed,
						2,mapSensor,
						2,batteryV,
						2,lambdaV,
						4,empty,
						2,load,
						2,empty,
						2,injectorTime,
						2,empty,
						2,ignitionTime,
						2,dwellTime,
						10,empty,
						2,gX,
						2,gY,
						2,gZ,
						9,empty,
						1,motorFlags,
						1,empty,
						1,outBits,
						1,time};

typedef struct {
	uint8_t length;		/* Length of data in bits eg. 8, 10 or some other length */
	uint8_t action;		/* bit 0 = CANSend, bit 1 = SDSave, bit 2 = Xbee */
} valueObject;

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
						16, 6,	// waterTemp
						16, 6,	// airTemp
						16, 6,	// potmeter
						16, 7,	// rpm
						16, 0,	// triggerErr
						16, 0,	// camAngle1
						16, 0,	// camAngle2
						16, 6,	// roadSpeed
						16, 6,	// mapSensor
						16, 6,	// batteryV
						16, 0,	// lambdaV
						16, 0,	// load
						16, 0,	// injectorTime
						16, 0,	// ignitionTime
						16, 0,	// dwellTime
						16, 0,	// gX
						16, 0,	// gY
						16, 0,	// gZ
						16, 0,	// motorFlags
						16, 0,	// outBits
						16, 0};	// time


/* Indeholder data fra ECU'en */
U8 EcuData[228];

/* Motor oil temp */
#define MOTOR_OIL_TEMP_START 20
#define MOTOR_OIL_TEMP_LENGTH 2
#define MOTOR_OIL_TEMP_GAIN 1
#define MOTOR_OIL_TEMP_OFFSET 0

/* WATER temp */
#define WATER_TEMP_START 46
#define WATER_TEMP_LENGTH 2
#define WATER_TEMP_GAIN -0.0390625
#define WATER_TEMP_OFFSET 120

/* RPM */
#define RPMSTART 54
#define RPMLENGTH 2
#define RPMGAIN 0.9408
#define RPMOFFSET 0

/* Road speed */
#define SPEEDSTART 62
#define SPEEDLENGTH 2
#define SPEEDGAIN 0.01
#define SPEEDOFFSET 0

/* potmeter */
#define POTSTART 50
#define POTLENGTH 2
#define POTGAIN 0.0510
#define POTOFFSET -31.4

/* Map */
#define MAPSTART 64
#define MAPLENGTH 2
#define MAPGAIN 1.0/800/5*3000
#define MAPOFFSET 0

/* Lambda */
#define LAMBDASTART 68
#define LAMBDALENGTH 1
#define LAMBDAGAIN -14.7*0.6/3840
#define LAMBDAOFFSET 0.7*14.7

void ecu_data_handler( void );
