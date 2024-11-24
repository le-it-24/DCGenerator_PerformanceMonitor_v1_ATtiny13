



/***GENERATOR TEMPERATURE SENSE APP DEPENDENCIES***/
#include "C:\Users\EpicsLab\OneDrive\Documents\EpicsLab\ResearchProjects\DCGenerator_PerformanceMonitor_v1_ATtiny13\include\TempSense\config_tempSense.h"




/***GENERATOR TEMPERATURE SENSING METHODS***/

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
    float tempC =
}
