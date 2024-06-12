#pragma once
#include <string>

// Allows viewing and manipulation of a file within a package.
class PackageFile
{
public:

	// The name and path of the file.
	std::string Filename;

	// A pointer to the file data.
	const char * Buffer;

	// True if the file is compressed.
	bool Compressed;

	// True if the file is encrypted.
	bool Encrypted;

	PackageFile() {}

	PackageFile(std::string filename, const char * buffer, bool encrypted = false, bool compressed = true)
		: Filename(filename), Buffer(buffer), Encrypted(encrypted), Compressed(compressed)
	{}

	PackageFile& operator= (const PackageFile& other);

	// Decompresses the file data.
	//auto decompress();

	// Decrypts the file data.
	//auto decrypt();

	// Returns the file.
	//auto get();

	// Returns the original file (before decompression and decryption).
	//auto get_original();
};