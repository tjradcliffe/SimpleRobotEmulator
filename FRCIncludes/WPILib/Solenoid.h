/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef SOLENOID_H_
#define SOLENOID_H_

#include "Base.h"

/**
 * Solenoid class for running high voltage Digital Output (9472 module).
 * 
 * The Solenoid class is typically used for pneumatics solenoids, but could be used
 * for any device within the current spec of the 9472 module.
 */
class Solenoid {
public:
	explicit Solenoid(UINT32 channel);
	Solenoid(UINT32 slot, UINT32 channel);
	~Solenoid();
	void Set(bool on);
	bool Get();

	UINT32 m_chassisSlot; ///< Slot number where the module is plugged into the chassis.
	UINT32 m_channel; ///< The channel on the module to control.
	bool m_state;
};

#endif
