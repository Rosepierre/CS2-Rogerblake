#pragma once
#include <iostream>
#include <fstream>

using namespace std;

namespace starwars {

    class Character
    {
        public:
        string _cName = "Unknown force user";
        int _cHealth;
        int _cLightsaberskill;
        int _cForcepower;
        int getHealth();
        int getSkill();
        int getForce();
        int attack();
        Character(string name = "Unknown force user", int health = 100, int skill = 50, int force = 75);
        void takeDamage(int damage);
    };

    class Jedi : public Character
    {
        private:
            string _name = "Unknown Jedi";
            int _health = 100;
            int _lightsaberSkill = 50;
            int _forcePower = 75;
        
        public:
            Jedi(string name = "Unknown Jedi", int health = 100, int skill = 50, int force = 75);
            int getHealth();
            int getSkill();
            int getForce();
            int attack();
            void useForce(int power);
            void takeDamage(int damage);

            void ouchietime()
            {
                cout << "Jedi name: " << _name  << " Jedi Health: "<< _health << '\n';
            }
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
                string line_2;
                getline(f, line_2);
                string line_3;
                getline(f, line_3);
                string line_4;
                getline(f, line_4);
                Jedi(line_1, stoi(line_2), stoi(line_3), stoi(line_4));
            }
 };
    
   class Sith : public Character
   {
        private:
            string _sname = "Unknown Sith";
            int _shealth = 120;
            int _slightsaberSkill = 60;
            int _sforcePower = 75;
        
        public:
            Sith(string sname= "Darth Bergen", int shealth = 120, int slightsaber = 60, int sforcepower= 75);
            int getsHealth();
            int getslightsaber();
            int getsforcePower();
            int sattack();
            void suseForce(int power);
            void takeDamage(int damage);
            void ouchietime()
            {
                cout << "Sith name: " << _sname  << " Sith Health: "<< _shealth << '\n';
            }
   };
   
}