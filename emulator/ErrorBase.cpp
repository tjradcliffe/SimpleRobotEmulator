/*!
  ErrorBase.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "ErrorBase.h"

Error ErrorBase::globalError;


ErrorBase::ErrorBase() {;}

ErrorBase::~ErrorBase(){;}

Error& ErrorBase::GetError()
{
	return error;
}

const Error& ErrorBase::GetError() const
{
	return error;
}

void ErrorBase::SetError(Error::Code code, const char* filename, UINT32 lineNumber) const
{
}

void ErrorBase::ClearError()
{
}

bool ErrorBase::StatusIsFatal() const
{
	return false;
}

Error& ErrorBase::GetGlobalError()
{
	return globalError;
}

