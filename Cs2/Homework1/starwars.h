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
            int attack();
            void useForce(int power);
            void takeDamage(int damage);
            //void saveToFile(string name, int health, int skill, int force);
            //void getInfo();
            void saveToFile(std::string name, int health, int lightsaberSkill, int forcePower)
            {
                std::ofstream file("characters.txt");
            
                if (file)
                {
                    file << name << '\n' 
                    << health << '\n'
                    << lightsaberSkill << '\n'
                    << forcePower << '\n';
                }
            }

            void loadFromFile()
            {
                std::ifstream f("characters.txt");
                string line_1;
                getline(f, line_1);
                cout << line_1;
            }
 };
    
   class Sith
   {
        private:
            std::string _sname = "Unknown Sith";
            int _shealth = 120;
            int _slightsaberSkill = 60;
            int _sforcePower = 75;
        
        public:
            Sith(std::string sname= "Darth Bergen", int shealth = 120, int slightsaber = 60, int sforcepower= 75);
            int getsHealth();
            int getslightsaber();
            int getsforcePower();
   };


    
}