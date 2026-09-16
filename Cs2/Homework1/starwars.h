#pragma once
#include <iostream>



namespace starwars {

    class Jedi
    {
        private:
        std::string name = "Unknown Jedi";
        int health = 100;
        int lightsaberSkill = 50;
        int forcePower = 75;
    };
}
