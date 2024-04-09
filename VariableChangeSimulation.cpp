// VariableChangeSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This is meant to simulate the scenerio where you are told to pick from N options. One of those options is correct.
// After you choose the host will reveal one of the inccorect options and then asks if you want to change your choice.
// According to the internet, changing your choice at this point increases your odds of success.
// this simulation is designed to test that. 

#include <iostream>
#include "Host.h"

int main()
{
    unsigned int numberOfRuns = 0;
    bool shouldBeVerbose = false;
    bool shouldPlayerChangeChoice = false;

    std::cout << "Enter number of runs to perform:";
    std::cin >> numberOfRuns;
    std::cout << "Should the player change choice? (1 for yes, 0 for no):";
    std::cin >> shouldPlayerChangeChoice;
    std::cout << "Should the simulation be verbose? (1 for yes, 0 for no):";
    std::cin >> shouldBeVerbose;
    
    std::cout << "starting run ";
    
    std::vector<bool> numberOfSuccesses(numberOfRuns, false);
    unsigned int increment = numberOfRuns / 10; 
    increment = increment ? increment : 1;
    
    for(unsigned int i=0;i<numberOfRuns;i++)
    {
        if(i%increment == 0)
        {
            std::cout << ".";
            std::flush(std::cout);
        }

        if (shouldBeVerbose)
        {
            std::cout << "..... new game .....\n";
        }
        
        Host host(3, shouldPlayerChangeChoice, shouldBeVerbose);

        host.PlayGame();

        numberOfSuccesses[i] = host.IsPlayerCorrect();
    }

    std::cout << " Finished\n";

    const auto result = std::count(numberOfSuccesses.begin(), numberOfSuccesses.end(), true);
    std::cout << "\nNumber of successes: " << result << " out of " << numberOfRuns << " runs\n";
    std::cout << "Success rate: " << (static_cast<float>(result) / static_cast<float>(numberOfRuns)) * 100 << "%\n";
}
