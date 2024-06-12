#pragma once
#include <fstream>
#include <string>
#include "Definitions.h"
#include "PackageFile.h"

// A low level package reading stream.
class PackageStream
{
	// The file stream object used to pull data from the package.
	std::ifstream Stream;

	// The count of files within the stream.
	unsigned int Count;

	// The stream's index into the files.
	unsigned int Index;

public:

	// Opens the specified package as a stream.
	PackageStream(std::string path);

	// Returns the amount of packages in the stream.
	unsigned int GetCount() const;

	// Sets the stream's package index.
	void SetIndex(unsigned int index);

	// Gets the next file from the package stream.
	PackageFile Get();

	// True if the package is valid.
	operator bool() const;

	// Gets the next file from the package stream.
	void operator>> (PackageFile& file);

	// Adds a package to the package stream.
	// void operator<< (const PackageFile& file);

	// Takes a package file to write.
	// The manager wil not take a pakage file, it will create a package file via the given parameters and call this function.
};