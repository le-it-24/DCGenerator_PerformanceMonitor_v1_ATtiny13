



/***TITLE***/




/***VOLTAGE OUTPUT MONITOR APP DEPEDENCUES***/

#include "config_VoltOutputMonitor.h"




/***GENERATOR VOLTAGE OUTPUT MONITOR METHODS***/

// Sense and calculate current average
// voltage output.
float get_GenAvgVoltOut()
{
    // Build sample set of voltage samples:
    uint16_t av = 0;
    for(int s = 0; s < samplSize_voltageSensor; s++)
    {
        av += analogRead(
    }
    
}



