/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef QUAD_ENCODER_H_
#define QUAD_ENCODER_H_


#include "Base.h"

/**
 * Class to read quad encoders.
 * Quadrature encoders are devices that count shaft rotation and can sense direction. The output of
 * the QuadEncoder class is an integer that can count either up or down, and can go negative for
 * reverse direction counting. When creating QuadEncoders, a direction is supplied that changes the
 * sense of the output to make code more readable if the encoder is mounted such that forward movement
 * generates negative values. Quadrature encoders have two digital outputs, an A Channel and a B Channel
 * that are out of phase with each other to allow the FPGA to do direction sensing. 
 */
class Encoder
{
public:
	Encoder(UINT32 aChannel, UINT32 bChannel, bool reverseDirection=false);
	~Encoder();

	// CounterBase interface
	void Start();
	INT32 Get();
	INT32 GetRaw();
	void Reset();
	void Stop();
	double GetPeriod();
	void SetMaxPeriod(double maxPeriod);
	bool GetStopped();
	bool GetDirection();
	double GetDistance();
	double GetRate();
	void SetMinRate(double minRate);
	void SetDistancePerPulse(double distancePerPulse);
	void SetReverseDirection(bool reverseDirection);

	// for emulator
	void setJag(class CANJaguar* pJag) {m_pJag = pJag;}
	void update();

private:

	UINT32 m_nChannelA;
	UINT32 m_nChannelB;

	INT32 m_nCount;
	INT32 m_nLastCount;

	double m_fScale;
	long m_nLastTime;

	class CANJaguar*	m_pJag;
};

#endif

