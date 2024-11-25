



/***GENERATOR TEMPERATURE SENSE APP DEPENDENCIES***/
#include "C:\Users\EpicsLab\OneDrive\Documents\EpicsLab\ResearchProjects\DCGenerator_PerformanceMonitor_v1_ATtiny13\include\TempSense\config_tempSense.h"




/***GENERATOR TEMPERATURE SENSING METHODS***/

// Method to immediately check if generator current
// operating temperature is above minimum threshold.
int genTempGoodMin()
{
    // Oversample voltage input and average:
    uint16_t anTemp = 0; // Analog data accumulator for temp signal.
    for(int s = 0; s < overSamplSize_genTemp; s++)
    {
        anTemp += analogRead(GEN_TEMP_SENSE);
    }
    anTemp = anTemp/overSamplSize_genTemp;
    
    // Convert Analog data to voltage:
    float vTemp = (ADC_VREF * anTemp)/ADC_RES;
    
    // Convert voltage to temperature centigrade:
    float tempC = ((vTemp * 1000) -500)/10;
    
    // Determine if tempC above threshold:
    if(tempC > GEN_MIN_OP_TEMP)
    {
        return 1;
    }
    
    // If line below reached the generator temp was
    // below min threshold.
    return 0;
}

// Read and calculate moving  avg temperature for generator:
float get_genAvgTemp()
{
    // Oversample voltage input and average:
    uint16_t anTemp = 0; // Analog data accumulator for temp signal.
    for(int s = 0; s < overSamplSize_genTemp; s++)
    {
        anTemp += analogRead(GEN_TEMP_SENSE);
    }
    anTemp = anTemp/overSamplSize_genTemp;
    
    // Convert Analog data to voltage:
    float vTemp = (ADC_VREF * anTemp)/ADC_RES;
    
    // Convert voltage to temperature centigrade:
    float tempC = ((vTemp * 1000) -500)/10;
    
    // Update moving average:
    float avgTempC = calculateMAVG_GenTemp(tempC);
    
    // Return avg:
    return avgTempC;
}
