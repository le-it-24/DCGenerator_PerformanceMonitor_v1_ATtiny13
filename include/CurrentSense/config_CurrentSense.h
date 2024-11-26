



/***CURRENT SENSE SYSTEM I/0 NDEFINITIONS***/

#define GEN_CURRENT_SENSE           A1




/***CURRENT SENSOR SPEC DEFINITIONS***/

#define CURRENT_SENSOR_SENSITIVITY   0.066 // Sensitivity in Volts of specified current sensor.




/***CURRENT SAMPLING DEFINITIONS***/

const int current_overSampleSize = 10;




/***GENERATOR CURRENT SOURCING PARAMETER DEFINITIONS***/

#define GEN_AMP_OUTPUT_MIN    0.25 // This is the minimum output current required from generator. 
                                   // This spec takes into consideration the current required for the system control.
#define GEN_AMP_OUTPUT_MAX    5.00