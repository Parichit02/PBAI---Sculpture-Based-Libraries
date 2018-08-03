#include "Canopy.h"
#include <SoftPWM.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  SoftPWMBegin(SOFTPWM_NORMAL);
  int frame_duration = 1;
}

int temp_count =1;
Canopy Canopy(frame_duration);
void loop() {
  // put your main code here, to run repeatedly:

    Canopy.behaviours_on[Canopy.test_LED]=true;
    temp_count=0;


  Canopy.loop();

}
