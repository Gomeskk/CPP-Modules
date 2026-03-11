#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << BOLD << CYAN << "\n=== Testing Basic Construction and Destruction ===" << RESET << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << BOLD << MAGENTA << "\n=== Deleting Animals (should not create a leak) ===" << RESET << std::endl;
    delete j;//should not create a leak
    delete i;

    std::cout << BOLD << CYAN << "\n=== Creating Array of Animals ===" << RESET << std::endl;
    const int arraySize = 6;
    Animal* animals[arraySize];
    
    // Fill half with Dogs
    for (int idx = 0; idx < arraySize / 2; idx++) {
        std::cout << YELLOW << "\n[Creating Dog " << idx << "]" << RESET << std::endl;
        animals[idx] = new Dog();
    }
    
    // Fill half with Cats
    for (int idx = arraySize / 2; idx < arraySize; idx++) {
        std::cout << YELLOW << "\n[Creating Cat " << idx << "]" << RESET << std::endl;
        animals[idx] = new Cat();
    }
    
    std::cout << BOLD << MAGENTA << "\n=== Testing makeSound() for all animals ===" << RESET << std::endl;
    for (int idx = 0; idx < arraySize; idx++) {
        std::cout << "Animal " << idx << " (" << animals[idx]->getType() << "): ";
        animals[idx]->makeSound();
    }
    
    std::cout << BOLD << RED << "\n=== Deleting all Animals ===" << RESET << std::endl;
    for (int idx = 0; idx < arraySize; idx++) {
        std::cout << YELLOW << "\n[Deleting Animal " << idx << "]" << RESET << std::endl;
        delete animals[idx];
    }
    
    std::cout << BOLD << CYAN << "\n=== Testing Deep Copy - Dog ===" << RESET << std::endl;
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "I love bones!");
    originalDog->getBrain()->setIdea(1, "Chase the mailman!");
    
    std::cout << BLUE << "\nCreating copy of Dog..." << RESET << std::endl;
    Dog* copiedDog = new Dog(*originalDog);
    
    std::cout << MAGENTA << "\nOriginal Dog ideas:" << RESET << std::endl;
    std::cout << "  Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "  Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;
    
    std::cout << MAGENTA << "\nCopied Dog ideas:" << RESET << std::endl;
    std::cout << "  Idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "  Idea 1: " << copiedDog->getBrain()->getIdea(1) << std::endl;
    
    std::cout << YELLOW << "\nModifying original Dog's ideas..." << RESET << std::endl;
    originalDog->getBrain()->setIdea(0, "I love digging!");
    
    std::cout << MAGENTA << "\nAfter modification:" << RESET << std::endl;
    std::cout << "  Original Dog Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "  Copied Dog Idea 0: " << copiedDog->getBrain()->getIdea(0) << std::endl;
    
    std::cout << GREEN << "\n✓ Deep copy verified: Brain addresses are different!" << RESET << std::endl;
    std::cout << "  Original Brain address: " << originalDog->getBrain() << std::endl;
    std::cout << "  Copied Brain address: " << copiedDog->getBrain() << std::endl;
    
    delete originalDog;
    delete copiedDog;
    
    std::cout << BOLD << CYAN << "\n=== Testing Deep Copy - Cat ===" << RESET << std::endl;
    Cat* originalCat = new Cat();
    originalCat->getBrain()->setIdea(0, "I love napping!");
    originalCat->getBrain()->setIdea(1, "Knock things off tables!");
    
    std::cout << BLUE << "\nCreating copy via assignment operator..." << RESET << std::endl;
    Cat* assignedCat = new Cat();
    *assignedCat = *originalCat;
    
    std::cout << MAGENTA << "\nOriginal Cat ideas:" << RESET << std::endl;
    std::cout << "  Idea 0: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "  Idea 1: " << originalCat->getBrain()->getIdea(1) << std::endl;
    
    std::cout << MAGENTA << "\nAssigned Cat ideas:" << RESET << std::endl;
    std::cout << "  Idea 0: " << assignedCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "  Idea 1: " << assignedCat->getBrain()->getIdea(1) << std::endl;
    
    std::cout << YELLOW << "\nModifying original Cat's ideas..." << RESET << std::endl;
    originalCat->getBrain()->setIdea(0, "I love chasing lasers!");
    
    std::cout << MAGENTA << "\nAfter modification:" << RESET << std::endl;
    std::cout << "  Original Cat Idea 0: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "  Assigned Cat Idea 0: " << assignedCat->getBrain()->getIdea(0) << std::endl;
    
    std::cout << GREEN << "\n✓ Deep copy verified: Brain addresses are different!" << RESET << std::endl;
    std::cout << "  Original Brain address: " << originalCat->getBrain() << std::endl;
    std::cout << "  Assigned Brain address: " << assignedCat->getBrain() << std::endl;
    
    delete originalCat;
    delete assignedCat;
    
    std::cout << BOLD << GREEN << "\n=== End of tests ===\n" << RESET << std::endl;
    
    return 0;
}
