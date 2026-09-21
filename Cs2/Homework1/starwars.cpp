#include "starwars.h"

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


    starwars::Sith::Sith(string sname, int shealth, int sskill, int sforce)
    {
        _sname = sname;
        _shealth = shealth;
        _slightsaberSkill = sskill;
        _sforcePower = sforce;
    }

   int starwars::Sith::getsHealth()
   {
        return _shealth;
   }

   int starwars::Sith::getslightsaber()
   {
        return _slightsaberSkill;
   }

   int starwars::Sith::getsforcePower()
   {
        return _sforcePower;
   }

   
