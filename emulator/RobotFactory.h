#ifndef ROBOT_FACTORY_H
#define ROBOT_FACTORY_H

#include "CANJaguar.h"
#include "Relay.h"

#ifndef EMULATOR
#include <vxWorks.h>
#else
#include "Base.h"
#endif

class CANJaguar;
class DriverStation;
class DigitalInput;
class Gyro;
class Encoder;
class Joystick;
class KBot;
class KBotDrive;
class Relay;
class Solenoid;
class SpeedController;

/*!
 * Robot factory base class--this just provides the interface for
 * concrete factories.  This class exists so that the emulator factory
 * will be able to wire the various bits together "behind the scenes."
 */
class RobotFactory
{
public:

	//! Constructor does nothing
	RobotFactory() {;}

	//! Virtual destructor so it will be called properly
	virtual ~RobotFactory() {;}

	//! Build a joystick object
	virtual Joystick* BuildJoystick(UINT32 nNumber) {return 0;}

	//! Build a gyro object
	virtual Gyro* BuildGyro(UINT32 channel) {return 0;}
	
	//! Build an encoder object
	virtual Encoder* BuildEncoder(UINT32 aChannel, UINT32 bChannel, bool bReverseDirection = false) {return 0;}
	
	//! Build a digital input object
	virtual DigitalInput* BuildDigitalInput(UINT32 channel, bool bDefault=true) {return 0;}

	//! Build a solenoid object with explicit slot
	virtual Solenoid* BuildSolenoid(UINT32 slot, UINT32 channel) {return 0;}

	//! Build a solenoid object with implicit slot
	virtual Solenoid* BuildSolenoid(UINT32 channel) {return 0;}

	//! Build CANJag object
	virtual CANJaguar* BuildCANJaguar(UINT8 deviceNumber, CANJaguar::ControlMode controlMode = CANJaguar::kPercentVoltage) {return 0;}

	//! Build KBot drive object
	virtual KBotDrive* BuildKBotDrive(SpeedController *frontLeftMotor, SpeedController *rearLeftMotor,
			SpeedController *frontRightMotor, SpeedController *rearRightMotor,
			float sensitivity = 0.5) {return 0;}

	//! Build Driver Station object
	virtual DriverStation* BuildDriverStation() {return 0;}

	//! Build Relay object
	virtual Relay* BuildRelay(INT32 channel, Relay::Direction direction = Relay::kBothDirections) {return 0;}

};

#endif
