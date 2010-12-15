#include "robot_avatar.h"

// wx includes

/*!
  robot_avatar.cpp
 
   Created on: 2010-04-15
       Author: tom
 */

// local includes
#include "robot_interface.h"

RobotAvatar::RobotAvatar(wxWindow* pParent) : wxPanel(pParent)
{
	m_nLength = 100;
	m_nWidth = 60;
	SetSize(wxSize(m_nLength, m_nWidth));
	wxColour red(255,0,0);
	wxColour green(0,255,0);
	SetBackgroundColour(red);
	SetForegroundColour(green);
	Show(true);
	m_pParent = pParent;

	m_fX = 0.0f;
	m_fY = 0.0f;
}

void RobotAvatar::update(RobotInterfaceBase* pRobot)
{
	pRobot->getPosition(m_fX, m_fY);
	SetPosition(wxPoint(m_fX, m_fY));
	SetSize(wxSize(m_nLength, m_nWidth));
}
