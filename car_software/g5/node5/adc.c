#include "config.h"
#include "adc.h"


ADCReadObject ADCReadObjects[] = {{Temp1, 100, 0, 0}, {Temp2,500, 0, 0}, {Temp3, 700, 0, 0}};	

void AdcReadStart(void)
{
	int i;
	ADCReadObject *P1;
	/* Search for ADCReadObject with lowest interval to make it first in list */
	QH = &ADCReadObjects[0];
	P1 = QH;
	for (i=1; i<NumOfSensors; i++){
		P1->next = &ADCReadObjects[i];
		P1 = P1->next;
	}			
}


void SetTimer(uint16_t val)
{
	
}
