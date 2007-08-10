//
// SQLite.h
//
// $Id: //poco/1.3/Data/SQLite/include/Poco/Data/SQLite/SQLite.h#2 $
//
// Library: SQLite
// Package: SQLIte
// Module:  SQLite
//
// Basic definitions for the Poco SQLite library.
// This file must be the first file included by every other SQLite
// header file.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
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


#ifndef SQLite_SQLite_INCLUDED
#define SQLite_SQLite_INCLUDED


#include "Poco/Foundation.h"


//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SQLite_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SQLite_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(POCO_DLL)
	#if defined(SQLite_EXPORTS)
		#define SQLite_API __declspec(dllexport)
	#else
		#define SQLite_API __declspec(dllimport)
	#endif
#endif


#if !defined(SQLite_API)
	#define SQLite_API
#endif


//
// Automatically link Data library.
//
#if defined(_MSC_VER)
	#if !defined(POCO_NO_AUTOMATIC_LIBS) && !defined(SQLite_EXPORTS)
		#if defined(POCO_DLL)
			#if defined(_DEBUG)
				#pragma comment(lib, "PocoSQLited.lib")
			#else
				#pragma comment(lib, "PocoSQLite.lib")
			#endif
		#else
			#if defined(_DEBUG)
				#pragma comment(lib, "PocoSQLitemtd.lib")
			#else
				#pragma comment(lib, "PocoSQLitemt.lib")
			#endif
		#endif
	#endif
#endif


#endif // SQLite_SQLite_INCLUDED
