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

U8 EcuData[228]; 

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
