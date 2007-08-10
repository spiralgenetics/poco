//
// HTTPCookieTest.cpp
//
// $Id: //poco/1.3/Net/testsuite/src/HTTPCookieTest.cpp#1 $
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
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


#include "HTTPCookieTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/Net/HTTPCookie.h"


using Poco::Net::HTTPCookie;


HTTPCookieTest::HTTPCookieTest(const std::string& name): CppUnit::TestCase(name)
{
}


HTTPCookieTest::~HTTPCookieTest()
{
}


void HTTPCookieTest::testCookie()
{
	HTTPCookie cookie("name", "value");
	assert (cookie.getName() == "name");
	assert (cookie.getValue() == "value");
	assert (cookie.toString() == "name=value");
	cookie.setPath("/");
	assert (cookie.toString() == "name=value; path=/");
	cookie.setComment("comment");
	assert (cookie.toString() == "name=value; path=/");
	cookie.setDomain("appinf.com");
	assert (cookie.toString() == "name=value; domain=appinf.com; path=/");
	cookie.setSecure(true);
	assert (cookie.toString() == "name=value; domain=appinf.com; path=/; secure");
	
	cookie.setVersion(1);
	assert (cookie.toString() == "name=\"value\"; Comment=\"comment\"; Domain=\"appinf.com\"; Path=\"/\"; secure; Version=\"1\"");
	
	cookie.setSecure(false);
	cookie.setMaxAge(100);
	assert (cookie.toString() == "name=\"value\"; Comment=\"comment\"; Domain=\"appinf.com\"; Path=\"/\"; Max-Age=\"100\"; Version=\"1\"");
}


void HTTPCookieTest::setUp()
{
}


void HTTPCookieTest::tearDown()
{
}


CppUnit::Test* HTTPCookieTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("HTTPCookieTest");

	CppUnit_addTest(pSuite, HTTPCookieTest, testCookie);

	return pSuite;
}
