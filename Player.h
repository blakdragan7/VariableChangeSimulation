#pragma once
#include <random>

class Player
{
    unsigned int currentChoice = 0;
    bool willChangeChoice;
    
public:
    Player(bool willChangeChoice);
    
    void MakeChoice(unsigned int maxChoices, std::mt19937 &gen);
    void ChangeChoiceIfSetGivenWrongChoice(unsigned int maxChoices, unsigned int wrongChoice, std::mt19937 &gen);
    unsigned int GetCurrentChoice() const;
};

