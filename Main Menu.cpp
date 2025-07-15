#include <iostream>
#include <string>

int logWrite();
int logRead();
int logList();
int logDelete();



//Main Menu Class
int mainMenu()
{
	int exitCode{ 0 };

	do
	{
		std::cout << "____________________\nMAIN MENU\n____________________\n\n  Write new entry? \n\n  Read old entry? \n\n  List all entries?  \n\n  Delete entry?  \n\n  Exit?\n\n\n\n";


		std::string userMenuChoice{};
		std::getline(std::cin >> std::ws, userMenuChoice);

		if (userMenuChoice == "write")
		{
			logWrite();
		}

		else if (userMenuChoice == "read")
		{
			logRead();
		}

		else if (userMenuChoice == "list")
		{
			logList();
		}

		else if (userMenuChoice == "delete")
		{
			logDelete();
		}

		else if (userMenuChoice == "exit")
		{
			
			return 0;
		}

		else
		{
			std::cout << "\n Invalid input. Please try again.\n\n";
		}



	} while (exitCode == 0);

	return 0;
}
