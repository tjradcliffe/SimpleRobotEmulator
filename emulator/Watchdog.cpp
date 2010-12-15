/*!
  Watchdog.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "Watchdog.h"

Watchdog::Watchdog() {;}
Watchdog::~Watchdog(){;}
bool Watchdog::Feed(){return true;}
void Watchdog::Kill(){;}
double Watchdog::GetTimer(){return 0.0;}
double Watchdog::GetExpiration(){return 0.0;}
void Watchdog::SetExpiration(double expiration){;}
bool Watchdog::GetEnabled(){return true;}
void Watchdog::SetEnabled(bool enabled){;}
bool Watchdog::IsAlive(){return true;}
bool Watchdog::IsSystemActive(){return true;}
