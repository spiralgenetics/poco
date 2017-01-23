//
// Mutex.cpp
//
// $Id: //poco/1.4/Foundation/src/Mutex.cpp#2 $
//
// Library: Foundation
// Package: Threading
// Module:  Mutex
//
// Copyright (c) 2004-2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/Mutex.h"


#if defined(POCO_OS_FAMILY_WINDOWS)
#if defined(_WIN32_WCE)
#include "Mutex_WINCE.inc"
#else
#include "Mutex_WIN32.inc"
#endif
#elif defined(POCO_VXWORKS)
#include "Mutex_VX.inc"
#else
#include "Mutex_POSIX.inc"
#endif


namespace Poco {


Mutex::Mutex()
{
}


Mutex::~Mutex()
{
}


FastMutex::FastMutex()
{
}


FastMutex::~FastMutex()
{
}


} // namespace Poco
