#include "starwars.h"

namespace starwars {

Character::Character(std::string name, int health, int skill, int force)
    : _cName(name), _cHealth(health), _cLightsaberskill(skill), _cForcepower(force)
{
}

Jedi::Jedi(std::string name, int health, int skill, int force)
    : Character(name, health, skill, force)
{
}

Guardian::Guardian(std::string name, int health, int skill, int force)
    : Jedi(name, health, skill, force)
{
}

Consular::Consular(std::string name, int health, int skill, int force)
    : Jedi(name, health, skill, force)
{
}


Sith::Sith(std::string name, int health, int skill, int force)
    : Character(name, health, skill, force)
{
}

Acolyte::Acolyte(std::string name, int health, int skill, int force)
    : Sith(name, health, skill, force)
{
}

Darth::Darth(std::string name, int health, int skill, int force)
    : Sith(name, health, skill, force)
{
}

int Character::getHealth()
{
    return _cHealth;
}

int Character::getSkill()
{
    return _cLightsaberskill;
}

int Character::getForce()
{
    return _cForcepower;
}

int Character::attack()
{
    return _cLightsaberskill;
}

int Character::useforce(int power)
{
    _cForcepower = _cForcepower - power;
    return _cForcepower;
}

void Character::takeDamage(int damage)
{
    _cHealth = _cHealth - damage;
}

string Character::getName()
{
    return _cName;
}

Character& Character::operator+(int increase)
{
     _cHealth += increase;
     
     return *this;
   
}

Character& Character::operator-(int decrease)
{
     _cHealth -= decrease;
     
     return *this;
   
}

std::ostream& operator<<(std::ostream& out, const Character& character)
{
    out << "Name: " << character._cName << '\n';
    out << "Health: " << character._cHealth << '\n';
    out << "Attack Power: " << character._cLightsaberskill << '\n';

    return out;
}

 bool Character::operator==(const Character& ch2) const
 {
    return _cHealth == ch2._cHealth;
 }

 bool Character::operator!=(const Character& ch2) const
 {
    return _cHealth != ch2._cHealth;
 }

 bool Character::operator<(const Character& ch2) const
 {
    return _cHealth < ch2._cHealth;
 }

 bool Character::operator>(const Character& ch2) const
 {
    return _cHealth > ch2._cHealth;
 }

}
