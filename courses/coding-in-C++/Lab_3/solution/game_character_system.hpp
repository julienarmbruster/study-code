#ifndef GAME_CHARACTER_SYSTEM_HPP
#define GAME_CHARACTER_SYSTEM_HPP

#include <string>

constexpr int MAX_LEVEL = 10;
constexpr int NUM_LEVEL_LIMITS = MAX_LEVEL - 1;

class Character
{
protected:
    std::string name;
    unsigned int healthPoints;
    unsigned int level;
    unsigned int experiencePoints;
    static unsigned int levelLimits[NUM_LEVEL_LIMITS];

public:
    Character(std::string name, unsigned int healthPoints,
              unsigned int level, unsigned int experiencePoints);
    Character &damageTaken(unsigned int dmg);
};

class Mage : public Character
{
protected:
    unsigned int magicPoints;

public:
    Mage(std::string name, unsigned int healthPoints,
         unsigned int level, unsigned int experiencePoints, unsigned int magicPoints);
    Mage &regenerateMagicPoints();
};

class Healer : public Mage
{
public:
    Healer(std::string name, unsigned int healthPoints,
           unsigned int level, unsigned int experiencePoints, unsigned int magicPoints);
    Healer &heal(unsigned int healthPoints, const Character &target);
};

#endif