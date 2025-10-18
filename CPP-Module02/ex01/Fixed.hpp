#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

// ANSI color codes for pretty output
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"

class Fixed
{
private:
    int _fixedPointValue;                 // The raw fixed-point value
    static const int _fractionalBits = 8;  // Number of bits for the fractional part

public:
    Fixed(void);                          // Default constructor
    Fixed(const Fixed &src);              // Copy constructor
    Fixed &operator=(const Fixed &rhs);   // Copy assignment operator
    ~Fixed(void);                         // Destructor

    // ---- New Constructors ----
    Fixed(const int value);
    Fixed(const float value);

    // ---- Conversion Methods ----
    float toFloat(void) const;
    int toInt(void) const;

    // ---- Member functions ----
    int getRawBits(void) const;           // Returns the raw value
    void setRawBits(int const raw);       // Sets the raw value
};

// ---- Stream Overload ----
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif