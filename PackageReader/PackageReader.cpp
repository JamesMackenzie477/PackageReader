#include <iostream>
#include "PackageManager.h"

int main()
{
	// Opens the package.
	PackageManager manager("D:\\Games\\AeriaGames\\Ironsight\\data\\script.wpg");
	// Ensures the package exists.
	if (manager)
	{
		// Iterates through the package files.
		for (auto& file : manager)
		{
			// Prints the filename.
			std::cout
				<< "\nFilename: " << file.Filename
				<< "\nCompressed: " << file.Compressed
				<< "\nEncrypted: " << file.Encrypted
				<< "\n";
		}

		// std::cout << manager.Get("script\\soundlink.txt").Filename << std::endl;
	}
	// Waits for the user.
	std::cin.get();
}