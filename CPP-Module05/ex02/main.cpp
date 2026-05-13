#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void printSeparator(const std::string& title) {
    std::cout << std::endl;
    std::cout << BOLD << MAGENTA << "═══════════════════════════════════════════════" << RESET << std::endl;
    std::cout << BOLD << YELLOW  << "  " << title << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "═══════════════════════════════════════════════" << RESET << std::endl;
}

int main() {

    // ── Test 1: Execute without signing ───────────────────────────────────────
    printSeparator("Test 1: Execute unsigned form");
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("garden");
        boss.executeForm(shrub);
    }

    // ── Test 2: ShrubberyCreationForm — happy path ────────────────────────────
    printSeparator("Test 2: ShrubberyCreationForm success");
    {
        Bureaucrat gardener("Gardener", 137);
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        gardener.signForm(shrub);
        gardener.executeForm(shrub);
    }

    // ── Test 3: ShrubberyCreationForm — grade too low to execute ──────────────
    printSeparator("Test 3: ShrubberyCreationForm exec grade too low");
    {
        Bureaucrat signer("Signer", 145);
        Bureaucrat runner("Runner", 138);
        ShrubberyCreationForm shrub("park");
        signer.signForm(shrub);
        runner.executeForm(shrub);   // needs 137, has 138 → fail
    }

    // ── Test 4: RobotomyRequestForm — happy path ──────────────────────────────
    printSeparator("Test 4: RobotomyRequestForm success");
    {
        Bureaucrat scientist("Scientist", 45);
        RobotomyRequestForm robot("Bender");
        scientist.signForm(robot);
        scientist.executeForm(robot);
        scientist.executeForm(robot); // run twice to show 50% randomness
        scientist.executeForm(robot);
        scientist.executeForm(robot);
    }

    // ── Test 5: RobotomyRequestForm — grade too low to sign ───────────────────
    printSeparator("Test 5: RobotomyRequestForm sign grade too low");
    {
        Bureaucrat intern("Intern", 73);
        RobotomyRequestForm robot("R2D2");
        intern.signForm(robot);        // needs 72, has 73 → fail
        intern.executeForm(robot);
    }

    // ── Test 6: PresidentialPardonForm — happy path ───────────────────────────
    printSeparator("Test 6: PresidentialPardonForm success");
    {
        Bureaucrat president("Zaphod", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }

    // ── Test 7: PresidentialPardonForm — exec grade too low ───────────────────
    printSeparator("Test 7: PresidentialPardonForm exec grade too low");
    {
        Bureaucrat signer("Signer", 25);
        Bureaucrat lowExec("LowExec", 6);
        PresidentialPardonForm pardon("Ford Prefect");
        signer.signForm(pardon);
        lowExec.executeForm(pardon);   // needs 5, has 6 → fail
    }

    // ── Test 8: Polymorphism via AForm pointer ────────────────────────────────
    printSeparator("Test 8: Polymorphism via AForm*");
    {
        Bureaucrat overlord("Overlord", 1);
        AForm* forms[3];
        forms[0] = new ShrubberyCreationForm("forest");
        forms[1] = new RobotomyRequestForm("Marvin");
        forms[2] = new PresidentialPardonForm("Trillian");
        for (int i = 0; i < 3; i++) {
            overlord.signForm(*forms[i]);
            overlord.executeForm(*forms[i]);
        }
        for (int i = 0; i < 3; i++)
            delete forms[i];
    }

    std::cout << std::endl;
    return 0;
}
