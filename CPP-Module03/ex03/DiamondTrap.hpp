#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;

public:
    DiamondTrap(void);                                  // Default constructor
    DiamondTrap(const std::string &name);               // Parameterized constructor
    DiamondTrap(const DiamondTrap &src);                // Copy constructor
    DiamondTrap &operator=(const DiamondTrap &rhs);     // Copy assignment operator
    ~DiamondTrap(void);                                 // Destructor

    // ---- Member Functions ----
    using ScavTrap::attack;
    void whoAmI(void);
};

#endif
