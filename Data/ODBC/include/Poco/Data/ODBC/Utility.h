//
// Utility.h
//
// $Id: //poco/1.3/Data/ODBC/include/Poco/Data/ODBC/Utility.h#2 $
//
// Library: ODBC
// Package: ODBC
// Module:  Utility
//
// Definition of Utility.
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


#ifndef ODBC_Utility_INCLUDED
#define ODBC_Utility_INCLUDED


#include "Poco/Data/ODBC/ODBC.h"
#include "Poco/Data/ODBC/DataTypes.h"
#include <sstream>
#ifdef POCO_OS_FAMILY_WINDOWS
#include <windows.h>
#endif
#include <sqltypes.h>


namespace Poco {
namespace Data {
namespace ODBC {


class ODBC_API Utility
	/// Various utility functions
{
public:
	typedef std::map<std::string, std::string> DSNMap;
	typedef DSNMap DriverMap;

	static bool isError(SQLRETURN rc);
		/// Returns true if return code is error

	static DriverMap& drivers(DriverMap& driverMap);
		/// Returns driver-attributes map of available ODBC drivers.

	static DSNMap& dataSources(DSNMap& dsnMap);
		/// Returns DSN-description map of available ODBC data sources.

	template<typename MapType, typename KeyArgType, typename ValueArgType>
	static typename MapType::iterator mapInsert(MapType& m, const KeyArgType& k, const ValueArgType& v)
		/// Utility map "insert or replace" function (from S. Meyers: Effective STL, Item 24)
	{
		typename MapType::iterator lb = m.lower_bound(k);
		if (lb != m.end() && !(m.key_comp()(k, lb->first)))
		{
			lb->second = v;
			return lb;
		}
		else
		{
			typedef typename MapType::value_type MVT;
			return m.insert(lb, MVT(k,v));
		}
	}

	static int cDataType(int sqlDataType);
		/// Returns C data type corresponding to supplied SQL data type.

	static int sqlDataType(int cDataType);
		/// Returns SQL data type corresponding to supplied C data type.

	static const SQLSMALLINT boolDataType;
		/// ODBC size for bool data type.

private:
	static const DataTypes _dataTypes;
		/// C <==> SQL data type mapping
};


///
/// inlines
///
inline bool Utility::isError(SQLRETURN rc)
{
	return (0 != (rc & (~1)));
}


inline int Utility::cDataType(int sqlDataType)
{
	return _dataTypes.cDataType(sqlDataType);
}


inline int Utility::sqlDataType(int cDataType)
{
	return _dataTypes.sqlDataType(cDataType);
}


} } } // namespace Poco::Data::ODBC


#endif
