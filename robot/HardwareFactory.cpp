#include "HardwareFactory.h"

#include "Joystick.h"
#include "Gyro.h"
#include "Encoder.h"
#include "DigitalInput.h"
#include "Solenoid.h"
#include "CANJaguar.h"
#include "KBotDrive.h"
#include "DriverStation.h"
#include "Relay.h"

RobotFactory* getRobotFactory()
{
	return new HardwareFactory;
}

Joystick* HardwareFactory::BuildJoystick(UINT32 nNumber)
{
	return new Joystick(nNumber);
}
	
Gyro* HardwareFactory::BuildGyro(UINT32 channel)
{
	return new Gyro(channel);
}

Encoder* HardwareFactory::BuildEncoder(UINT32 aChannel, UINT32 bChannel, bool bReverseDirection)
{
	return new Encoder(aChannel, bChannel, bReverseDirection);
}

DigitalInput* HardwareFactory::BuildDigitalInput(UINT32 channel, bool bDefault)
{
	return new DigitalInput(channel);
}

Solenoid* HardwareFactory::BuildSolenoid(UINT32 slot, UINT32 channel)
{
	return new Solenoid(slot, channel);
}

Solenoid* HardwareFactory::BuildSolenoid(UINT32 channel)
{
	return new Solenoid(channel);
}

CANJaguar* HardwareFactory::BuildCANJaguar(UINT8 deviceNumber, CANJaguar::ControlMode controlMode)
{
	return new CANJaguar(deviceNumber, controlMode);
}

KBotDrive* HardwareFactory::BuildKBotDrive(SpeedController *frontLeftMotor, SpeedController *rearLeftMotor,
			SpeedController *frontRightMotor, SpeedController *rearRightMotor,
			float sensitivity)
{
	return new KBotDrive(frontLeftMotor, rearLeftMotor,
			frontRightMotor, rearRightMotor,
			sensitivity);
}

DriverStation* HardwareFactory::BuildDriverStation()
{
	return DriverStation::GetInstance();;
}

Relay* HardwareFactory::BuildRelay(INT32 channel, Relay::Direction direction)
{
	return new Relay(channel, direction);
}
