// local includes
#include "SimpleKBot.h"
#include "CANJaguar.h"
#include "Encoder.h"
#include "KBotDrive.h"
#include "mappings.h"
#include "DriverStation.h"
#include "Joystick.h"
#include "RobotFactory.h"

// standard includes
#include <cmath>

RobotFactory* pRobotFactory = getRobotFactory();

#define ENCODER_CALIBRATION 0.01257f

/**
 * This is a stripped down version of "BuiltinDefaultCode" modified to drive KBot2010."
 */

/**
 * Constructor for this "BuiltinDefaultCode" Class.
 * 
 * The constructor creates all of the objects used for the different inputs and outputs of
 * the robot.  Essentially, the constructor defines the input/output mapping for the robot,
 * providing named objects for each of the robot interfaces. 
 */
SimpleKBot::SimpleKBot(void)	{
	printf("BuiltinDefaultCode Constructor Started\n");

	// Encoders
	m_leftEncoder = pRobotFactory->BuildEncoder(L_ENC_A_CHANNEL,
			L_ENC_B_CHANNEL, false);
	m_rightEncoder = pRobotFactory->BuildEncoder(R_ENC_A_CHANNEL,
			R_ENC_B_CHANNEL, true);

	m_leftEncoder->SetDistancePerPulse(ENCODER_CALIBRATION);
	m_rightEncoder->SetDistancePerPulse(ENCODER_CALIBRATION);
	m_leftEncoder->Start();
	m_rightEncoder->Start();
	m_leftEncoder->Reset();
	m_rightEncoder->Reset();

	m_fLastRightWheel = 0.0f;
	m_fLastLeftWheel = 0.0f;

	// Create a robot using standard right/left robot drive on PWMS 1, 2, 3, and #4
	m_leftJaguar1 = pRobotFactory->BuildCANJaguar(3, CANJaguar::kPercentVoltage);
	m_leftJaguar1->Set(0.0);
	m_leftJaguar2 = pRobotFactory->BuildCANJaguar(2, CANJaguar::kPercentVoltage);
	m_leftJaguar2->Set(0.0);

	m_rightJaguar1 = pRobotFactory->BuildCANJaguar(4, CANJaguar::kPercentVoltage);
	m_rightJaguar1->Set(0.0);
	m_rightJaguar2 = pRobotFactory->BuildCANJaguar(5, CANJaguar::kPercentVoltage);
	m_rightJaguar2->Set(0.0);

	m_robotDrive = pRobotFactory->BuildKBotDrive(m_leftJaguar1, m_leftJaguar2, m_rightJaguar1, m_rightJaguar2);

	// Acquire the Driver Station object
	m_ds = DriverStation::GetInstance();

	// Define joysticks being used at USB port #1 and USB port #2 on the Drivers Station
	m_rightStick = pRobotFactory->BuildJoystick(1);
	m_leftStick = pRobotFactory->BuildJoystick(2);

	// Initialize counters to record the number of loops completed in autonomous and teleop modes
	m_autoPeriodicLoops = 0;
	m_disabledPeriodicLoops = 0;
	m_telePeriodicLoops = 0;

	printf("BuiltinDefaultCode Constructor Completed\n");
}


/********************************** Init Routines *************************************/

void SimpleKBot::RobotInit(void) {
	// Actions which would be performed once (and only once) upon initialization of the
	// robot would be put here.
	
	printf("RobotInit() completed.\n");
}

void SimpleKBot::DisabledInit(void) {
	m_disabledPeriodicLoops = 0;			// Reset the loop counter for disabled mode
	printf("DisabledInit() completed.\n");
}

void SimpleKBot::AutonomousInit(void) {
	m_autoPeriodicLoops = 0;				// Reset the loop counter for autonomous mode
	printf("AutonomousInit() completed.\n");
}

void SimpleKBot::TeleopInit(void) {
	m_telePeriodicLoops = 0;				// Reset the loop counter for teleop mode
	printf("TeleopInit() completed.\n");
}

/********************************** Periodic Routines *************************************/

void SimpleKBot::DisabledPeriodic(void)  {
	// feed the user watchdog at every period when disabled
	GetWatchdog().Feed();

	// increment the number of disabled periodic loops completed
	m_disabledPeriodicLoops++;
	
	// update common stuff (position etc)
	update();

	// while disabled, printout the duration of current disabled mode in seconds
	if ((m_disabledPeriodicLoops % (int)GetLoopsPerSec()) == 0) {
		int nDisabledSeconds = m_disabledPeriodicLoops / (int)GetLoopsPerSec();
		printf("Disabled seconds: %d\r\n", nDisabledSeconds);
	}
}

void SimpleKBot::AutonomousPeriodic(void) {
	// feed the user watchdog at every period when in autonomous
	GetWatchdog().Feed();
	
	m_autoPeriodicLoops++;

	// update common stuff (position etc)
	update();

	/* the below code (if uncommented) would drive the robot forward at half speed
	 * for two seconds.  This code is provided as an example of how to drive the
	 * robot in autonomous mode, but is not enabled in the default code in order
	 * to prevent an unsuspecting team from having their robot drive autonomously!
	 */
	/* below code commented out for safety
	if (m_autoPeriodicLoops == 1) {
		// When on the first periodic loop in autonomous mode, start driving forwards at half speed
		m_robotDrive->Drive(0.5, 0.0);			// drive forwards at half speed
	}
	if (m_autoPeriodicLoops == (2 * GetLoopsPerSec())) {
		// After 2 seconds, stop the robot
		m_robotDrive->Drive(0.0, 0.0);			// stop robot
	}*/

}

void SimpleKBot::TeleopPeriodic(void) {
	// feed the user watchdog at every period when in teleop
	GetWatchdog().Feed();

	// Periodic loops are now synchronized with incoming packets,
	//  so Driver Station-dependent code goes here
	
	// increment the number of teleop periodic loops completed
	m_telePeriodicLoops++;

	// update common stuff (position etc)
	update();

	// Code to drive the robot
	float xval=0, yval=0;
	xval = m_rightStick->GetX();
	if (xval < 0)
	{
		xval *= -xval;	// preserve sign
	}
	else
	{
		xval *= xval;	// square for better control
	}
	yval = m_rightStick->GetY();

	// drive robot with arcade style (use right stick); no squared inputs because we already squared xval
	m_robotDrive->ArcadeDrive(-yval, -xval, false);

} // TeleopPeriodic(void)
	
/*
 Generic update robot position and orientation.  This is all based on path
 integration and therefore subject to cumulative error, but to first order
 ought to be ok.

 The robot starts out at a known absolute orientation and position relative
 to the field co-ordinate system, which has (0, 0) at the centre, X to the
 right along the long axis of the field and Y away from an observer in the
 stands.  On-screen, X is to the right, Y is up (that is, image co-ordinates,
 not raster co-ordinates.)  Z is therefore positive UP.  The orientation angle
 is measured from the X-axis by the right hand rule (thumb UP, along the Z axis).

 The current algorithm assumes the robot moves along the initial direction
 by the average distance, and then turns.  Iteration would help.
 */
void SimpleKBot::update()
{
    float fAngleCalibration = 1.0f/(3.141592f*22.0f); // robot wheels are 22 inches apart

	float fRightWheel = m_rightEncoder->GetDistance();
	float fLeftWheel = m_leftEncoder->GetDistance();
	float fRightDelta = fRightWheel - m_fLastRightWheel;
	float fLeftDelta = fLeftWheel - m_fLastLeftWheel;
	m_fLastRightWheel = fRightWheel;
	m_fLastLeftWheel = fLeftWheel;
	float fDistance = 0.5*(fRightDelta+fLeftDelta);
	m_fX += cos(m_fAngle)*fDistance;
	m_fY += sin(m_fAngle)*fDistance;
	m_fAngle += fAngleCalibration*(fRightDelta-fLeftDelta);
}

START_ROBOT_CLASS(SimpleKBot);
