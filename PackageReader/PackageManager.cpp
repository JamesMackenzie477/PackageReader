#include "PackageManager.h"

PackageManager::PackageManager(std::string path)
{
	// Opens the file.
	PackageStream stream(path);
	if (stream)
	{
		// Adds the package files to the files list.
		for (unsigned int i = 0; i < stream.GetCount(); i++)
		{
			Files.push_back(stream.Get());
		}
	}
}

PackageManager::operator bool() const
{
	return true;
}

PackageFile PackageManager::Get(std::string filename)
{
	for (const PackageFile& file : Files)
	{
		if (file.Filename == filename)
		{
			return file;
		}
	}
}

PackageFile PackageManager::Get(int index)
{
	return Files[index];
}

std::vector<PackageFile>::iterator PackageManager::begin()
{
	return Files.begin();
}

std::vector<PackageFile>::iterator PackageManager::end()
{
	return Files.end();
}
