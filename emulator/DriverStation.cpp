/*!
  DriverStation.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "DriverStation.h"

DriverStation *DriverStation::m_instance = 0;

DriverStation::DriverStation()
{

}

DriverStation::~DriverStation()
{

}

DriverStation* DriverStation::GetInstance()
{
	if (0 == m_instance)
	{
		m_instance = new DriverStation();
	}

	return m_instance;
}

UINT32 DriverStation::GetPacketNumber()
{
	return 0;
}
