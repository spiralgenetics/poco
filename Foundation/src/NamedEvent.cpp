//
// NamedEvent.cpp
//
// Library: Foundation
// Package: Processes
// Module:  NamedEvent
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/NamedEvent.h"


#if defined(POCO_OS_FAMILY_WINDOWS) && defined(POCO_WIN32_UTF8)
#include "NamedEvent_WIN32U.inc"
#elif defined(POCO_OS_FAMILY_WINDOWS)
#include "NamedEvent_WIN32.inc"
#elif POCO_OS == POCO_OS_ANDROID
#include "NamedEvent_Android.inc"
#elif defined(POCO_OS_FAMILY_UNIX)
#include "NamedEvent_UNIX.inc"
#endif


namespace Poco {


NamedEvent::NamedEvent(const std::string& name):
	NamedEventImpl(name)
{
}


NamedEvent::~NamedEvent()
{
}


} // namespace Poco
