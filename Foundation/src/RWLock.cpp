//
// RWLock.cpp
//
// $Id: //poco/1.4/Foundation/src/RWLock.cpp#3 $
//
// Library: Foundation
// Package: Threading
// Module:  RWLock
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/RWLock.h"


#if defined(POCO_OS_FAMILY_WINDOWS)
#if defined(_WIN32_WCE)
#include "RWLock_WINCE.inc"
#else
#include "RWLock_WIN32.inc"
#endif
#elif defined(POCO_ANDROID)
#include "RWLock_Android.inc"
#elif defined(POCO_VXWORKS)
#include "RWLock_VX.inc"
#else
#include "RWLock_POSIX.inc"
#endif


namespace Poco {


RWLock::RWLock()
{
}

	
RWLock::~RWLock()
{
}


} // namespace Poco
