//
// Connection.h
//
// $Id: //poco/1.4/Shell/include/Poco/Shell/Connection.h#1 $
//
// Library: Shell
// Package: Shell
// Module:  Connection
//
// Definition of the Connection class.
//
// Copyright (c) 2009-2013, Applied Informatics Software Engineering GmbH.
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


#ifndef Shell_Connection_INCLUDED
#define Shell_Connection_INCLUDED


#include "Poco/Shell/Shell.h"
#include "Poco/Net/TCPServerConnection.h"


namespace Poco {
namespace Shell {


class CommandProcessor;


class Shell_API Connection: public Poco::Net::TCPServerConnection
	/// The Connection class receives commands over a TCP connection
	/// and sends responses back to the client.
	///
	/// Commands are received one per line, and responses are sent in
	/// RFC 2821-style response chunks. Every command can send
	/// multiple response chunks. Intermediate response chunks have a
	/// status code of 100, and can occur more than once.
	/// The final chunk has a status code has a 200, 4xx or 500 status code
	/// and is exactly one line long.
	/// If the command was successful, the status code is 200 and the
	/// response text is "OK". If the command was not successful
	/// (its return code was not 0), the status code is 400 + return code.
	/// If the comand resulted in an exception, the status code is 500.
	///
	/// Example (positive response to help command):
	///     100-The following commands are available:
	///     100-bundles (ls, ss)
	///     100-services (lss)
	///     100-start
	///     100-stop
	///     ...
	///     100-set
	///     100 Enter <command> --help for more information about a command
	///     200 OK
	///
	/// Example (negative response to login command):
	///     403 DENIED
{
public:
	enum StatusCode
	{
		STATUS_INTERMEDIATE  = 100,
		STATUS_OK            = 200,
		STATUS_GOODBYE       = 201,
		STATUS_CLIENT_ERROR  = 400,
		STATUS_CLIENT_USAGE  = 401,
		STATUS_CLIENT_DENIED = 403, 
		STATUS_SERVER_ERROR  = 500
	};
	
	Connection(const Poco::Net::StreamSocket& s, CommandProcessor& processor, const std::string& authServiceName);
		/// Creates the Connection.
		
	~Connection();
		/// Destroys the Connection.
		
	// TCPServerConnection
	void run();

protected:
	static int statusFor(int exitCode, std::string& message);
		/// Creates a suitable status code and response message
	
private:
	Connection();
	
	CommandProcessor& _commandProcessor;
	std::string _authServiceName;
};


} } // namespace Poco::Shell


#endif // Shell_Connection_INCLUDED