#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(void);                             // Default constructor
    ScavTrap(const std::string &name);          // Parameterized constructor
    ScavTrap(const ScavTrap &src);              // Copy constructor
    ScavTrap &operator=(const ScavTrap &rhs);   // Copy assignment operator
    ~ScavTrap(void);                            // Destructor

    // ---- Member Functions ----
    void attack(const std::string &target);
    void guardGate(void);
};

#endif
