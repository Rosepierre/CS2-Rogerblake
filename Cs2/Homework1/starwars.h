#pragma once
#include <iostream>
#include <fstream>

using namespace std;

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
            void savetoFile();

        void saveToFile(string _name, int _health, int _lightsaberSkill, int _forcePower)
        {
            std::ofstream file("characters.txt", std::ios::app);
            
                if (file)
                {
                    file << _name << ' ' 
                    << _health << ' '
                    << _lightsaberSkill << ' '
                    << _forcePower;
                }
        }

        void getInfo() 
        {
            std::ifstream f("characters.txt");
        }
        
    };

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

    
    
   class Sith
   {
        private:
            std::string _sname = "Unknown Sith";
            int _shealth = 120;
            int _slightsaberSkill = 60;
            int _sforcePower = 75;
        
        public:
            Sith(std::string sname= "Unknown Sith", int shealth = 120, int slightsaber = 60, int sforcepower= 75);
            int getsHealth();
            int getslightsaber();
            int getsforcePower();
   };

   
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

   
}
