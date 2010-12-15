/*!
  IterativeRobot.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "IterativeRobot.h"

/*!
Sets the robot to an uninitialized state
 */
IterativeRobot::IterativeRobot()
{
	m_disabledInitialized = false;
	m_autonomousInitialized = false;
	m_teleopInitialized = false;
	m_period = 0.0;
}

//! Destructor does nothing much
IterativeRobot::~IterativeRobot()
{
}

/*!
Starts the timer and calls autonomous init.
 */
void IterativeRobot::StartCompetition()
{
}

//! Does any global initialization
void IterativeRobot::RobotInit()
{
}

//! Initializes disabled state
void IterativeRobot::DisabledInit()
{
}

//! Initializes autonomous state
void IterativeRobot::AutonomousInit()
{
}

//! Initializes teleop state
void IterativeRobot::TeleopInit()
{
}

//! Called on the clock in disabled state
void IterativeRobot::DisabledPeriodic()
{
}

//! Called on the clock in autonomous
void IterativeRobot::AutonomousPeriodic()
{
}

//! Called on the clock in teleop
void IterativeRobot::TeleopPeriodic()
{
}

//! Not used
void IterativeRobot::DisabledContinuous()
{
}
//! Not used
void IterativeRobot::AutonomousContinuous()
{
}
//! Not used
void IterativeRobot::TeleopContinuous()
{
}

void IterativeRobot::SetPeriod(double period)
{
	m_period = period;
}

double IterativeRobot::GetPeriod()
{
	return m_period;
}

double IterativeRobot::GetLoopsPerSec()
{
	return 1.0/m_period;
}

bool IterativeRobot::NextPeriodReady()
{
	return 	m_mainLoopTimer.HasPeriodPassed(m_period);
}
