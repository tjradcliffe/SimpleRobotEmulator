/*!
  Relay.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "Relay.h"

Relay::Relay(UINT32 channel, Relay::Direction direction)
{
	m_channel = channel;
	m_direction = direction;
}

Relay::~Relay()
{
}

void Relay::Set(Relay::Value value)
{
	m_value = value;
}

void Relay::SetDirection(Relay::Direction dir)
{
	m_direction = dir;
}
