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
void init_sensePins()
{
  pinMode(GEN_VOLT_SENSE, INPUT);
  pinMode(GEN_CURRENT_SENSE, INPUT);
  pinMode(GEN_TEMP_SENSE, INPUT);
  pinMode(GEN_SPEED_SENSE, INPUT);
}




/***SYSTEM SLEEP FUNCTIONS***/
// This method programs the system sleep timer:
void setSystemSleepTimer()
{
   __disable_interrupt(); 
   __watchdog_reset(); 
  /* Start timed sequence */ 
  WDTCR |= (1<<WDCE) | (1<<WDE); 
  /* Set new prescaler(time-out) value = 64K cycles (~0.5 s) */ 
  WDTCR = (1<<WDE) | (1<<WDP2) | (1<<WDP0); __enable_interrupt();
}

void setup()
{
  /***HARDWARE MODULES INITIALIZATION***/
  init_sensePins();
  
  // Serial comm setup:
  
}

void loop() 
{
  
}
