#pragma once
#include <iostream>
#include <fstream>

using namespace std;

namespace starwars {

    class Character
    {
        protected:
        std::string _cName;
        int _cHealth;
        int _cLightsaberskill;
        int _cForcepower;

        public:
        Character(string name = "Unknown force user", int health = 100, int skill = 50, int force = 75);
        int getHealth();
        int getSkill();
        int getForce();
        int attack();
        int useforce(int power);
        void takeDamage(int damage);
    };

    class Jedi : public Character
    {
        public:
            Jedi(string name = "Unknown Jedi", int health = 100, int skill = 50, int force = 75);

            void ouchietime()

            {
                cout << "Jedi name: " << _cName  << " Jedi Health: "<< _cHealth << '\n';
            }

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
            ifstream f("characters.txt");
            if (!f) return;

            string name;
            int health, skill, force;

            getline(f, name);
            f >> health >> skill >> force;

            *this = Jedi(name, health, skill, force);
        }
    };

    class Guardian : public Jedi
    {
        public:
        Guardian(string name = "Guardian", int health = 150, int lightsaberskill = 70, int force = 75);
    };

    class Consular : Jedi
    {
        public:
        Consular(string name = "Consular",  int _cHealth = 100, int lightsaberskill = 50, int force = 120);
    };

    class Sith : public Character
   {
        public:
            Sith(string sname= "Darth Bergen", int shealth = 120, int slightsaber = 60, int sforcepower= 75);

            void ouchietime()
            {
                cout << "Sith name: " << _cName  << " Sith Health: "<< _cHealth << '\n';
            }
   };
   
   class Acolyte : Sith
   {
    public:
        Acolyte(string name ="Acolyte", int health = 80, int lightsaber = 40, int force = 75);
   };

   class Darth : Sith
   {
    public:
        Darth(string name ="Darth", int health = 200, int lightsaber = 100, int force = 75);
   };

}
