#include "Bureaucrat.hpp"

static void printSeparator(const std::string& title) {
    std::cout << std::endl;
    std::cout << BOLD << MAGENTA << "═══════════════════════════════════════" << RESET << std::endl;
    std::cout << BOLD << YELLOW  << "  " << title << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "═══════════════════════════════════════" << RESET << std::endl;
}

int main() {

    // ── Test 1: Valid construction and operator<< ──────────────────────────────
    printSeparator("Test 1: Valid construction");
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 75);
        Bureaucrat charlie("Charlie", 150);
        std::cout << alice   << std::endl;
        std::cout << bob     << std::endl;
        std::cout << charlie << std::endl;
    }

    // ── Test 2: Grade too high (grade < 1) ────────────────────────────────────
    printSeparator("Test 2: GradeTooHighException on construction");
    {
        try {
            Bureaucrat bad("BadHigh", 0);
            std::cout << bad << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }

    // ── Test 3: Grade too low (grade > 150) ───────────────────────────────────
    printSeparator("Test 3: GradeTooLowException on construction");
    {
        try {
            Bureaucrat bad("BadLow", 151);
            std::cout << bad << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }

    // ── Test 4: incrementGrade() at the limit ─────────────────────────────────
    printSeparator("Test 4: incrementGrade() throws at grade 1");
    {
        try {
            Bureaucrat top("Top", 1);
            std::cout << top << std::endl;
            top.incrementGrade(); // should throw
            std::cout << top << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }

    // ── Test 5: decrementGrade() at the limit ─────────────────────────────────
    printSeparator("Test 5: decrementGrade() throws at grade 150");
    {
        try {
            Bureaucrat bottom("Bottom", 150);
            std::cout << bottom << std::endl;
            bottom.decrementGrade(); // should throw
            std::cout << bottom << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }

    // ── Test 6: Normal increment / decrement ──────────────────────────────────
    printSeparator("Test 6: Normal increment and decrement");
    {
        Bureaucrat mid("Mid", 50);
        std::cout << "Before: " << mid << std::endl;
        mid.incrementGrade();
        std::cout << "After increment: " << mid << std::endl;
        mid.decrementGrade();
        mid.decrementGrade();
        std::cout << "After 2x decrement: " << mid << std::endl;
    }

    // ── Test 7: Copy constructor ───────────────────────────────────────────────
    printSeparator("Test 7: Copy constructor");
    {
        Bureaucrat orig("Original", 42);
        Bureaucrat copy(orig);
        std::cout << "Original: " << orig << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
    }

    // ── Test 8: Assignment operator ───────────────────────────────────────────
    printSeparator("Test 8: Assignment operator");
    {
        Bureaucrat a("Alpha", 10);
        Bureaucrat b("Beta", 100);
        std::cout << "Before: " << a << std::endl;
        a = b;
        std::cout << "After assignment (grade only changes): " << a << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
