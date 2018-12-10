//
// Event.cpp
//
// Library: Foundation
// Package: Threading
// Module:  Event
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/Event.h"


#if defined(POCO_OS_FAMILY_WINDOWS)
#include "Event_WIN32.inc"
#elif defined(POCO_VXWORKS)
#include "Event_VX.inc"
#else
#include "Event_POSIX.inc"
#endif


namespace Poco {


Event::Event(bool autoReset): EventImpl(autoReset)
{
}


Event::~Event()
{
}


} // namespace Poco
