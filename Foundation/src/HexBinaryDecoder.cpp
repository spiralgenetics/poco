//
// HexBinaryDecoder.cpp
//
// $Id: //poco/1.3/Foundation/src/HexBinaryDecoder.cpp#1 $
//
// Library: Foundation
// Package: Streams
// Module:  HexBinary
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


#include "Poco/HexBinaryDecoder.h"
#include "Poco/Exception.h"


namespace Poco {


HexBinaryDecoderBuf::HexBinaryDecoderBuf(std::istream& istr): _istr(istr)
{
}


HexBinaryDecoderBuf::~HexBinaryDecoderBuf()
{
}


int HexBinaryDecoderBuf::readFromDevice()
{
	int c;
	int n;
	if ((n = readOne()) == -1) return -1;
	if (n >= '0' && n <= '9')
		c = n - '0';
	else if (n >= 'A' && n <= 'F')
		c = n - 'A' + 10;
	else if (n >= 'a' && n <= 'f')
		c = n - 'a' + 10;
	else throw DataFormatException();
	c <<= 4;
	if ((n = readOne()) == -1) return -1;
	if (n >= '0' && n <= '9')
		c |= n - '0';
	else if (n >= 'A' && n <= 'F')
		c |= n - 'A' + 10;
	else if (n >= 'a' && n <= 'f')
		c |= n - 'a' + 10;
	else throw DataFormatException();
	return c;
}


int HexBinaryDecoderBuf::readOne()
{
	int ch = _istr.get();
	while (ch == ' ' || ch == '\r' || ch == '\t' || ch == '\n')
		ch = _istr.get();
	return ch;
}


HexBinaryDecoderIOS::HexBinaryDecoderIOS(std::istream& istr): _buf(istr)
{
	poco_ios_init(&_buf);
}


HexBinaryDecoderIOS::~HexBinaryDecoderIOS()
{
}


HexBinaryDecoderBuf* HexBinaryDecoderIOS::rdbuf()
{
	return &_buf;
}


HexBinaryDecoder::HexBinaryDecoder(std::istream& istr): HexBinaryDecoderIOS(istr), std::istream(&_buf)
{
}


HexBinaryDecoder::~HexBinaryDecoder()
{
}


} // namespace Poco
