#include "Bureaucrat.hpp"
#include "Form.hpp"

static void printSeparator(const std::string& title) {
    std::cout << std::endl;
    std::cout << BOLD << MAGENTA << "═══════════════════════════════════════" << RESET << std::endl;
    std::cout << BOLD << YELLOW  << "  " << title << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "═══════════════════════════════════════" << RESET << std::endl;
}

int main() {

    // ── Test 1: Valid Form construction and operator<< ─────────────────────────
    printSeparator("Test 1: Valid Form construction");
    {
        Form tax("Tax Return", 50, 25);
        std::cout << tax << std::endl;
    }

    // ── Test 2: Form grade too high (grade < 1) ───────────────────────────────
    printSeparator("Test 2: Form GradeTooHighException");
    {
        try {
            Form bad("Bad Form", 0, 10);
        }
        catch (std::exception& e) {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }

    // ── Test 3: Form grade too low (grade > 150) ──────────────────────────────
    printSeparator("Test 3: Form GradeTooLowException");
    {
        try {
            Form bad("Bad Form", 10, 151);
        }
        catch (std::exception& e) {
            std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
        }
    }

    // ── Test 4: Bureaucrat signs a form successfully ───────────────────────────
    printSeparator("Test 4: Successful signing");
    {
        Bureaucrat ceo("CEO", 1);
        Form contract("Contract", 10, 5);
        std::cout << contract << std::endl;
        ceo.signForm(contract);
        std::cout << contract << std::endl;
    }

    // ── Test 5: Bureaucrat's grade too low to sign ────────────────────────────
    printSeparator("Test 5: Failed signing (grade too low)");
    {
        Bureaucrat intern("Intern", 149);
        Form classified("Classified Report", 5, 3);
        std::cout << classified << std::endl;
        intern.signForm(classified);
        std::cout << classified << std::endl;
    }

    // ── Test 6: Exact grade boundary (grade == gradeToSign) ───────────────────
    printSeparator("Test 6: Boundary — grade equals required sign grade");
    {
        Bureaucrat mid("Mid", 42);
        Form memo("Memo", 42, 100);
        mid.signForm(memo);
        std::cout << memo << std::endl;
    }

    // ── Test 7: One grade below boundary ──────────────────────────────────────
    printSeparator("Test 7: Boundary — one grade too low");
    {
        Bureaucrat almost("Almost", 43);
        Form memo("Memo", 42, 100);
        almost.signForm(memo);
        std::cout << memo << std::endl;
    }

    // ── Test 8: Form already signed, sign again ───────────────────────────────
    printSeparator("Test 8: Sign an already-signed form");
    {
        Bureaucrat boss("Boss", 1);
        Form report("Report", 1, 1);
        boss.signForm(report);
        std::cout << "Signing again..." << std::endl;
        boss.signForm(report);
        std::cout << report << std::endl;
    }

    // ── Test 9: Form operator<< shows all info ────────────────────────────────
    printSeparator("Test 9: Form insertion operator");
    {
        Form f("Annual Budget", 5, 10);
        Bureaucrat director("Director", 5);
        std::cout << "Before: " << f << std::endl;
        director.signForm(f);
        std::cout << "After:  " << f << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
