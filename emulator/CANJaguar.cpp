
#include "CANJaguar.h"

/**
 * Constructor
 *
 * @param deviceNumber The the address of the Jaguar on the CAN bus.
 */
CANJaguar::CANJaguar(UINT8 deviceNumber, ControlMode controlMode)
	: m_deviceNumber (deviceNumber)
	, m_controlMode (controlMode)
{
}

CANJaguar::~CANJaguar()
{

}

void CANJaguar::Set(float fValue)
{
	m_fValue = fValue;
}

float CANJaguar::Get()
{
	return m_fValue;
}
