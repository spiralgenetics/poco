//
// NameValueCollectionTest.cpp
//
// $Id: //poco/1.3/Net/testsuite/src/NameValueCollectionTest.cpp#1 $
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


#include "NameValueCollectionTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/Net/NameValueCollection.h"
#include "Poco/Exception.h"


using Poco::Net::NameValueCollection;
using Poco::NotFoundException;


NameValueCollectionTest::NameValueCollectionTest(const std::string& name): CppUnit::TestCase(name)
{
}


NameValueCollectionTest::~NameValueCollectionTest()
{
}


void NameValueCollectionTest::testNameValueCollection()
{
	NameValueCollection nvc;
	
	assert (nvc.empty());
	assert (nvc.size() == 0);
	
	nvc.set("name", "value");
	assert (!nvc.empty());
	assert (nvc["name"] == "value");
	assert (nvc["Name"] == "value");
	
	nvc.set("name2", "value2");
	assert (nvc.get("name2") == "value2");
	assert (nvc.get("NAME2") == "value2");
	
	assert (nvc.size() == 2);
	
	try
	{
		std::string value = nvc.get("name3");
		fail("not found - must throw");
	}
	catch (NotFoundException&)
	{
	}

	try
	{
		std::string value = nvc["name3"];
		fail("not found - must throw");
	}
	catch (NotFoundException&)
	{
	}
	
	assert (nvc.get("name", "default") == "value");
	assert (nvc.get("name3", "default") == "default");

	assert (nvc.has("name"));
	assert (nvc.has("name2"));
	assert (!nvc.has("name3"));	
	
	nvc.add("name3", "value3");
	assert (nvc.get("name3") == "value3");
	
	nvc.add("name3", "value31");
	
	NameValueCollection::ConstIterator it = nvc.find("Name3");
	assert (it != nvc.end());
	std::string v1 = it->second;
	assert (it->first == "name3");
	++it;
	assert (it != nvc.end());
	std::string v2 = it->second;
	assert (it->first == "name3");
	
	assert (v1 == "value3" && v2 == "value31" || v1 == "value31" && v2 == "value3");
	
	nvc.erase("name3");
	assert (!nvc.has("name3"));
	assert (nvc.find("name3") == nvc.end());
	
	it = nvc.begin();
	assert (it != nvc.end());
	++it;
	assert (it != nvc.end());
	++it;
	assert (it == nvc.end());
	
	nvc.clear();
	assert (nvc.empty());
	
	assert (nvc.size() == 0);
}


void NameValueCollectionTest::setUp()
{
}


void NameValueCollectionTest::tearDown()
{
}


CppUnit::Test* NameValueCollectionTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("NameValueCollectionTest");

	CppUnit_addTest(pSuite, NameValueCollectionTest, testNameValueCollection);

	return pSuite;
}
