#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;  // pointer may or may not have a weapon

public:
    HumanB(std::string name);
    ~HumanB();
    
    void setWeapon(Weapon& weapon);
    void attack();
};

#endif