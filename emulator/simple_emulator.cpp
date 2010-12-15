// local includes
#include "robot_display_frame.h"
#include "robot_interface.h"
#include "SimpleKBot.h"

// wx includes
#include "wx/wx.h"

class RobotEmulatorApp: public wxApp
{
    virtual bool OnInit();
};

IMPLEMENT_APP(RobotEmulatorApp)

bool RobotEmulatorApp::OnInit()
{
    RobotDisplayFrame *pFrame = new RobotDisplayFrame( wxT("KBot Emulator"),
         wxPoint(50,50), wxSize(450,340), new RobotInterface<SimpleKBot> );
    pFrame->Show(TRUE);
    SetTopWindow(pFrame);
    return true;
}

