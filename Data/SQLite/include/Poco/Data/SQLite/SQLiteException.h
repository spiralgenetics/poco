//
// SQLiteException.h
//
// $Id: //poco/1.3/Data/SQLite/include/Poco/Data/SQLite/SQLiteException.h#2 $
//
// Library: SQLite
// Package: SQLite
// Module:  SQLiteException
//
// Definition of SQLiteException.
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


#ifndef SQLite_SQLiteException_INCLUDED
#define SQLite_SQLiteException_INCLUDED


#include "Poco/Data/SQLite/SQLite.h"
#include "Poco/Data/DataException.h"


namespace Poco {
namespace Data {
namespace SQLite {


POCO_DECLARE_EXCEPTION(SQLite_API, SQLiteException, Poco::Data::DataException)
POCO_DECLARE_EXCEPTION(SQLite_API, InvalidSQLStatementException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, InternalDBErrorException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, DBAccessDeniedException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, ExecutionAbortedException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, DBLockedException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, TableLockedException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, NoMemoryException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, ReadOnlyException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, InterruptException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, IOErrorException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, CorruptImageException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, TableNotFoundException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, DatabaseFullException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, CantOpenDBFileException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, LockProtocolException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, SchemaDiffersException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, RowTooBigException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, ConstraintViolationException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, DataTypeMismatchException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, InvalidLibraryUseException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, OSFeaturesMissingException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, AuthorizationDeniedException, SQLiteException)
POCO_DECLARE_EXCEPTION(SQLite_API, TransactionException, SQLiteException)


} } } // namespace Poco::Data::SQLite


#endif
