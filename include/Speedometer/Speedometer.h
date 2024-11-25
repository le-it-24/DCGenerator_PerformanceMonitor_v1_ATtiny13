



/***SPEEDOMETER SYSTEM APP DEPENDENCIES***/
#include "C:\Users\EpicsLab\OneDrive\Documents\EpicsLab\ResearchProjects\DCGenerator_PerformanceMonitor_v1_ATtiny13\include\Speedometer\config_Speedometer.h"




/***GENERATOR SPEEDOMETER SENSING METHODS***/
void update_rCount()
{

    // Update rCount:
    rCount += 1;

}

// I want to implement a projection of where RPM will be based on the current rate of revelotion input + current rCount.
unsigned long elapsed = minStart - rtc_getTime();

/***GENERATOR SPEEDOMETER CONTROL METHODS***/
void init_genSpeedometer()
{
    pinMode(GEN_SPEED_SENSE, INPUT);
    attachInterrupt(GEN_SPEED_SENSE,update_rCount,RISING);
}

uint16_t get_genAvgRPM()
{
    return genRPMavg;
}