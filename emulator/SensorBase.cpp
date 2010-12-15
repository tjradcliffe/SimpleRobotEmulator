/*!
  SensorBase.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "SensorBase.h"

UINT32 SensorBase::m_defaultAnalogModule = 0;
UINT32 SensorBase::m_defaultDigitalModule = 1;
UINT32 SensorBase::m_defaultSolenoidModule = 8;
SensorBase *SensorBase::m_singletonList = 0;

SensorBase::SensorBase() : m_nextSingleton(0) {;}
SensorBase::~SensorBase() {;}

void SensorBase::SetDefaultAnalogModule(UINT32 slot) {m_defaultAnalogModule = slot;}
void SensorBase::SetDefaultDigitalModule(UINT32 slot) {m_defaultDigitalModule = slot;}
void SensorBase::SetDefaultSolenoidModule(UINT32 slot) {m_defaultSolenoidModule = slot;}
void SensorBase::DeleteSingletons() {;}
bool SensorBase::CheckDigitalModule(UINT32 slot) {return true;}
bool SensorBase::CheckRelayModule(UINT32 slot) {return true;}
bool SensorBase::CheckPWMModule(UINT32 slot) {return true;}
bool SensorBase::CheckSolenoidModule(UINT32 slot) {return true;}
bool SensorBase::CheckAnalogModule(UINT32 slot) {return true;}
bool SensorBase::CheckDigitalChannel(UINT32 channel) {return true;}
bool SensorBase::CheckRelayChannel(UINT32 channel) {return true;}
bool SensorBase::CheckPWMChannel(UINT32 channel) {return true;}
bool SensorBase::CheckAnalogChannel(UINT32 channel) {return true;}
bool SensorBase::CheckSolenoidChannel(UINT32 channel) {return true;}

void SensorBase::AddToSingletonList() {;}
