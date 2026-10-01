#include <iostream>
#include <fstream>
#include <cstdlib>   
#include <ctime>
#include "starwars.h"
using namespace std;

void getInfo() 
{
    ifstream f("characters.txt");
    string fromfile;
    while(getline(f,fromfile))
    {
        cout << fromfile << std::endl;
    }
    f.close();
}


int main(int argc, char* argv[])
{
    string jediName;
    //char maybe;
    int jediHealth;
    int jediForce;
    int jediLightsaber;
    int choice;
    starwars::Jedi* player = nullptr;
    starwars::Sith* enemy = nullptr;

    cout << "Here you will create your jedi. First pick from a Jedi Consular or a Guaridian:  \n";

    cout << "1 for Consular, 2 for Guardian or 3 for default. \n";
    
    cin >> choice;

    cout << "Now your jedi's name: \n";

    cin.ignore();
    getline(cin, jediName);
    
    if (jediName == "Jeremy Bergen")
    {
        cout << "ERROR JEREMY BERGEN is a known dark lord of the sith \n";
        return 0;
    }

    cout << "Now your jedi's health: ";
    cin >> jediHealth;

    cout << "Your jedi's lightsaber skill: ";
    cin >> jediLightsaber;

    cout << "Now your jedi's force power: ";
    cin >> jediForce;
    
if(choice == 1)
{
    player = new starwars::Consular(
        jediName, jediHealth, jediLightsaber, jediForce
    );

    player->saveToFile(jediName, jediHealth, jediLightsaber, jediForce);
    player->loadFromFile();
    getInfo();
}

else if(choice == 2)
{
    player = new starwars::Guardian(
        jediName, jediHealth, jediLightsaber, jediForce
    );

    player->saveToFile(jediName, jediHealth, jediLightsaber, jediForce);
    player->loadFromFile();
    getInfo();
}

else
{
    player = new starwars::Jedi(
        jediName, jediHealth, jediLightsaber, jediForce
    );

    player->loadFromFile();
    getInfo();
}
       
   

    srand(static_cast<unsigned int>(time(nullptr)));

    int random = rand() % 2;

    if(random == 0)
    {
        enemy = new starwars::Acolyte;
    }
    else
    {
        enemy = new starwars::Darth;
    }

while(player->getHealth() > 0 && enemy->getHealth() > 0)
{
    player->takeDamage(enemy->attack());
    enemy->takeDamage(player->attack());

    player->ouchietime();
    enemy->ouchietime();
}

delete player;
delete enemy;

}