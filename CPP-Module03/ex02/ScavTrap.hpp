#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    // ---- Constructors & Destructor ----
    ScavTrap(void);
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &src);
    ScavTrap &operator=(const ScavTrap &rhs);
    ~ScavTrap(void);

    // ---- Member Functions ----
    void attack(const std::string &target);
    void guardGate(void);
};

#endif
