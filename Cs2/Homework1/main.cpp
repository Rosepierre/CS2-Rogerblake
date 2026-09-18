#include <iostream>
#include <starwars.h>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    string jediname;
    int jedihealth;
    int jediforce;
    int jedilightsaber;
    

    cout << "Here you will create your jedi, First enter your jedi's First and last name: ";
    getline(cin, jediname);
    
    if (jediname == "Jeremy Bergen")
    {
        cout << 'Jedi: Jeremy Bergen == oxymoron for he is a dark lord of the sith';
        abort();
    }
    cout << "Now your jedi's health: ";
    cin >> jedihealth;
    cout << "Now your jedi's force power: ";
    cin >> jediforce;
    cout << "And Finally your jedi's lightsaber skill: ";
    cin >> jedilightsaber;

    starwars::Jedi j1(jediname, jedihealth, jedilightsaber, jediforce);

}