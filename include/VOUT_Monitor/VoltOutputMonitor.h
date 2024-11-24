



/***TITLE***/




/***VOLTAGE OUTPUT MONITOR APP DEPEDENCUES***/

#include "C:\Users\EpicsLab\OneDrive\Documents\EpicsLab\ResearchProjects\DCGenerator_PerformanceMonitor_v1_ATtiny13\include\VOUT_Monitor\config_VoltOutputMonitor.h"




/***GENERATOR VOLTAGE OUTPUT MONITOR METHODS***/

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
    
}



