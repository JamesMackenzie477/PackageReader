#include "PackageFile.h"

PackageFile & PackageFile::operator=(const PackageFile & other)
{
	Filename = other.Filename;
	Buffer = other.Buffer;
	Compressed = other.Compressed;
	Encrypted = other.Encrypted;
	return *this;
}
