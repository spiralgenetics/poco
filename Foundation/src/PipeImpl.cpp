//
// PipeImpl.cpp
//
// Library: Foundation
// Package: Processes
// Module:  PipeImpl
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/PipeImpl.h"


#if defined(POCO_OS_FAMILY_WINDOWS)
#if defined(_WIN32_WCE)
#include "PipeImpl_DUMMY.inc"
#else
#include "PipeImpl_WIN32.inc"
#endif
#elif defined(POCO_OS_FAMILY_UNIX)
#include "PipeImpl_POSIX.inc"
#else
#include "PipeImpl_DUMMY.inc"
#endif
