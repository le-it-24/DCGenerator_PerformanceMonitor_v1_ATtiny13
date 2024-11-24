



/***CURRENT SENSE SYSTEM APP DEPENDENCIES***/
#include "C:\Users\EpicsLab\OneDrive\Documents\EpicsLab\ResearchProjects\DCGenerator_PerformanceMonitor_v1_ATtiny13\include\CurrentSense\config_CurrentSense.h"




/***GENERATOR CURRENT OUTPUT SENSING METHODS***/

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