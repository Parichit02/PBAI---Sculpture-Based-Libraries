#include "Canopy.h"
#include<SoftPWM.h>
#include <Arduino.h>
#include <stdint.h>

Canopy::Canopy(int input_frame_duration)
{

  for(int i=0; i<number_of_behaviours; i++)
  {
    behaviours_on[i] = false;
    framecount[i] = 0;
  }
  current_millis = millis();
  frame_duration = input_frame_duration;
  SoftPWMBegin(SOFTPWM_NORMAL); 
  
}

Canopy::~Canopy()
{}

void Canopy::start_test_LED()
{
  behaviours_on[test_LED] = true;
  framecount[test_LED] = 0;
  PWM_test_LED = 0;
}

void Canopy:: resume_test_LED()
{

  framecount[test_LED]++;
  if(framecount[test_LED] > 1000)
    {
      behaviours_on[test_LED] = false;
      framecount[test_LED]=0;
      SoftPWMSet(13,0);
    }
    SoftPWMSet(13,255);

}

void Canopy::loop()
{
  elapsed_millis = millis() - current_millis;
  if (elapsed_millis >= frame_duration || elapsed_millis < 0)
  {
    current_millis = millis();
    if(behaviours_on[test_LED])
    {
      resume_test_LED();
    }
    
  }
}







