//============================================================================
// Name        : robot_emulator.cpp
// Author      : Tom Radcliffe
// Version     :
// Copyright   : Copyright (C) 2010 Predictive Patterns Software Inc.
// Description : Emulator framework for FIRST FRC hardware
//============================================================================

// local includes
#include "robot_avatar.h"
#include "robot_display_frame.h"
#include "robot_interface.h"

// wx includes
#include "wx/joystick.h"
#include "wx/timer.h"
#include "wx/wx.h"

// globals
long nTime_ms = 0;	// global time for emulator

enum ControlID
{
    ID_Quit = 1,
    ID_About,
    ID_Heartbeat,
    ID_Autonomous,
    ID_Teleop,
    ID_Disable,
};

BEGIN_EVENT_TABLE(RobotDisplayFrame, wxFrame)
    EVT_MENU(ID_Quit, RobotDisplayFrame::OnQuit)
    EVT_MENU(ID_About, RobotDisplayFrame::OnAbout)
    EVT_MENU(ID_Autonomous, RobotDisplayFrame::OnEnableAutonomous)
    EVT_MENU(ID_Teleop, RobotDisplayFrame::OnEnableTeleop)
    EVT_MENU(ID_Disable, RobotDisplayFrame::OnDisable)
    EVT_TIMER(ID_Heartbeat, RobotDisplayFrame::OnHeartbeat)
END_EVENT_TABLE()

RobotDisplayFrame::RobotDisplayFrame(const wxString& title,
       const wxPoint& pos, const wxSize& size, RobotInterfaceBase* pRobot) : wxFrame(0, -1, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append( ID_About, wxT("&About...") );
    menuFile->AppendSeparator();
    menuFile->Append( ID_Quit, wxT("E&xit") );

    wxMenu *menuRobot = new wxMenu;
    menuRobot->Append( ID_Autonomous, wxT("A&utonomous") );
    menuRobot->Append( ID_Teleop, wxT("&Teleop") );
    menuRobot->Append( ID_Disable, wxT("&Stop") );

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, wxT("&File") );
    menuBar->Append( menuRobot, wxT("&Robot") );

    SetMenuBar( menuBar );

    CreateStatusBar();
    SetStatusText( wxT("2809!") );

    m_pRobot = pRobot;

    m_pAvatar = new RobotAvatar(this);

    m_pRightStick = new wxJoystick(wxJOYSTICK1);
    m_pLeftStick = new wxJoystick(wxJOYSTICK2);

    m_fTime = 0.0f;

    m_pHeartbeatTimer = new wxTimer(this, ID_Heartbeat);
	m_nState = knDisabled;
	m_pHeartbeatTimer->Start(knTimer_ms);

}


void RobotDisplayFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(TRUE);
}

void RobotDisplayFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{

    wxMessageBox(wxT("Team 2809 KBot Emulator"),
        wxT("About Robot Emulator"), wxOK | wxICON_INFORMATION, this);
}

void RobotDisplayFrame::OnHeartbeat(wxTimerEvent& WXUNUSED(event))
{
	m_pHeartbeatTimer->Stop();

	m_fTime += knTimer_ms/1000.0f;

	if (knAutonomous == m_nState)
	{
		// TODO: do autonomous mode call here
	}
	else if (knTeleop == m_nState)
	{
		// TODO: do joystick/teleop mode calls here
		if (m_pRightStick)
		{
			wxPoint position = m_pRightStick->GetPosition();
			float fX = (position.x - 32767)/32767.0;
			float fY = (position.y - 32767)/32767.0;

			// call into robot
			m_pRobot->updateTeleop(knTimer_ms, fX, fY);
		}
	}
	else
	{
		// TODO: disabled mode calls here
	}

	m_pAvatar->update(m_pRobot);

	m_pHeartbeatTimer->Start(knTimer_ms);
}

void RobotDisplayFrame::OnEnableAutonomous(wxCommandEvent& WXUNUSED(event))
{
	m_nState = knAutonomous;
}

void RobotDisplayFrame::OnEnableTeleop(wxCommandEvent& WXUNUSED(event))
{
	m_nState = knTeleop;
}

void RobotDisplayFrame::OnDisable(wxCommandEvent& WXUNUSED(event))
{
	m_nState = knDisabled;
}
