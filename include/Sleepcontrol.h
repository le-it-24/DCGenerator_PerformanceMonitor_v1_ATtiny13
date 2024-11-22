



/***TITLE***/




/***SLEEP CONTROL APPLICATION VARIABLES***/
int sleepDuration = 8; // Value sets sleep time duration,
                        // It is programmed to about 7.8125 ticks/ms.
                        



/***SLEEP TIMER (TIMER2) METHODS***/

// This method programs the system sleep timer:
void setSystemSleepTimer()
{
   // Timer2 setup to wake sytem after sleep duration:
   TCNT2 = 255 - sleepDuration;
   TIMSK2 |= (1 << TOIE2);
   TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // Runs timer at CLK_PER/1024.
}

void disableSystemSleepTimer()
{
   TIMSK2 &= ~(1 << TOIE2);
   TCCR2B &= ~((1 << CS22) | (1 << CS21) | (1 << CS20));
}




/***SYSTEM SLEEP CONTROL METHODS***/

void init_sleepSystem()
{
   set_sleep_mode(SLEEP_MODE_IDLE);
}

void setSystemSleep() // Puts system to sleep. Wake up source is timer2.
{
   
   sleep_bod_disable();
   sleep_enable();
   sleep_bod_disable();
   setSystemSleepTimer();
   sei();
   sleep_cpu();
}




/***SLEEP SYSTEM ISR***/
ISR(TIMER2_OVF_vect)
{
   sleep_disable();
   disableSystemSleepTimer();
}