#include <iostream>		// for std::cout and std::cin
#include <string>		//to make strings
#include <fstream>		//to write things to file
#include <limits>
#include "SQLstuff.h"

std::string userInput();

int logRead()
{
	bool funcLoop{true};

	do
	{
		std::cout << "\n Input ID of the entry your wish to read. \n\n";
			
		std::string nameEntry{ userInput() };

		if (nameEntry == "exit")
		{
			return 0;
		}

		sqlRead(nameEntry);
		funcLoop = false;

	
	} while (funcLoop == true);

	//Send request to database for entry

	return 0;
}
