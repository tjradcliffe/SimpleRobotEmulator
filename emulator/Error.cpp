/*!
  Error.cpp
 
   Created on: 2010-02-27
       Author: Thomas Radcliffe
 */

#include "Error.h"

Error::Error() {;}
Error::~Error() {;}
Error::Code Error::GetCode() const {return m_code;}
const char* Error::GetMessage() const {return m_message.c_str();}
const char* Error::GetFilename() const {return m_filename.c_str();}
UINT32 Error::GetLineNumber() const {return m_lineNumber;}
   const ErrorBase* Error::GetOriginatingObject() const {return m_originatingObject;}
void Error::Clear()
{
	m_code = 0;
	m_message = "";
	m_filename = "";
	m_lineNumber = -1;
	m_originatingObject = 0;
}

void Error::Set(Error::Code code, const char* filename, UINT32 lineNumber, const ErrorBase* originatingObject)
{
	m_code = code;
	m_message = "";
	m_filename = filename;
	m_lineNumber = lineNumber;
	m_originatingObject = originatingObject;
}

