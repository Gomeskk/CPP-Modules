#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name) {
    std::cout << GREEN << "🧠 Creating a horde of " << N << " zombies named " << name << "..." << RESET << std::endl;
    
    // Allocate N zombies in a single allocation
    Zombie* horde = new Zombie[N];
    
    // Initialize each zombie with the given name
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    
    return horde;
}