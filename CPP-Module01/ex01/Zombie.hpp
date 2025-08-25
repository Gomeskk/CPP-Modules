#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <string>
#include <sstream>

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class Zombie {
private:
    std::string name;

public:
    Zombie();                   // Default constructor needed for array allocation
    Zombie(std::string name);   // named constructor
    ~Zombie();                  // destructor
    
    void announce(void);
    void setName(std::string name); // Setter for name
};

// Function to create a horde of zombies
Zombie* zombieHorde(int N, std::string name);

#endif