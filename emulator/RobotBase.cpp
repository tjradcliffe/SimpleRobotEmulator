/*!
  RobotBase.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "RobotBase.h"

RobotBase* RobotBase::m_instance = 0;

// dummy for completeness
class RobotDeleter
{

};

// defined by START_ROBOT_CLASS macro
RobotBase* FRC_userClassFactory();

RobotBase::~RobotBase()
{
}

RobotBase::RobotBase() : m_ds(0) {;}


RobotBase &RobotBase::getInstance()
{
	if (0 == m_instance)
	{
		m_instance = (RobotBase*) FRC_userClassFactory();
	}
	return *m_instance;
}

// this method is not a good idea
void RobotBase::setInstance(RobotBase* robot)
{
	delete m_instance;
	m_instance = robot;
}

bool RobotBase::IsEnabled() {return true;}
bool RobotBase::IsDisabled() {return true;}
bool RobotBase::IsAutonomous() {return true;}
bool RobotBase::IsOperatorControl() {return true;}
bool RobotBase::IsSystemActive() {return true;}
bool RobotBase::IsNewDataAvailable() {return true;}
Watchdog &RobotBase::GetWatchdog() {return m_watchdog;}
