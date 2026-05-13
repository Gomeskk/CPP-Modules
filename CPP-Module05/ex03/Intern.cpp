#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ── Constructors / Destructor ──────────────────────────────────────────────────
// The Intern has no name, grade, or state, so there is nothing to initialise.
// The OCF is still required by the subject.

Intern::Intern() {
    std::cout << GREEN << "✓ Intern default constructor called" << RESET << std::endl;
}

// Nothing to copy — Intern has no member variables.
Intern::Intern(const Intern&) {
    std::cout << BLUE << "⎘ Intern copy constructor called" << RESET << std::endl;
}

// Nothing to assign — return *this to satisfy the operator contract.
Intern& Intern::operator=(const Intern&) {
    std::cout << YELLOW << "⟵ Intern copy assignment operator called" << RESET << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << RED << "✗ Intern destructor called" << RESET << std::endl;
}

// ── Factory helpers ────────────────────────────────────────────────────────────
// Each function allocates one concrete form on the heap and returns it as AForm*.
// They all share the same signature so they can be stored as function pointers
// in the lookup table below.

static AForm* makeShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* makePardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// ── makeForm — lookup table, no if/else chain ─────────────────────────────────
// The subject explicitly forbids long if/else chains. Instead we use a table:
//   - FormEntry pairs a form name (string) with a factory function pointer.
//   - We loop once through the table comparing names.
//   - On a match we call the factory, which allocates the right subclass and
//     returns it as an AForm* (polymorphism).
//   - If no match is found we print an error and return NULL.
//
// Adding a new form type only requires adding ONE line to the table — the
// loop logic never needs to change.

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    // A local struct that pairs a name string with a factory function pointer.
    struct FormEntry {
        const std::string   name;
        AForm*              (*create)(const std::string&); // function pointer type: AForm*(string)
    };

    // The lookup table — static so it is built once and lives for the program's lifetime.
    static const FormEntry table[] = {
        { "shrubbery creation",    makeShrubbery },
        { "robotomy request",      makeRobotomy  },
        { "presidential pardon",   makePardon    }
    };

    // Compute the number of entries at compile time (avoids a magic number).
    static const std::size_t tableSize = sizeof(table) / sizeof(table[0]);

    // Linear search: compare the requested name against each entry.
    for (std::size_t i = 0; i < tableSize; i++) {
        if (table[i].name == formName) {
            std::cout << GREEN << "Intern creates " << formName << RESET << std::endl;
            // Call the matching factory — it allocates the concrete form and
            // returns it as AForm*. The caller is responsible for deleting it.
            return table[i].create(target);
        }
    }

    // No match found — print an error and return NULL so the caller can check.
    std::cout << RED << "Intern error: unknown form '" << formName << "'" << RESET << std::endl;
    return NULL;
}
