



/***SPEEDOMETER SENSOR SYSTEM I/O DEFINITIONS***/
#define GEN_SPEED_SENSE         2 // External interrupt pin for speedometer input.




/***SPEEDOMETER SENSOR SENSE DEFINITIONS***/
time minStart; // A time stamp of when the current minute started.
uint16_t rCount = 0; // Total number of revolutions counted for the current minute.
uint16_t genRPMavg = 0; // Current RPM of generator. This is an avg derived from the total rCount for the current elapsing minute.