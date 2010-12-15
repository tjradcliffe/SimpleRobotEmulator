#ifndef EMULATORFACTORY_H_
#define EMULATORFACTORY_H_

/*!
  EmulatorFactory.h
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "RobotFactory.h"

class EmulatorFactory : public RobotFactory
{
public:

	//! Constructor creates and wires up all anticipated objects
	EmulatorFactory();

	//! Destructor cleans up
	~EmulatorFactory();

	//! Build a joystick object
	Joystick* BuildJoystick(UINT32 nNumber);

	//! Build a gyro object
	Gyro* BuildGyro(UINT32 channel);

	//! Build an encoder object
	Encoder* BuildEncoder(UINT32 aChannel, UINT32 bChannel, bool bReverseDirection = false);

	//! Build a digital input object
	DigitalInput* BuildDigitalInput(UINT32 channel, bool bDefault = true);

	//! Build a solenoid object with explicit slot
	Solenoid* BuildSolenoid(UINT32 slot, UINT32 channel);

	//! Build a solenoid object with implicit slot
	Solenoid* BuildSolenoid(UINT32 channel);

	//! Build CANJag object
	CANJaguar* BuildCANJaguar(UINT8 deviceNumber, CANJaguar::ControlMode controlMode = CANJaguar::kPercentVoltage);

	//! Build KBot drive object
	KBotDrive* BuildKBotDrive(SpeedController *frontLeftMotor, SpeedController *rearLeftMotor,
			SpeedController *frontRightMotor, SpeedController *rearRightMotor,
			float sensitivity = 0.5);

	//! Build Driver Station object
	DriverStation* BuildDriverStation();

	//! Build Relay object
	Relay* BuildRelay(INT32 channel, Relay::Direction direction = Relay::kBothDirections);

};

#endif /* EMULATORFACTORY_H_ */
