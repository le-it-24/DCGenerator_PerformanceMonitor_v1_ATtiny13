



/***MAIN EXECUTION DEPENDENCIES***/

// Note: The needed sensor functionality for each module 
//       has been broken down to provide modules for
//       each sensor application. As well,
//       System control functions such as sleep control 
//       have been given their own module.

#include <Arduino.h>
#include "C:\Users\EpicsLab\OneDrive\Documents\EpicsLab\ResearchProjects\DCGenerator_PerformanceMonitor_v1_ATtiny13\include\SleepControl\Sleepcontrol.h"
#include "C:\Users\EpicsLab\OneDrive\Documents\EpicsLab\ResearchProjects\DCGenerator_PerformanceMonitor_v1_ATtiny13\include\VOUT_Monitor\VoltOutputMonitor.h"
#include "C:\Users\EpicsLab\OneDrive\Documents\EpicsLab\ResearchProjects\DCGenerator_PerformanceMonitor_v1_ATtiny13\include\CurrentSense\CurrentSense.h"
#include "C:\Users\EpicsLab\OneDrive\Documents\EpicsLab\ResearchProjects\DCGenerator_PerformanceMonitor_v1_ATtiny13\include\TempSense\TempSense.h"
#include "C:\Users\EpicsLab\OneDrive\Documents\EpicsLab\ResearchProjects\DCGenerator_PerformanceMonitor_v1_ATtiny13\include\Speedometer\Speedometer.h"





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
void init_sensors()
{
  pinMode(GEN_VOLT_SENSE, INPUT);
  pinMode(GEN_CURRENT_SENSE, INPUT);
  pinMode(GEN_TEMP_SENSE, INPUT);
  init_genSpeedometer();
}




/***MAIN EXECUTION SETUP***/
void setup()
{
  /***HARDWARE MODULES INITIALIZATION***/
  init_sensors();

  /***APPLICATION INITIALIZATION PHASE***/
  
  //  Note: Performance monitor needs to determine if output is good from the 
  //        the generator. If PowerGood, PerformanceMonitor can setup into active mode.
  sys_mode = isPowerGood();

  // Debug Serial & System serial comm setup:
  debugSerial.begin(115200);
  Serial.begin(115200);
  
  // Sleep System init:
  init_sleepSystem();

  // Test comm:
  debugSerial.println("DC-generator performance monitor system initialized.");
  Serial.println("DC-generator performance monitor system initialized.");

}

void loop() 
{
  
  /***SYSTEM FLAG PROCESSING BLOCK***/
  if(SYSTEM_WAKE_FLAG) // Flag set periodically to wake system for stat updates.
  {
    // Reset flag:
    SYSTEM_WAKE_FLAG = 0;

    // Run system diagnostics:
    float gen_avgTemp = get_genAvgTemp();
    float gen_avgVoltOut = get_GenAvgVoltOut();
    float avgCurrentOut = get_genAvgCurrentOut();
    float avgRPM = get_genAvgRPM();
    
    // Send data to SystemController:
    String performanceData = String(gen_avgTemp+";"+gen_avgVoltOut+";"+avgCurrentOut+";"+avgRPM);
    Serial.println(performanceData);
  }

  // No pending flags, put system to sleep:
  setSystemSleep();

}
