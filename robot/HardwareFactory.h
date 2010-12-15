#ifndef HARDWARE_FACTORY_H
#define HARDWARE_FACTORY_H

#include "RobotFactory.h"

class HardwareFactory: public RobotFactory
{
public:

	//! Constructor does nothing
	HardwareFactory() {;}

	//!  destructor so it will be called properly
	~HardwareFactory() {;}

	//! Build a joystick object
	 Joystick* BuildJoystick(UINT32 nNumber);

	//! Build a gyro object
	 Gyro* BuildGyro(UINT32 channel);
	
	//! Build an encoder object
	 Encoder* BuildEncoder(UINT32 aChannel, UINT32 bChannel, bool bReverseDirectione);
	
	//! Build a digital input object
	 DigitalInput* BuildDigitalInput(UINT32 channel, bool bDefault=true);

	//! Build a solenoid object with explicit slot
	 Solenoid* BuildSolenoid(UINT32 slot, UINT32 channel);

	//! Build a solenoid object with implicit slot
	 Solenoid* BuildSolenoid(UINT32 channel);

	//! Build CANJag object
	 CANJaguar* BuildCANJaguar(UINT8 deviceNumber, CANJaguar::ControlMode controlMode);

	//! Build KBot drive object
	 KBotDrive* BuildKBotDrive(SpeedController *frontLeftMotor, SpeedController *rearLeftMotor,
			SpeedController *frontRightMotor, SpeedController *rearRightMotor,
			float sensitivity);

	//! Build Driver Station object
	 DriverStation* BuildDriverStation();

	//! Build Relay object
	 Relay* BuildRelay(INT32 channel, Relay::Direction direction);

};

#endif
