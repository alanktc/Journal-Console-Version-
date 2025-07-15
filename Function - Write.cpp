#include <iostream>		// for std::cout and std::cin
#include <string>		//to make strings
#include <fstream>		//to write things to file
#include <ctime>		//gets the time stuff
#include "SQLstuff.h"


std::string userInput();
int randNo();

const char* timeFormat{};


std::string getTime(const char* timeFormat)
{
	char buffer[80];															//This whole part finds the date and time at saving of entry
	time_t rawtime;																
	tm timeinfo;																
	
	time(&rawtime);																	
	localtime_s(&timeinfo, &rawtime);												
	
	strftime(buffer, sizeof(buffer), timeFormat, &timeinfo);						
	std::string getTime{buffer};			
	return getTime;
}

//This function creates an entry
int logWrite()
{
	std::string funcConfirm{};

	timeFormat = "%y%m%d%H%M%S";
	std::string idTime{ getTime(timeFormat) };							 		//This calls the getTIme function to get the right time info	

																
	auto idNum = idTime + std::to_string(randNo());								//This part gets a random number from Random Num.cpp

	//std::string pathEntry{"D:/C++/Journal Database/Journal Entries/"};			//This part combines random number with time of entry creation to make entry id	
	//std::string idEntry{ pathEntry + idNum + ".txt" };

	//const char *nameEntry[80]{};
	//*nameEntry = idEntry.c_str();												//This part turns the id into char		


	std::cout << "\n What do you want to write about? \n\n";
	std::string inputEntry{};													//This string stores the user's input
	std::string finalEntry{};													//This string is what actually get appended to file
	//std::ofstream myfile;														//This creates the variable for the file path
	//myfile.open(*nameEntry, std::ios_base::app);								//This part adds the file path into the variable and makes sure input appends the file

	do
	{	
		inputEntry = userInput() ;

		finalEntry = finalEntry + " " + inputEntry;

		do
		{

			std::cout << "\n Done? would you like to save? (y/n) \n\n";

			funcConfirm = userInput();

			if (funcConfirm == "y")
			{				
				timeFormat = "%F %T";
				std::string entryTime{ getTime(timeFormat) };							 						//This calls the getTIme function to get the right time info	

				finalEntry = "Entry written on : " + entryTime + "\n\n" + finalEntry + "\n\n\n\n\n\n";			//This string is what ends up getting appended to the file AND combines the time&date&stuff AND the user's input													

				//myfile << finalEntry;																			//This part FINALLY appends the date & time of the entry to the file
				//myfile.close();

				sqlWrite(finalEntry,idNum);
				std::cout << "\n Entry saved. Returning to main menu. \n";

				return 0;
			}

			else if (funcConfirm == "n")
			{

				std::cout << "\n You may continue writing \n\n";

			}

			else
			{
				std::cout << "\n Sorry. I don't understand. Please input a valid response.\n\n";
			}


		} while (funcConfirm != "n");

	} while (funcConfirm != "y");

	funcConfirm = ' ';
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 0;
}


