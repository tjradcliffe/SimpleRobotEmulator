#ifndef ROBOT_AVATAR_H_
#define ROBOT_AVATAR_H_

// wx includes
#include "wx/wx.h"

// wx forward declarations

/*!
  robot_avatar.h
 
   Created on: 2010-04-15
       Author: tom
 */

class RobotInterfaceBase;

class RobotAvatar: public wxPanel
{
public:
	RobotAvatar(wxWindow* pParent);

	void update(RobotInterfaceBase* pRobot);

protected:

	int m_nLength;
	int m_nWidth;
	wxWindow* m_pParent;

	float m_fX;
	float m_fY;

};


#endif /* ROBOT_AVATAR_H_ */
