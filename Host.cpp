#include "Host.h"

#include <iostream>

Host::Host(unsigned int numberOfOptions, bool playerWillChangeChoice, bool beVerbose) : beVerbose(beVerbose), choices(numberOfOptions, false), numberOfOptions(numberOfOptions), player(playerWillChangeChoice)
{
    std::random_device rd;
    gen.seed(rd());
    
    const unsigned int correct = gen() % numberOfOptions;
    choices[correct] = true;

    if (beVerbose)
    {
        std::cout << "Correct Options is " << correct << "\n";
    }
}

void Host::PlayGame()
{
    player.MakeChoice(numberOfOptions, gen);

    if (beVerbose)
    {
        std::cout << "Player Choose " << player.GetCurrentChoice() << "\n";
    }

   
    auto invertedChoices = choices;
    invertedChoices.flip();
    invertedChoices[player.GetCurrentChoice()] = false;
    
    std::discrete_distribution<int> dist(invertedChoices.begin(), invertedChoices.end());
    
    const unsigned int wrongChoice = dist(gen);

    if (beVerbose)
    {
        std::cout << "Choice to reveal is " << wrongChoice << "\n";
    }
    
    player.ChangeChoiceIfSetGivenWrongChoice(numberOfOptions, wrongChoice, gen);

    if (beVerbose)
    {
        std::cout << "Player Changed Choice to " << player.GetCurrentChoice() << "\n";
    }
}

bool Host::IsPlayerCorrect() const
{
    return choices[player.GetCurrentChoice()];
}
