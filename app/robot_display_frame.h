#ifndef ROBOT_DISPLAY_FRAME_H_
/*
 * robot_display_frame.h
 *
 *  Created on: 2010-12-13
 *      Author: tom
 */

// local includes
#include "robot_avatar.h"
#include "robot_interface.h"

// wx includes
#include "wx/joystick.h"
#include "wx/timer.h"
#include "wx/wx.h"

class RobotDisplayFrame: public wxFrame
{
public:

	enum EnabledState
	{
		knAutonomous,
		knTeleop,
		knDisabled,
	};

	static const int knTimer_ms = 50;

	RobotDisplayFrame(const wxString& title,
           const wxPoint& pos, const wxSize& size, RobotInterfaceBase* pRobotInterface);

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnEnableAutonomous(wxCommandEvent& event);
    void OnEnableTeleop(wxCommandEvent& event);
    void OnDisable(wxCommandEvent& event);
    void OnHeartbeat(wxTimerEvent& event);

    DECLARE_EVENT_TABLE()

protected:

    wxTimer*	m_pHeartbeatTimer;

    EnabledState	m_nState;

    wxJoystick*	m_pRightStick;

    wxJoystick*	m_pLeftStick;

    RobotInterfaceBase* m_pRobot;

    RobotAvatar* m_pAvatar;

    float m_fTime;
};

#define ROBOT_DISPLAY_FRAME_H_


#endif /* ROBOT_DISPLAY_FRAME_H_ */
