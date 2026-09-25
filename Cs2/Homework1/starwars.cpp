#include "starwars.h"

starwars::Jedi::Jedi(std::string name, int health, int skill, int force)
{
    _name = name;
    _health = health;
    _lightsaberSkill = skill;
    _forcePower = force;
}

int starwars::Jedi::getHealth()
{
    return _health;
}

int starwars::Jedi::getSkill()
{
    return _lightsaberSkill;
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

void starwars::Jedi::takeDamage(int damage)
{
    int ouch = _health - damage;
    _health = ouch;
}

starwars::Sith::Sith(string sname, int shealth, int sskill, int sforce)
{
    _sname = sname;
    _shealth = shealth;
    _slightsaberSkill = sskill;
    _sforcePower = sforce;
}

int starwars::Sith::getsHealth()
{
    return _shealth;
}

int starwars::Sith::getslightsaber()
{
    return _slightsaberSkill;
}

int starwars::Sith::getsforcePower()
{
    return _sforcePower;
}

int starwars::Sith::sattack()
{
    return _slightsaberSkill;
}

void starwars::Sith::suseForce(int power)
{
    int newpow = _sforcePower - power;
    _sforcePower = newpow;
}

void starwars::Sith::stakeDamage(int damage)
{
    int ouch = _shealth - damage;
    _shealth = ouch;
}
