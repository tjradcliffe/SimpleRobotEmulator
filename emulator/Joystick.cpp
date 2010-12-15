/*!
  Joystick.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "Joystick.h"

Joystick::Joystick(UINT32 stick)
{
	m_port = stick;
}

Joystick::~Joystick()
{
}

float Joystick::GetX(GenericHID::JoystickHand hand)
{
	return m_fX;
}

float Joystick::GetY(GenericHID::JoystickHand hand)
{
	return m_fY;
}

float Joystick::GetZ()
{
	return 0.0f;
}

float Joystick::GetTwist()
{
	return 0.0f;
}

float Joystick::GetRawAxis(unsigned int nAxis)
{
	return 0.0f;
}

float Joystick::GetAxis(Joystick::AxisType nAxis)
{
	return 0.0f;
}

bool Joystick::GetButton(Joystick::ButtonType nButton)
{
	return false;
}

bool Joystick::GetTrigger(GenericHID::JoystickHand hand)
{
	return false;
}

bool Joystick::GetBumper(GenericHID::JoystickHand hand)
{
	return false;
}

bool Joystick::GetRawButton(unsigned int nButton)
{
	return false;
}

float Joystick::GetThrottle()
{
	return 0.0f;
}

bool Joystick::GetTop(GenericHID::JoystickHand hand)
{
	return false;
}

float Joystick::GetMagnitude()
{
	return 0.0f;
}

float Joystick::GetDirectionRadians()
{
	return 0.0f;
}

float Joystick::GetDirectionDegrees()
{
	return 0.0f;
}
