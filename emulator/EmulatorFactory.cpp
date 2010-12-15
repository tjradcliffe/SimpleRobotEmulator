/*!
  EmulatorFactory.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

extern long nTime_ms;

#include "EmulatorFactory.h"

#include "CANJaguar.h"
#include "DriverStation.h"
#include "DigitalInput.h"
#include "Gyro.h"
#include "Encoder.h"
#include "Joystick.h"
#include "mappings.h"
#include "SimpleKBot.h"
#include "KBotDrive.h"
#include "Relay.h"
#include "Solenoid.h"
#include "SpeedController.h"

#include <vector>

RobotFactory* getRobotFactory()
{
	return new EmulatorFactory;
}

// local variables actually holding the various bits of hardware
static CANJaguar* pLeftJag1 = 0;
static CANJaguar* pLeftJag2 = 0;
static CANJaguar* pRightJag1 = 0;
static CANJaguar* pRightJag2 = 0;
static Encoder* pLeftEncoder = 0;
static Encoder* pRightEncoder = 0;
static KBotDrive* pKBotDrive = 0;
static std::vector<Joystick*> vecJoystick(2);

void updateEmulatorTeleop(int nTimeIncrement_ms, float fRightX, float fRightY)
{
	nTime_ms += nTimeIncrement_ms;

	vecJoystick[0]->setPosition(fRightX, fRightY);

	pLeftEncoder->update();
	pRightEncoder->update();
}

void updateEmulatorAutonomous(int nTimeIncrement_ms)
{
	nTime_ms += nTimeIncrement_ms;

	pLeftEncoder->update();
	pRightEncoder->update();
}

void updateEmulatorDisabled()
{
}

EmulatorFactory::EmulatorFactory()
{
	pLeftJag1 = new CANJaguar(L_WHEEL1_JAG_ID);
	pLeftJag2 = new CANJaguar(L_WHEEL2_JAG_ID);
	pRightJag1 = new CANJaguar(R_WHEEL1_JAG_ID);
	pRightJag2 = new CANJaguar(R_WHEEL2_JAG_ID);

	pLeftEncoder = new Encoder(L_ENC_A_CHANNEL,L_ENC_B_CHANNEL);
	pLeftEncoder->setJag(pLeftJag1);	// either will do
	pRightEncoder = new Encoder(R_ENC_A_CHANNEL,R_ENC_B_CHANNEL);
	pRightEncoder->setJag(pRightJag1);	// either will do

	// ordering here is to get turn sign right
	pKBotDrive = new KBotDrive(pRightJag1, pRightJag2, pLeftJag1, pLeftJag2);
}

EmulatorFactory::~EmulatorFactory()
{
	// TODO: implement
}

//! Build a joystick object
Joystick* EmulatorFactory::BuildJoystick(UINT32 nNumber)
{
	vecJoystick[nNumber-1] = new Joystick(nNumber);
	return vecJoystick[nNumber-1];
}

//! Build a gyro object
Gyro* EmulatorFactory::BuildGyro(UINT32 channel)
{
	return new Gyro(channel);
}

//! Build an encoder object
Encoder* EmulatorFactory::BuildEncoder(UINT32 aChannel, UINT32 bChannel, bool bReverseDirection)
{
	if ((aChannel == L_ENC_A_CHANNEL) && (bChannel == L_ENC_B_CHANNEL))
	{
		return pLeftEncoder;
	}
	else if ((aChannel == R_ENC_A_CHANNEL) && (bChannel == R_ENC_B_CHANNEL))
	{
		return pRightEncoder;
	}

	return 0;
}

//! Build a digital input object
DigitalInput* EmulatorFactory::BuildDigitalInput(UINT32 channel, bool bDefault)
{
	DigitalInput* pDigitalInput = new DigitalInput(channel);
	pDigitalInput->setDefault(bDefault);
	return pDigitalInput;
}

//! Build a solenoid object with explicit slot
Solenoid* EmulatorFactory::BuildSolenoid(UINT32 slot, UINT32 channel)
{
	return new Solenoid(slot, channel);
}

//! Build a solenoid object with implicit slot
Solenoid* EmulatorFactory::BuildSolenoid(UINT32 channel)
{
	return new Solenoid(channel);
}

//! Build CANJag object
CANJaguar* EmulatorFactory::BuildCANJaguar(UINT8 deviceNumber, CANJaguar::ControlMode controlMode)
{
	if (deviceNumber == L_WHEEL1_JAG_ID)
	{
		return pLeftJag1;
	}
	else if (deviceNumber == L_WHEEL2_JAG_ID)
	{
		return pLeftJag2;
	}
	else if (deviceNumber == R_WHEEL1_JAG_ID)
	{
		return pRightJag1;
	}
	else if (deviceNumber == R_WHEEL2_JAG_ID)
	{
		return pRightJag2;
	}

	return 0;
}

//! Build KBot drive object
KBotDrive* EmulatorFactory::BuildKBotDrive(SpeedController *frontLeftMotor, SpeedController *rearLeftMotor,
		SpeedController *frontRightMotor, SpeedController *rearRightMotor,
		float sensitivity)
{
	return pKBotDrive;
}

//! Build Driver Station object
DriverStation* EmulatorFactory::BuildDriverStation()
{
	return DriverStation::GetInstance();
}

//! Build Relay object
Relay* EmulatorFactory::BuildRelay(INT32 channel, Relay::Direction direction)
{
	return new Relay(channel, direction);
}

