/*!
  Gyro.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "Gyro.h"

Gyro::Gyro(UINT32 channel)
{
	m_channel = channel;
}

void Gyro::Reset()
{
	m_offset = 0.0f;
}

float Gyro::GetAngle()
{
	return 0.0f;
}
