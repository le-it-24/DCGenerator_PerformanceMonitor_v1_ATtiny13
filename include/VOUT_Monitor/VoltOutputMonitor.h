



/***TITLE***/




/***VOLTAGE OUTPUT MONITOR APP DEPEDENCUES***/

#include "C:\Users\EpicsLab\OneDrive\Documents\EpicsLab\ResearchProjects\DCGenerator_PerformanceMonitor_v1_ATtiny13\include\VOUT_Monitor\config_VoltOutputMonitor.h"




/***GENERATOR VOLTAGE OUTPUT MONITOR METHODS***/

// Method to immediately check if generator current
// output voltage is below the minimum threshold.
int genUnderVoltage()
{
    // Build sample set of voltage samples:
    uint16_t av = 0;
    for(int s = 0; s < samplSize_voltageSensor; s++)
    {
        av += analogRead(GEN_VOLT_SENSE);
        delayMicroseconds(10);
    }
    // process AV sample:
    av = av/samplSize_voltageSensor;
    // Convert analog data to voltage:
    float vFilter = (VREF * av)/RES;
    float vOut = vFilter * VDIVIDER_FACTOR;
    
    // Determine if vOut less than min treshold:
    if(vOut > GEN_MIN_VOUT)
    {
        return 0;
    }
    
    // If this line is reached, the output voltage is below
    // min threshold.
    return 1;
}

// Method to immediately check if generator current
// output voltage is above the maximum threshold.
int genOverVoltage()
{
    // Build sample set of voltage samples:
    uint16_t av = 0;
    for(int s = 0; s < samplSize_voltageSensor; s++)
    {
        av += analogRead(GEN_VOLT_SENSE);
        delayMicroseconds(10);
    }
    // process AV sample:
    av = av/samplSize_voltageSensor;
    // Convert analog data to voltage:
    float vFilter = (VREF * av)/RES;
    float vOut = vFilter * VDIVIDER_FACTOR;
    
    // Determine if vOut less than min treshold:
    if(vOut < GEN_MAX_VOUT)
    {
        return 0;
    }
    
    // If this line is reached, the output voltage is above
    // max threshold.
    return 1;
}

// Sense and calculate current average
// voltage output.
float get_GenAvgVoltOut()
{
    // Build sample set of voltage samples:
    uint16_t av = 0;
    for(int s = 0; s < samplSize_voltageSensor; s++)
    {
        av += analogRead(GEN_VOLT_SENSE);
        delayMicroseconds(10);
    }
    // process AV sample:
    av = av/samplSize_voltageSensor;
    // Convert analog data to voltage:
    float vFilter = (VREF * av)/RES;
    float vOut = vFilter * VDIVIDER_FACTOR;
    
    // Update moving average:
    float vOUT_avg = updateMAV_vOut(vOut);
    
    // Return avg:
    return vOUT_avg;
}



