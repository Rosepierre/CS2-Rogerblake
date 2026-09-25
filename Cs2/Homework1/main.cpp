#include <iostream>
#include <fstream>
#include "starwars.h"
using namespace std;

int main(int argc, char* argv[])
{
    string jediname;
    //char maybe;
    int jedihealth;
    int jediforce;
    int jedilightsaber;
    

    cout << "Here you will create your jedi, First enter your jedi's First and last name: ";
    getline(cin, jediname);
    
    if (jediname == "Jeremy Bergen")
    {
        cout << "ERROR JEREMY BERGEN is a known dark lord of the sith ";
        return 0;
    }

    cout << "Now your jedi's health: ";
    cin >> jedihealth;

    cout << "Your jedi's lightsaber skill: ";
    cin >> jedilightsaber;

    cout << "Now your jedi's force power: ";
    cin >> jediforce;
    
    starwars::saveToFile(jediname, jedihealth, jedilightsaber, jediforce);
    
    starwars::Jedi j1(jediname, jedihealth, jedilightsaber, jediforce);
    j1.getForce();
    j1.getHealth();
    j1.getSkill();
    j1.saveToFile(jediname, jedihealth, jedilightsaber, jediforce);
    

    //starwars::Sith s1();

}
