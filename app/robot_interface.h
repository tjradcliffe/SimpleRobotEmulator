#ifndef ROBOT_INTERFACE_H
#define ROBOT_INTERFACE_H

//============================================================================
// Name        : robot_interface.h
// Author      : Tom Radcliffe
// Version     :
// Copyright   : Copyright (C) 2010 Predictive Patterns Software Inc.
// Description : Emulator framework for FIRST FRC hardware: interface
//============================================================================

// WPI includes
#include "IterativeRobot.h"
#include "Timer.h"

// standard includes
#include <cstdlib>
#include <iostream>
#include <sstream>

extern long nTime_ms;

void updateEmulatorTeleop(int nTimeIncrement_ms, float fRightStickX, float fRightStickY);
void updateEmulatorAutonomous(int nTimeIncrement_ms);
void updateEmulatorDisabled();

// This is defined in RobotBase via macro from your robot class (START_ROBOT_CLASS)
RobotBase* FRC_userClassFactory();

class RobotInterfaceBase
{
public:
	RobotInterfaceBase() {;}

	virtual ~RobotInterfaceBase() {;}

	virtual void updateTeleop(int nTimeInterval_ms, float fX, float fY) = 0 ;

	virtual void updateAutonomous(int nTimeInterval_ms) = 0 ;

	virtual void updateDisabled() = 0 ;

	virtual void getPosition(float& fX, float& fY) = 0 ;

	virtual void getOrientation(float& fTheta) = 0 ;

	virtual void teleopInit() = 0 ;

	virtual void autonomousInit() = 0 ;

	virtual void disable() = 0 ;

};

template<class T> class RobotInterface: public RobotInterfaceBase
{
public:

	RobotInterface()
	{
		// create the robot
		m_pRobot = (T*)(&(RobotBase::getInstance()));

		m_pRobot->RobotInit();
	}

	~RobotInterface()
	{
		delete m_pRobot;
	}

	void updateTeleop(int nTimeInterval_ms, float fX, float fY)
	{
		updateEmulatorTeleop(nTimeInterval_ms, fX, fY);

		m_pRobot->TeleopPeriodic();
	}

	void updateAutonomous(int nTimeInterval_ms)
	{
		updateEmulatorAutonomous(nTimeInterval_ms);

		m_pRobot->AutonomousPeriodic();
	}

	void updateDisabled()
	{
		updateEmulatorDisabled();

		m_pRobot->DisabledPeriodic();
	}

	void getPosition(float& fX, float& fY)
	{
		fX = m_pRobot->getX();
		fY = m_pRobot->getY();
	}

	void getOrientation(float& fTheta)
	{
		fTheta = 0.0f;
	}

	void teleopInit()
	{
		nTime_ms = 0;
		m_pRobot->TeleopInit();
	}

	void autonomousInit()
	{
		nTime_ms = 0;
		m_pRobot->AutonomousInit();
	}

	void disable()
	{
		nTime_ms = 0;
		m_pRobot->DisabledInit();
	}

private:

	T* m_pRobot;
};

#endif

