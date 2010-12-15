/*!
  Solenoid.h
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "Solenoid.h"

Solenoid::Solenoid(UINT32 channel)
{
	m_channel = channel;
}

Solenoid::Solenoid(UINT32 slot, UINT32 channel)
{
	m_chassisSlot = slot;
	m_channel = channel;
}

void Solenoid::Set(bool state)
{
	m_state = state;
}
