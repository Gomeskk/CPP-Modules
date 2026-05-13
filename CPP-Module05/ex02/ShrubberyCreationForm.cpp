#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
    std::cout << GREEN << "✓ ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << GREEN << "✓ ShrubberyCreationForm parameterized constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {
    std::cout << BLUE << "⎘ ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << YELLOW << "⟵ ShrubberyCreationForm copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << RED << "✗ ShrubberyCreationForm destructor called" << RESET << std::endl;
}

void ShrubberyCreationForm::executeAction() const {
    std::string filename = _target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    if (!ofs)
        throw std::runtime_error("Cannot open file: " + filename);

    ofs << BOLD << CYAN   << "  Shrubbery for: " << _target << RESET << "\n\n";
    ofs << GREEN          << "          ,@@@@@@@,\n";
    ofs                   << "  ,,,.   ,@@@@@@/@@,  " << YELLOW << ".oo8888o." << GREEN << "\n";
    ofs                   << "   ,&%%&%&&%,@@@@@/@@@@@@," << YELLOW << "8888\\88/8o" << GREEN << "\n";
    ofs                   << "  ,%&\\%&&%&&%,@@@\\@@@/@@@" << YELLOW << "88\\88888/88'" << GREEN << "\n";
    ofs                   << "  %&&%&%&/%&&%@@\\@@/ /@@@" << YELLOW << "88888\\88888'" << GREEN << "\n";
    ofs                   << "  %&&%/ %&%%&&@@\\ V /@@' `" << YELLOW << "88\\8 `/88'" << GREEN << "\n";
    ofs                   << "  `&%\\ ` /%&'    |.|        \\ '|8'\n";
    ofs                   << "      |o|        | |         | |\n";
    ofs                   << "      |.|        | |         | |\n";
    ofs                   << "   \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n" << RESET;
    ofs << "\n";
    ofs << BOLD << MAGENTA << "       *  *  *  ASCII TREE  *  *  *\n" << RESET;
    ofs << "\n";
    ofs << GREEN           << "           /\\\n";
    ofs                    << "          /  \\\n";
    ofs                    << "         /    \\\n";
    ofs                    << "        /  /\\  \\\n";
    ofs                    << "       /  /  \\  \\\n";
    ofs                    << "      /  / /\\ \\  \\\n";
    ofs                    << "     /__|/_/  \\_\\|__\\\n" << RESET;
    ofs << YELLOW          << "           |  |\n";
    ofs                    << "           |  |\n";
    ofs                    << "          /|  |\\\n" << RESET;
    ofs.close();

    std::cout << MAGENTA << "🌳 Shrubbery planted at '" << _target << "' → " << filename << RESET << std::endl;
}
