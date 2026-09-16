#pragma once
#include <iostream>

namespace starwars {

    class Jedi
    {
        private:
            std::string _name = "Unknown Jedi";
            int _health = 100;
            int _lightsaberSkill = 50;
            int _forcePower = 75;
        
        public:
            Jedi(std::string name = "Unknown Jedi");
            int getHealth();
            int getSkill();
            int getForce();

        starwars::Jedi::Jedi(std::string name)
        {
            _name = name;
        }

        int starwars::Jedi::getHealth(int health)
        {
            _health = health;
        }

        int starwars::Jedi::getSkill(int skill)
        {
            _lightsaberSkill = skill;
        }

        int starwars::Jedi::getForce(int force)
        {
            _forcePower = force;
        }
    };
    
   class Sith
   {

   };
}
