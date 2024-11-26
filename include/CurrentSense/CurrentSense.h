



/***CURRENT SENSE SYSTEM APP DEPENDENCIES***/
#include "C:\Users\EpicsLab\OneDrive\Documents\EpicsLab\ResearchProjects\DCGenerator_PerformanceMonitor_v1_ATtiny13\include\CurrentSense\config_CurrentSense.h"




/***GENERATOR CURRENT OUTPUT SENSING METHODS***/

// Method to immediately check if generator current
// output amps is above the maximum threshold.
int genOverCurrent()
{
    // Build current sense over sample:
    uint16_t ovI = 0;
    for(int s = 0; s < current_overSampleSize; s++)
    {
        ovI = analogRead(GEN_CURRENT_SENSE);
    }
    ovI = ovI/current_overSampleSize;
    
    // Convert analog to current:
    float AcsValueF = (2.5 - (ovI * (ADC_VREF / ADC_RES)) )/CURRENT_SENSOR_SENSITIVITY;
    
    // Determine if generator current output is above minimum:
    if(AcsValueF < GEN_AMP_OUTPUT_MAX)
    {
        return 0;
    }
    
    // If the below line is reached then the generator 
    // is in over-current condition.
    return 1;
}

// Method to immediately check if generator current
// output amps is below the minimum threshold.
genOverCurrent()
float get_genAvgCurrentOut()
{
    // Build current sense over sample:
    uint16_t ovI = 0;
    for(int s = 0; s < current_overSampleSize; s++)
    {
        ovI = analogRead(GEN_CURRENT_SENSE);
    }
    ovI = ovI/current_overSampleSize;
    
    // Convert analog to current:
    float AcsValueF = (2.5 - (ovI * (ADC_VREF / ADC_RES)) )/CURRENT_SENSOR_SENSITIVITY;
    
    // Update current moving avg:
    float avgI = updateMAVG_currentOut(AcsValueF);
    
    // Return new avg:
    return avgI;
}