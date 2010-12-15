#ifndef _BASE_H
#define _BASE_H

// TJR: Add phony type info here
#define UINT64 unsigned long
#define UINT32 unsigned int
#define UINT16 unsigned short
#define UINT8 unsigned char
#define INT64 long
#define INT32 int
#define INT16 short
#define INT8 char

// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

#endif
