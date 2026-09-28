#include "starwars.h"

starwars::Character::Character(std::string name, int health, int skill, int force)
{
    _cName = name;
    _cHealth = health;
    _cLightsaberskill = skill;
    _cForcepower = force;
}

int starwars::Character::getHealth()
{
    return _cHealth;
}

int starwars::Character::getSkill()
{
    return _cLightsaberskill;
}

int starwars::Jedi::getForce()
{
    return _forcePower;
}

int starwars::Jedi::attack()
{
    return _lightsaberSkill;
}

void starwars::Jedi::useForce(int power)
{
    int newpow = _forcePower - power;
    _forcePower = newpow;
}

void starwars::Character::takeDamage(int damage)
{
    _cHealth = _cHealth - damage;
}

/*starwars::Sith::Sith(string sname, int shealth, int sskill, int sforce)
{
    _sname = sname;
    _shealth = shealth;
    _slightsaberSkill = sskill;
    _sforcePower = sforce;
}*/

int starwars::Sith::getsHealth()
{
    return _cHealth;
}

int starwars::Sith::getslightsaber()
{
    return _cLightsaberskill;
}

int starwars::Sith::getsforcePower()
{
    return _cForcepower;
}

int starwars::Sith::sattack()
{
    return _cLightsaberskill;
}

void starwars::Sith::suseForce(int power)
{
    int newpow = _sforcePower - power;
    _sforcePower = newpow;
}

/*void starwars::Sith::stakeDamage(int damage)
{
    int ouch = _shealth - damage;
    _shealth = ouch;
}*/
