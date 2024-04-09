#include "Player.h"

Player::Player(bool willChangeChoice) : willChangeChoice(willChangeChoice)
{
}

void Player::MakeChoice(unsigned int maxChoices, std::mt19937 &gen)
{
    currentChoice = gen() % maxChoices;
}

void Player::ChangeChoiceIfSetGivenWrongChoice(unsigned int maxChoices, unsigned int wrongChoice, std::mt19937 &gen)
{
    if (willChangeChoice)
    {
        const unsigned int previousChoice = currentChoice;
        do
        {
            currentChoice = gen() % maxChoices;
        }while(currentChoice == wrongChoice || currentChoice == previousChoice);
    }
}

unsigned int Player::GetCurrentChoice() const
{
    return currentChoice;
}
