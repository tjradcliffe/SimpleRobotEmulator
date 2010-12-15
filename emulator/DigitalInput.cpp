/*!
  DigitalInput.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "DigitalInput.h"

DigitalInput::DigitalInput(unsigned int nChannel)
{
	m_channel = nChannel;
	m_bDefault = true;
	m_nCalled = 0;
}

unsigned int DigitalInput::DigitalInput::Get()
{
	bool bValue = m_bDefault;
	++m_nCalled;

	// here we do some lookup on the various digital inputs
	return bValue;
}
