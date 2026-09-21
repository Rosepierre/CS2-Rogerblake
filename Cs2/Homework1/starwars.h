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
            void saveToFile();
            //void getInfo();

        void saveToFile(string _name, int _health, int _lightsaberSkill, int _forcePower)
        {
            std::ofstream file("characters.txt", std::ios::app);
            
                if (file)
                {
                    file << _name << ' ' 
                    << _health << ' '
                    << _lightsaberSkill << ' '
                    << _forcePower << '\n';
                }
        }

        void getInfo() 
        {
            ifstream f("characters.txt");
            string fromfile;
            while(getline(f,fromfile))
            {
                cout << "The Jedi: " << fromfile << std::endl;
            }
            f.close();
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
