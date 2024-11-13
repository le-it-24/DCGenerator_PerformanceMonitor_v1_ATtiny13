#include <Arduino.h>




/***GENERATOR PERFORMANCE MONITOR PINOUT***/
#define GEN_VOLT_SENSE      
#define GEN_CURRENT_SENSE
#define GEN_TEMP_SENSE
#define GEN_SPEED_SENSE




/***MAIN EXECUTION VARIABLES***/
int updateDelayPeriod = 100; // Milliseconds between each sampling update cycle.
float voltageMovingAvg[5]; // Moving average samples of voltage.
float currentMovigAvg[5]; // Moving average samples of current output.
float speedMovingAvg[5]; // Moving average samples of DC generator speed.
float tempMovingAvg[6]; // Moving average samples of DC generator temperature.

// Sample count records for moving averages:
uint8_t numSamples_VMA = 0; // Numbner of samples collected in voltageMovingAvg.
uint8_t numSamples_CMA = 0; 
uint8_t numSamples_SMA = 0;
uint8_t numSamples_TMA = 0;




/***SENSOR PIN FUNCTIIONS***/

// Initializer for data sensing pins:
void setup() 
{
  // put your setup code here, to run once:
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
}
