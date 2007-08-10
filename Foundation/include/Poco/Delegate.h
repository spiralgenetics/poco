//
// Delegate.h
//
// $Id: //poco/1.3/Foundation/include/Poco/Delegate.h#1 $
//
// Library: Foundation
// Package: Events
// Module:  Delegate
//
// Implementation of the Delegate template.
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


#ifndef  Foundation_Delegate_INCLUDED
#define  Foundation_Delegate_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/AbstractDelegate.h"
#include "Poco/Expire.h"


namespace Poco {


template <class TObj, class TArgs> 
class Delegate: public AbstractDelegate<TArgs>
{
public:
	typedef void (TObj::*NotifyMethod)(const void*, TArgs&);

	Delegate(TObj* obj, NotifyMethod method):
		AbstractDelegate<TArgs>(obj),
		_receiverObject(obj), 
		_receiverMethod(method)
	{
	}

	Delegate(const Delegate& delegate):
		AbstractDelegate<TArgs>(delegate),
		_receiverObject(delegate._receiverObject),
		_receiverMethod(delegate._receiverMethod)
	{
	}

	~Delegate()
	{
	}
	
	Delegate& operator = (const Delegate& delegate)
	{
		if (&delegate != this)
		{
			this->_pTarget        = delegate._pTarget;
			this->_receiverObject = delegate._receiverObject;
			this->_receiverMethod = delegate._receiverMethod;
		}
		return *this;
	}

	bool notify(const void* sender, TArgs& arguments)
	{
		(_receiverObject->*_receiverMethod)(sender, arguments);
		return true; // a "standard" delegate never expires
	}

	AbstractDelegate<TArgs>* clone() const
	{
		return new Delegate(*this);
	}

protected:
	TObj*        _receiverObject;
	NotifyMethod _receiverMethod;

private:
	Delegate();
};


} // namespace Poco


#endif
