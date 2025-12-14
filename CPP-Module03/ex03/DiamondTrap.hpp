#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;

public:
    // ---- Constructors & Destructor ----
    DiamondTrap(void);
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &src);
    DiamondTrap &operator=(const DiamondTrap &rhs);
    ~DiamondTrap(void);

    // ---- Member Functions ----
    using ScavTrap::attack;
    void whoAmI(void);
};

#endif
