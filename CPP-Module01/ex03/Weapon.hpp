#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class Weapon {
private:
    std::string type;

public:
    Weapon(std::string type);
    ~Weapon();
    
    const std::string& getType() const;
    void setType(std::string type);
};

#endif