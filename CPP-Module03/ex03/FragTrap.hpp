#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(void);                             // Default constructor                     
    FragTrap(const std::string &name);          // Parameterized constructor          
    FragTrap(const FragTrap &src);              // Copy constructor
    FragTrap &operator=(const FragTrap &rhs);   // Copy assignment operator
    ~FragTrap(void);                            // Destructor

    // ---- Member Functions ----
    void highFivesGuys(void);
};

#endif
