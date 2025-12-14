#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    // ---- Constructors & Destructor ----
    FragTrap(void);
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &src);
    FragTrap &operator=(const FragTrap &rhs);
    ~FragTrap(void);

    // ---- Member Functions ----
    void highFivesGuys(void);
};

#endif
