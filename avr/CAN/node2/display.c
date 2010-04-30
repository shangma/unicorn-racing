#include "led.h"

void disp_rpm(U8 leds) 
{
                  if (leds <= 7) {
                        LED_REG1 = (1<<leds)-1;
                        LED_REG2 = 0;
                    }
                    if (leds>=8) {
                        LED_REG1 = 255;
                        LED_REG2 = (1<<(leds-8))-1;
                    }
}
