#include <stdint.h>

typedef struct {
	uint16_t rpm;
	uint16_t roadSpeed;
	uint16_t waterTemp;
	uint16_t batteryV;
	uint16_t oilPressure;
} parameters;

extern parameters params;

