//
// ThreadLocalTest.cpp
//
// $Id: //poco/1.3/Foundation/testsuite/src/ThreadLocalTest.cpp#1 $
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


#include "ThreadLocalTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/ThreadLocal.h"
#include "Poco/Thread.h"
#include "Poco/Runnable.h"


using Poco::ThreadLocal;
using Poco::Thread;
using Poco::Runnable;


class TLTestRunnable: public Runnable
{
public:
	TLTestRunnable(int n): _n(n)
	{
	}

	void run()
	{
		*_count = 0;
		for (int i = 0; i < _n; ++i)
			++(*_count);
		_result = *_count;
	}
	
	int result()
	{
		return _result;
	}
	
private:
	int _n;
	int _result;
	static ThreadLocal<int> _count;
};


struct TLTestStruct
{
	int i;
	std::string s;
};


ThreadLocal<int> TLTestRunnable::_count;


ThreadLocalTest::ThreadLocalTest(const std::string& name): CppUnit::TestCase(name)
{
}


ThreadLocalTest::~ThreadLocalTest()
{
}


void ThreadLocalTest::testLocality()
{
	TLTestRunnable r1(5000);
	TLTestRunnable r2(7500);
	TLTestRunnable r3(6000);
	Thread t1;
	Thread t2;
	Thread t3;
	t1.start(r1);
	t2.start(r2);
	t3.start(r3);
	t1.join();
	t2.join();
	t3.join();
	
	assert (r1.result() == 5000);
	assert (r2.result() == 7500);
	assert (r3.result() == 6000);
}


void ThreadLocalTest::testAccessors()
{
	ThreadLocal<TLTestStruct> ts;
	ts->i = 100;
	ts->s = "foo";
	assert ((*ts).i == 100);
	assert ((*ts).s == "foo");
	assert (ts.get().i == 100);
	assert (ts.get().s == "foo");
}


void ThreadLocalTest::setUp()
{
}


void ThreadLocalTest::tearDown()
{
}


CppUnit::Test* ThreadLocalTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("ThreadLocalTest");

	CppUnit_addTest(pSuite, ThreadLocalTest, testLocality);
	CppUnit_addTest(pSuite, ThreadLocalTest, testAccessors);

	return pSuite;
}
