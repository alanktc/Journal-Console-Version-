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

		/*
		nameEntry = "D:/C++/Journal Database/Journal Entries/" + nameEntry + ".txt";
		std::string txtEntry;
		
		std::ifstream targetEntry;
		targetEntry.open(nameEntry);

		if (targetEntry.is_open())
		{
			while (std::getline(targetEntry >> std::ws, txtEntry));
			{
				std::cout << '\n' << "Found it!" << "\n\n" << txtEntry << "\n\n";
			}

			targetEntry.close();
			funcLoop = false;
		}
		


		else
		{
			std::cout << "\n No such entry exists. Please enter again. Or type \"exit\" to leave \n\n";
		}
		*/
	} while (funcLoop == true);

	//Send request to database for entry

	return 0;
}
