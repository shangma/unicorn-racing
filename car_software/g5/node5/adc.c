#include "config.h"
#include "adc.h"


ADCReadObject ADCReadObjects[] = {{Temp1, 100, 0, 0}, {Temp2,500, 0, 0}, {Temp3, 700, 0, 0}};	

void AdcReadStart(void)
{
	int i;
	/* Search for ADCReadObject with lowest interval to make it first in list */	
	QH = &ADCReadObjects[0];
	for (i=1; i<NumOfSensors; i++){
		if (QH->interval > ADCReadObjects[i].interval){
			 QH = &ADCReadObjects[i];
		}
	}
}

void SetTimer(uint16_t val)
{

}
