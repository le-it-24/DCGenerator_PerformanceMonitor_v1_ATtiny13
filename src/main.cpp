



/***MAIN EXECUTION DEPENDENCIES***/
#include <SoftwareSerial.h>
#include <Arduino.h>




/***GENERATOR PERFORMANCE MONITOR PINOUT***/
#define GEN_VOLT_SENSE      
#define GEN_CURRENT_SENSE
#define GEN_TEMP_SENSE
#define GEN_SPEED_SENSE




/***MAIN EXECUTION VARIABLES***/
// Object for Debug interface software serial interface and comm processing:
SoftwareSerial debugSerial(0, 1); // RX, TX

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




/***MAIN EXECUTION SETUP***/
void setup()
{
  /***HARDWARE MODULES INITIALIZATION***/
  init_sensePins();
  
  // Debug Serial & System serial comm setup:
  debugSerial.begin(115200);
  Serial.begin(115200);
  
  // Sleep System init:
  init_sleepSystem();

  // Test comm:
  mySerial.println("DC-generator performance monitor system initialized.");
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
    float boiler_avgTemp = getBoiler_avgTemp();
    float gen_avgVoltOut = get_GenAvgVoltOut();
    float avgCurrentOut = get_genAvgCurrentOut();
    float avgRPM = get_genAvgRPM();
    
    // Send data to SystemController:
    string performanceData = String(boiler_avgTemp+";"+gen_avgVoltOut+";"+avgCurrentOut+";"+avgRPM);
    Serial.println(performanceData);
  }

  // No pending flags, put system to sleep:
  setSystemSleep();

}
