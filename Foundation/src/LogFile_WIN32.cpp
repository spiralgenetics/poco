//
// LogFile_WIN32.cpp
//
// $Id: //poco/1.3/Foundation/src/LogFile_WIN32.cpp#2 $
//
// Library: Foundation
// Package: Logging
// Module:  LogFile
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
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


#include "Poco/LogFile_WIN32.h"
#include "Poco/File.h"
#include "Poco/Exception.h"


namespace Poco {


LogFileImpl::LogFileImpl(const std::string& path): _path(path)
{
	_hFile = CreateFileA(path.c_str(), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (_hFile == INVALID_HANDLE_VALUE) throw OpenFileException(path);
	SetFilePointer(_hFile, 0, 0, FILE_END);
	// There seems to be a strange "optimization" in the Windows NTFS
	// filesystem that causes it to reuse directory entries of deleted
	// files. Example:
	// 1. create a file named "test.dat"
	//    note the file's creation date
	// 2. delete the file "test.dat"
	// 3. wait a few seconds
	// 4. create a file named "test.dat"
	//    the new file will have the same creation
	//    date as the old one.
	// We work around this bug by taking the file's
	// modification date as a reference when the
	// file is empty.
	if (sizeImpl() == 0)
		_creationDate = File(path).getLastModified();
	else
		_creationDate = File(path).created();
}


LogFileImpl::~LogFileImpl()
{
	CloseHandle(_hFile);
}


void LogFileImpl::writeImpl(const std::string& text)
{
	DWORD bytesWritten;
	BOOL res = WriteFile(_hFile, text.data(), (DWORD) text.size(), &bytesWritten, NULL);
	if (!res) throw WriteFileException(_path);
	res = WriteFile(_hFile, "\r\n", 2, &bytesWritten, NULL);
	if (!res) throw WriteFileException(_path);
	res = FlushFileBuffers(_hFile);
	if (!res) throw WriteFileException(_path);
}


UInt64 LogFileImpl::sizeImpl() const
{
	LARGE_INTEGER li;
	li.HighPart = 0;
	li.LowPart  = SetFilePointer(_hFile, 0, &li.HighPart, FILE_CURRENT);
	return li.QuadPart;
}


Timestamp LogFileImpl::creationDateImpl() const
{
	return _creationDate;
}


const std::string& LogFileImpl::pathImpl() const
{
	return _path;
}


} // namespace Poco
