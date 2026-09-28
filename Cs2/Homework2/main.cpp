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
        cout << "ERROR JEREMY BERGEN is a known dark lord of the sith \n";
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

    j1.loadFromFile();
    getInfo();

    starwars::Sith s1;
    while (j1.getHealth() > 0 && s1.getsHealth() > 0)
    {
    /*s1.getslightsaber();

    j1.attack();
    j1.getForce();*/
    j1.takeDamage(s1.sattack());
    s1.takeDamage(j1.attack());
    j1.ouchietime();
    s1.ouchietime();
    }

}