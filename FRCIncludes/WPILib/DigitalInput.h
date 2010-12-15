/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef DIGITAL_INPUT_H_
#define DIGITAL_INPUT_H_

#include "Base.h"

/**
 * Class to read a digital input.
 * This class will read digital inputs and return the current value on the channel. Other devices
 * such as encoders, gear tooth sensors, etc. that are implemented elsewhere will automatically
 * allocate digital inputs and outputs as required. This class is only for devices like switches
 * etc. that aren't implemented anywhere else.
 */
class DigitalInput {
public:
	explicit DigitalInput(UINT32 channel);
	DigitalInput(UINT32 slot, UINT32 channel);
	~DigitalInput();
	UINT32 Get();
	UINT32 GetChannel();

	void setDefault(bool bDefault) {m_bDefault = bDefault;}

private:
	UINT32 m_channel;
	bool m_lastValue;
	bool m_bDefault;
	int m_nCalled;
};

#endif

