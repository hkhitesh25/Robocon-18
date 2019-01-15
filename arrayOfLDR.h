/* arrayOfLDR.h */
#ifndef arrayOfLDR_h
#define arrayOfLDR_h
#include "Arduino.h"
//#include "WProgram.h"
class arrayOfLDR
{
	public:
    arrayOfLDR(int ld1,int ld2,int ld3,int ld4,int ld5,int ld6);
    float read_sensor_values();
    double calculate_pid(int error,int previous_error,int previous_sum);
    private:
    int _ld1;
    int _ld2;
    int _ld3;
    int _ld4;
    int _ld5;
    int _ld6;
    /*
    double kp;
    double kd;
    double ki;	
    */
    
};

#endif
