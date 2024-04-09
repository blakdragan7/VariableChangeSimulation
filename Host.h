#pragma once
#include <vector>
#include <random>

#include "Player.h"

class Host
{
    std::mt19937 gen;
    
    std::vector<bool> choices;
    unsigned int numberOfOptions;
    Player player;

    bool beVerbose = false;
    
public:
    Host(unsigned int numberOfOptions, bool playerWillChangeChoice, bool beVerbose = false);

    void PlayGame();
    bool IsPlayerCorrect() const;
};

