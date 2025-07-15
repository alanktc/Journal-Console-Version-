#include <iostream> // for std::cout and std::cin
#include <string>
#include "SQLstuff.h"

std::string userInput();


int mainMenu();

//Login Function
// This here asks for user password and returns 1 if correct, 0 if wrong
int loginSess()
{
	
	std::string pwCorrect{ "1" };
	do
	{
	;	
		std::cout << " Enter Password: \n\n";
		
		pwCheck (userInput());
			

	} 
	while (pwCheck == 0);

	std::cout << "\n\n Password Correct!\n\n";
	
	return 0;
}
//End of Login Function




int main()
{
	//This part starts the login process
	loginSess();

	std::cout << "Welcome buddy! \nWhat would you like to do?\n\n\n";
	mainMenu();
	

	return 0;
}
