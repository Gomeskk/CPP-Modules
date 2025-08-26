#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    std::cout << BOLD << CYAN << "===== UNNECESSARY VIOLENCE PROGRAM =====" << RESET << std::endl;
    std::cout << "This program demonstrates references vs pointers in class design" << std::endl << std::endl;
    
    std::cout << BOLD << GREEN << "----- Testing HumanA (uses reference) -----" << RESET << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    
    std::cout << std::endl << BOLD << BLUE << "----- Testing HumanB (uses pointer) -----" << RESET << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    
    std::cout << std::endl << BOLD << CYAN << "All humans have returned to their graves. Program ending." << RESET << std::endl;
    return 0;
}