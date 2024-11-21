



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




/***SYSTEM SLEEP FUNCTIONS***/
// This method programs the system sleep timer:
void setSystemSleepTimer()
{
   // Timer2 setup to wake sytem after sleep duration:
   TCNT2 = 255 - sleepDuration;
   TIMSK2 |= (1 << TOIE2);
   TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // Runs timer at CLK_PER/1024.
}

void setup()
{
  /***HARDWARE MODULES INITIALIZATION***/
  init_sensePins();
  
  // Debug Serial & System serial comm setup:
  debugSerial.begin(115200);
  Serial.begin(115200);

  // Test comm:
  mySerial.println("DC-generator performance monitor system initialized.");
  mySerial.println("DC-generator performance monitor system initialized.");

}

void loop() 
{
  
}
