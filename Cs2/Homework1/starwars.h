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
            Jedi(std::string name = "Unknown Jedi", int health = 100, int skill = 50, int force = 75);
            int getHealth();
            int getSkill();
            int getForce();

        starwars::Jedi::Jedi(std::string name, int health, int skill, int force)
        {
            _name = name;
            _health = health;
            _lightsaberSkill = skill;
            _forcePower = force;
        }

        int starwars::Jedi::getHealth()
        {
            return _health;
        }

        int starwars::Jedi::getSkill()
        {
            return _lightsaberSkill;
        }

        int starwars::Jedi::getForce()
        {
            return _forcePower;
        }
    };
    
   class Sith
   {

   };
}
