#include <iostream>
#include <fstream>
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
    
    

    cout << "Here you will create your jedi, First enter your jedi's First and last name: ";
    getline(cin, jediName);
    
    if (jediName == "Jeremy Bergen")
    {
        cout << "ERROR JEREMY BERGEN is a known dark lord of the sith ";
        return 0;
    }

    cout << "Now your jedi's health: ";
    cin >> jediHealth;

    cout << "Your jedi's lightsaber skill: ";
    cin >> jediLightsaber;

    cout << "Now your jedi's force power: ";
    cin >> jediForce;
    
    
    starwars::Jedi j1(jediName, jediHealth, jediLightsaber, jediForce);
    j1.getForce();
    j1.getHealth();
    j1.getSkill();
    j1.saveToFile(jediName, jediHealth, jediLightsaber, jediForce);
    getInfo();
    j1.loadFromFile();

    //starwars::Sith s1();

}
