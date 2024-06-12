#pragma once
#include <string>
#include <vector>
#include "PackageStream.h"

// Used to manage the files within a package.
class PackageManager
{
	// Contains the files stored within the package.
	std::vector<PackageFile> Files;

public:

	// Reads the package from a file.
	PackageManager(std::string path);

	// Reads the package from a buffer.
	// PackageManager(const char * buffer);

	// True if the package is valid.
	operator bool() const;

	// File retrieval methods.

	PackageFile Get(std::string filename);

	PackageFile Get(int index);

	// File insertation methods.

	// void Replace(const PackageFile& file);

	void Add(std::string filename, const char * buffer, bool encrypt = false, bool compress = true); // if the file already exists, overwrite it.

	// Iterator methods.

	std::vector<PackageFile>::iterator begin();

	std::vector<PackageFile>::iterator end();

	// Stream methods.

	void operator<< (const PackageFile& file);

	// Index method overide (index linked list - call get(int index)).
};