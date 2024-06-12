#include "PackageStream.h"

PackageStream::PackageStream(std::string path)
{
	// Opens the package.
	Stream = std::ifstream(path, std::ifstream::binary);
	if (Stream)
	{
		// Validates that the file is a package.

		// Reads the package header and sets the stream attributes.
		PACKAGE_HEADER header;
		Stream.read(reinterpret_cast<char *>(&header), sizeof(header));
		Count = header.NumberOfSections;
	}
}

unsigned int PackageStream::GetCount() const
{
	return Count;
}

void PackageStream::SetIndex(unsigned int index)
{
	Index = index;
}

PackageFile PackageStream::Get()
{
	// if (Index < Count);

	// Gets the package section position.
	Stream.seekg(sizeof(PACKAGE_HEADER) + sizeof(PACKAGE_SECTION) * Index++);

	// Reads the package section.
	PACKAGE_SECTION section;
	Stream.read(reinterpret_cast<char *>(&section), sizeof(section));

	// Reads the file into a buffer.
	Stream.seekg(section.DataOffset);
	char * buffer = new char[section.DataSize];
	Stream.read(buffer, section.DataSize);

	// Translates the file into a package file object.
	return PackageFile(section.FileName, buffer, section.DataInfo & INFO_COMPRESSED, section.DataInfo & INFO_ENCRYPTED);
}

PackageStream::operator bool() const
{
	return Stream.operator bool();
}

void PackageStream::operator>>(PackageFile& file)
{
	// Gets the next file.
	PackageFile next = Get();
	file = next;
}
