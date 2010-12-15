#ifndef TIMER_H_
#define TIMER_H_

/*!
  Timer.h
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

/*!
Dumb timer class implementation.  THIS IS NOT A REALTIME CLOCK.
It uses "clock" under the hood and has a resolution of about
1 ms.
 */
class Timer
{
public:

	//! Sets timer to zero, stopped
	Timer();

	//! Does nothing much
	~Timer();

	//! Returns the time since the last Start call in seconds
	double Get();

	//! Resets the timer to zero, stopped
	void Reset();

	//! Starts the timer.  Resets first.
	void Start();

	//! Stops the timer.  Records accumulated time.
	void Stop();

	//! Returns true if period has passed since last Start call.  Records accumulated tiem.
	bool HasPeriodPassed(double period);

	//! Set the time to deal with broken clock
	void Set(float fTime);

private:

	//! The start time in seconds
	double m_startTime;

	//! The time since the last start call in seconds (Must have called Stop or HasPeriodPassed)
	double m_accumulatedTime;

	//! True if timer is running, false otherwise.
	bool m_running;
};

#endif /* TIMER_H_ */
