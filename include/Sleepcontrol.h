



/***TITLE***/




/***SLEEP CONTROL APPLICATION VARIABLES***/
int sleepDuration = 8; // Value sets sleep time duration,
                        // It is programmed to about 7.8125 ticks/ms.
                        



/***SLEEP TIMER (TIMER2) METHODS***/
void setSystemSleepTimer()
{
   // Timer2 setup to wake sytem after sleep duration:
   TCNT2 = 255 - sleepDuration;
   TIMSK2 |= (1 << TOIE2);
   TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // Runs timer at CLK_PER/1024.
}