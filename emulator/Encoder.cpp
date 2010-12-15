/*!
  Encoder.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "CANJaguar.h"
#include "Encoder.h"

extern long nTime_ms;

static float kfMaxSpeed = 3*39;  // inches per second
static float kfWheelCircumference = 19; // inches
static float kfMaxRevs = kfMaxSpeed/kfWheelCircumference;  // revs per second

Encoder::Encoder(UINT32 nChannelA, UINT32 nChannelB, bool bReverseDirection)
{
	m_nChannelA = nChannelA;
	m_nChannelB = nChannelB;

	m_nCount = 0;
	m_nLastCount = m_nCount;
	m_nLastTime = 0L;
}

void Encoder::update()
{
	if (nTime_ms != m_nLastTime)
	{
		double fDeltaT = (nTime_ms - m_nLastTime)/1000.0;
		m_nCount += 1440*kfMaxRevs*m_pJag->Get()*fDeltaT;
		m_nLastTime = nTime_ms;
	}
}

INT32 Encoder::Get()
{
	return m_nCount;
}

double Encoder::GetDistance()
{
	return m_nCount*m_fScale;
}

void Encoder::SetDistancePerPulse(double fScale)
{
	m_fScale = fScale;
}

double Encoder::GetRate()
{
	return kfMaxRevs*m_pJag->Get();
}

void Encoder::Reset()
{
	m_nCount = 0;
	m_nLastCount = m_nCount;
	m_nLastTime = nTime_ms;
}

void Encoder::Start()
{
	m_nCount = 0;
	m_nLastCount = m_nCount;
	m_nLastTime = nTime_ms;
}
