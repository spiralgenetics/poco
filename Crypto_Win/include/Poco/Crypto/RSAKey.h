//
// RSAKey.h
//
// $Id$
//
// Library: Crypto_Win
// Package: RSA
// Module:  RSAKey
//
// Definition of the RSAKey class.
//
// Copyright (c) 2006-2014, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Crypto_RSAKey_INCLUDED
#define Crypto_RSAKey_INCLUDED


#include "Poco/Crypto/Crypto.h"
#include "Poco/Crypto/RSAKeyImpl.h"


namespace Poco {
namespace Crypto {


class X509Certificate;


class Crypto_Win_API RSAKey
	/// This class stores an RSA key pair, consisting
	/// of private and public key. Storage of the private
	/// key is optional.
	///
	/// If a private key is available, the RSAKey can be
	/// used for decrypting data (encrypted with the public key)
	/// or computing secure digital signatures.
{
public:
	enum KeyLength
	{
		KL_512  = 512,
		KL_1024 = 1024,
		KL_2048 = 2048,
		KL_4096 = 4096
	};

	enum Exponent
	{
		EXP_SMALL = 0,
		EXP_LARGE
	};

	explicit RSAKey(const X509Certificate& cert);
		/// Extracts the RSA public key from the given certificate.

	RSAKey(KeyLength keyLength, Exponent exp = EXP_SMALL);
		/// Creates the RSAKey. Creates a new public/private key pair using the given parameters.
		/// Can be used to sign data and verify signatures.
		///
		/// The Exponent parameter will be ignored and is provided for API compatibility with the 
		/// OpenSSL implementation only.

	RSAKey(const std::string& publicKeyFile, const std::string& privateKeyFile = "", const std::string& privateKeyPassphrase = "");
		/// Creates the RSAKey, by reading public and private key from the given files and
		/// using the given passphrase for the private key. Can only by used for signing if 
		/// a private key is available. 

	RSAKey(std::istream* pPublicKeyStream, std::istream* pPrivateKeyStream = 0, const std::string& privateKeyPassphrase = "");
		/// Creates the RSAKey. Can only by used for signing if pPrivateKeyStream
		/// is not null.

	~RSAKey();
		/// Destroys the RSAKey.

	int size() const;
		/// Returns the RSA modulus size.

	void save(const std::string& publicKeyFile, const std::string& privateKeyFile = "", const std::string& privateKeyPassphrase = "");
		/// Exports the public and private keys to the given files. 
		///
		/// If an empty filename is specified, the corresponding key
		/// is not exported.

	void save(std::ostream* pPublicKeyStream, std::ostream* pPrivateKeyStream = 0, const std::string& privateKeyPassphrase = "");
		/// Exports the public and private key to the given streams.
		///
		/// If a null pointer is passed for a stream, the corresponding
		/// key is not exported.

	RSAKeyImpl::Ptr impl() const;
		/// Returns the impl object.

	const std::string& name() const;
		/// Returns "rsa"
	
private:
	RSAKeyImpl::Ptr _pImpl;
};


//
// inlines
//
inline RSAKeyImpl::Ptr RSAKey::impl() const
{
	return _pImpl;
}


} } // namespace Poco::Crypto


#endif // Crypto_RSAKey_INCLUDED
