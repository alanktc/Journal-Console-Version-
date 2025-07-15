#include <iostream>		// for std::cout and std::cin
#include <string>		//to make strings
#include <fstream>		//to write things to file
#include <filesystem>
#include "SQLstuff.h"


std::string userInput();


int logDelete()
{
	bool funcLoop{ true };
	do
	{

		std::cout << "\n Please enter the ID of the entry you wish to delete: \n";
		std::string deleteEntry{userInput()};

		if (deleteEntry == "exit")
		{
			funcLoop = false;

			return 0;
		}

		sqlDelete(deleteEntry);

		/*
		deleteEntry = "D:/C++/Journal Database/Journal Entries/" + deleteEntry + ".txt";

		if (std::filesystem::remove(deleteEntry))
		{
			std::cout << "\n Entry " << deleteEntry << " deleted.\n\n";
			funcLoop = false;
		}

		else
		{
			std::cout << "\n Entry " << deleteEntry << " not found.\n\n";
		}
		*/
		return 0;
	} while (funcLoop == true);



	return 0;
}