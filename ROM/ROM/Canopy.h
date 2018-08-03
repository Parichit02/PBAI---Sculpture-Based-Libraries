#ifndef Canopy_H_
#define Canopy_H_

class Canopy {
  public:
    Canopy(int frame_duration);
    ~Canopy();

    int my_type = 0;
    int frame_duration;
    float current_millis;
    float elapsed_millis ;

    //All Behaviours
    const static int number_of_behaviours = 2;
    int test_LED = 1;
 
    bool behaviours_on[number_of_behaviours];

    //Framecounts
    int framecount[number_of_behaviours];

    //Test LED
    int PWM_test_LED;
    int final_PWM_value;
   

    void start_test_LED();
    void resume_test_LED();


    void loop();
};

#endif
