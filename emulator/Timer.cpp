/*!
  Timer.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "Timer.h"

#include <ctime>

Timer::Timer()
{
	m_startTime = 0.0;
	m_accumulatedTime = 0.0;
	m_running = false;
}

Timer::~Timer() {;}

double Timer::Get()
{
//	float fClock = clock();
//	m_accumulatedTime = fClock/CLOCKS_PER_SEC - m_startTime;
	return m_accumulatedTime;
}

void Timer::Set(float fTime)
{
	m_accumulatedTime = fTime;
}

void Timer::Reset()
{
	m_startTime = 0.0;
	m_accumulatedTime = 0.0;
	m_running = false;
}

void Timer::Start()
{
	m_startTime = clock()/CLOCKS_PER_SEC;
	m_accumulatedTime = 0.0;
	m_running = true;
}

void Timer::Stop()
{
	m_accumulatedTime = clock()/CLOCKS_PER_SEC - m_startTime;
	m_running = false;
}

bool Timer::HasPeriodPassed(double period)
{
	m_accumulatedTime = clock()/CLOCKS_PER_SEC - m_startTime;
	return m_accumulatedTime > period;
}
