#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

static void printSeparator(const std::string& title) {
    std::cout << std::endl;
    std::cout << BOLD << MAGENTA << "═══════════════════════════════════════════════" << RESET << std::endl;
    std::cout << BOLD << YELLOW  << "  " << title << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "═══════════════════════════════════════════════" << RESET << std::endl;
}

int main() {

    Intern someRandomIntern;

    // ── Test 1: subject example — RobotomyRequestForm ─────────────────────────
    printSeparator("Test 1: makeForm(\"robotomy request\", \"Bender\")");
    {
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            Bureaucrat scientist("Scientist", 45);
            scientist.signForm(*rrf);
            scientist.executeForm(*rrf);
            delete rrf;
        }
    }

    // ── Test 2: ShrubberyCreationForm ─────────────────────────────────────────
    printSeparator("Test 2: makeForm(\"shrubbery creation\", \"garden\")");
    {
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
        if (scf) {
            Bureaucrat gardener("Gardener", 137);
            gardener.signForm(*scf);
            gardener.executeForm(*scf);
            delete scf;
        }
    }

    // ── Test 3: PresidentialPardonForm ────────────────────────────────────────
    printSeparator("Test 3: makeForm(\"presidential pardon\", \"Arthur Dent\")");
    {
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (ppf) {
            Bureaucrat president("President", 1);
            president.signForm(*ppf);
            president.executeForm(*ppf);
            delete ppf;
        }
    }

    // ── Test 4: Unknown form name ─────────────────────────────────────────────
    printSeparator("Test 4: makeForm(\"unknown form\", \"target\")");
    {
        AForm* unknown = someRandomIntern.makeForm("unknown form", "target");
        if (!unknown)
            std::cout << CYAN << "Returned NULL as expected" << RESET << std::endl;
    }

    // ── Test 5: Case-sensitive mismatch ──────────────────────────────────────
    printSeparator("Test 5: makeForm(\"Robotomy Request\", \"R2D2\") — wrong case");
    {
        AForm* wrongCase = someRandomIntern.makeForm("Robotomy Request", "R2D2");
        if (!wrongCase)
            std::cout << CYAN << "Returned NULL as expected" << RESET << std::endl;
    }

    // ── Test 6: Bureaucrat uses intern-created form end to end ────────────────
    printSeparator("Test 6: Full workflow with Bureaucrat");
    {
        Bureaucrat boss("Boss", 1);
        AForm* form = someRandomIntern.makeForm("presidential pardon", "Marvin");
        if (form) {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }

    std::cout << std::endl;
    return 0;
}
