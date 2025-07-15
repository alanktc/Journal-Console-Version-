#include <iostream>		// for std::cout and std::cin
#include <string>		//to make strings
#include <fstream>		//to write things to file
//#include <filesystem>
#include "SQLstuff.h"

//namespace fs = std::filesystem;



std::string userInput();

int logList()
{
	sqlList();
	/*
	std::cout << "\n Here you go!! \n\n";
	std::string path = "D:/C++/Journal Database/Journal Entries/";
	for (const auto& entry : fs::directory_iterator(path))
		std::cout << entry.path() << std::endl;
	*/



	return 0;
}
