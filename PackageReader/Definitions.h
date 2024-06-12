#pragma once

// defines the unique fourcc code used to identify the file format
#define FOURCC 0x474B5052
// defines the max length of a package name
#define MAX_PACK_NAME 0x80

#define INFO_COMPRESSED 1
#define INFO_ENCRYPTED 2

// defines the pack actions
// no action
#define ACTION_NONE 0
// compresses the files in the package
#define ACTION_COMPRESS 1
// encrypts the files in the package
#define ACTION_ENCRYPT 2

// definition of the structure of a package file header
typedef struct _PACKAGE_HEADER
{
	// the package fourcc code
	unsigned int FourCC;
	// the package version
	unsigned int Version;
	// contains the package root name	
	char PackageRoot[MAX_PACK_NAME];
	// contains the number of sections within the package
	unsigned int NumberOfSections;
} PACKAGE_HEADER, *PPACKAGE_HEADER;

// definition of the structure of a package file section
typedef struct _PACKAGE_SECTION
{
	// the name of the file accociated with the section
	char FileName[MAX_PACK_NAME];
	// the offset of the data block from the base of the file
	unsigned int DataOffset;
	// the size of the data block
	unsigned int DataSize;
	// contains information on whether the data is encrypted or compressed
	unsigned int DataInfo;
} PACKAGE_SECTION, *PPACKAGE_SECTION;