#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << BOLD << CYAN << "\n=== Testing Animal, Dog, and Cat ===" << RESET << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << BOLD << YELLOW << "\n=== Type information ===" << RESET << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << BOLD << MAGENTA << "\n=== Testing makeSound() ===" << RESET << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    std::cout << BOLD << RED << "\n=== Cleaning up Animal, Dog, and Cat ===" << RESET << std::endl;
    delete meta;
    delete j;
    delete i;
    
    std::cout << BOLD << CYAN << "\n=== Testing WrongAnimal and WrongCat ===" << RESET << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << BOLD << YELLOW << "\n=== Type information ===" << RESET << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    
    std::cout << BOLD << MAGENTA << "\n=== Testing makeSound() - should output WrongAnimal sound ===" << RESET << std::endl;
    wrongCat->makeSound(); // Will output WrongAnimal sound (no virtual)
    wrongMeta->makeSound();
    
    std::cout << BOLD << RED << "\n=== Cleaning up WrongAnimal and WrongCat ===" << RESET << std::endl;
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << BOLD << CYAN << "\n=== Additional tests: Direct object creation ===" << RESET << std::endl;
    Dog mydog;
    Cat mycat;
    
    std::cout << BOLD << YELLOW << "\n=== Testing direct objects ===" << RESET << std::endl;
    std::cout << "My dog is type: " << mydog.getType() << std::endl;
    std::cout << "My cat is type: " << mycat.getType() << std::endl;
    mydog.makeSound();
    mycat.makeSound();
    
    std::cout << BOLD << MAGENTA << "\n=== Testing copy constructor ===" << RESET << std::endl;
    Dog copyDog(mydog);
    copyDog.makeSound();
    
    std::cout << BOLD << MAGENTA << "\n=== Testing assignment operator ===" << RESET << std::endl;
    Cat newCat;
    newCat = mycat;
    newCat.makeSound();
    
    std::cout << BOLD << GREEN << "\n=== End of tests ===" << RESET << std::endl;
    
    return 0;
}
