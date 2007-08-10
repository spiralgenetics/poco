//
// ChildNodesTest.cpp
//
// $Id: //poco/1.3/XML/testsuite/src/ChildNodesTest.cpp#1 $
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


#include "ChildNodesTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/DOM/Document.h"
#include "Poco/DOM/Element.h"
#include "Poco/DOM/NodeList.h"
#include "Poco/DOM/AutoPtr.h"


using Poco::XML::Element;
using Poco::XML::Document;
using Poco::XML::NodeList;
using Poco::XML::Node;
using Poco::XML::AutoPtr;


ChildNodesTest::ChildNodesTest(const std::string& name): CppUnit::TestCase(name)
{
}


ChildNodesTest::~ChildNodesTest()
{
}


void ChildNodesTest::testChildNodes()
{
	AutoPtr<Document> pDoc = new Document;
	AutoPtr<Element> pRoot = pDoc->createElement("root");

	assert (!pRoot->hasChildNodes());
	AutoPtr<NodeList> pNL = pRoot->childNodes();
	assert (pNL->length() == 0);
	
	AutoPtr<Element> pChild1 = pDoc->createElement("child1");
	pRoot->appendChild(pChild1);
	assert (pRoot->hasChildNodes());
	
	assert (pNL->length() == 1);
	assert (pNL->item(0) == pChild1);

	AutoPtr<Element> pChild2 = pDoc->createElement("child2");
	pRoot->appendChild(pChild2);

	assert (pNL->length() == 2);
	assert (pNL->item(0) == pChild1);
	assert (pNL->item(1) == pChild2);
	
	AutoPtr<Element> pChild0 = pDoc->createElement("child0");
	pRoot->insertBefore(pChild0, pChild1);

	assert (pNL->length() == 3);
	assert (pNL->item(0) == pChild0);
	assert (pNL->item(1) == pChild1);
	assert (pNL->item(2) == pChild2);

	pRoot->removeChild(pChild1);
	assert (pNL->length() == 2);
	assert (pNL->item(0) == pChild0);
	assert (pNL->item(1) == pChild2);

	pRoot->removeChild(pChild0);
	assert (pNL->length() == 1);
	assert (pNL->item(0) == pChild2);

	pRoot->removeChild(pChild2);
	assert (pNL->length() == 0);
	assert (pNL->item(0) == 0);

	assert (!pRoot->hasChildNodes());
}


void ChildNodesTest::setUp()
{
}


void ChildNodesTest::tearDown()
{
}


CppUnit::Test* ChildNodesTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("ChildNodesTest");

	CppUnit_addTest(pSuite, ChildNodesTest, testChildNodes);

	return pSuite;
}
