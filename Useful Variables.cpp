#include <cstdlib>  // Needed for rand() and srand()
#include <random>   // For random distribution
#include <iostream> // for std::cout and std::cin
#include <string>


//This part randomly generates computer's choice and show what the computer chose
int randNo()
{
    const int range_from = 1;
    const int range_to = 99;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);

    int randNo = distr(generator);


    return randNo;
}

std::string userInput()
{
    std::string userInput{};
    std::getline(std::cin >> std::ws, userInput);

    return userInput;
}