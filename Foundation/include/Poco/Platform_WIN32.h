//
// Platform_WIN32.h
//
// $Id: //poco/1.3/Foundation/include/Poco/Platform_WIN32.h#4 $
//
// Library: Foundation
// Package: Core
// Module:  Platform
//
// Platform and architecture identification macros
// and platform-specific definitions for Windows.
//
// Copyright (c) 2004-2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_Platform_WIN32_INCLUDED
#define Foundation_Platform_WIN32_INCLUDED


// Verify that we're built with the multithreaded 
// versions of the runtime libraries
#if defined(_MSC_VER) && !defined(_MT)
	#error Must compile with /MD, /MDd, /MT or /MTd
#endif


// Check debug/release settings consistency
#if defined(NDEBUG) && defined(_DEBUG)
	#error Inconsistent build settings (check for /MD[d])
#endif


// Reduce bloat imported by "Poco/UnWindows.h"
#if defined(_WIN32)
	#if !defined(_WIN32_WINNT)
		#define _WIN32_WINNT 0x0500
	#endif
	#if !defined(WIN32_LEAN_AND_MEAN) && !defined(POCO_BLOATED_WIN32)
		#define WIN32_LEAN_AND_MEAN
	#endif
#endif


// Unicode Support
#if defined(UNICODE) && !defined(POCO_WIN32_UTF8)
	#define POCO_WIN32_UTF8
#endif


// Turn off some annoying warnings
#if defined(_MSC_VER)
	#pragma warning(disable:4018) // signed/unsigned comparison
	#pragma warning(disable:4251) // ... needs to have dll-interface warning 
	#pragma warning(disable:4355) // 'this' : used in base member initializer list
	#pragma warning(disable:4996) // VC++ 8.0 deprecation warnings
	#pragma warning(disable:4351) // new behavior: elements of array '...' will be default initialized
	#pragma warning(disable:4675) // resolved overload was found by argument-dependent lookup
#endif


#endif // Foundation_Platform_WIN32_INCLUDED
