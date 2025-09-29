#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <climits>

// ANSI color codes for pretty output
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BLUE    "\033[34m"

/*
 * Fixed Class
 * -----------
 * A fixed-point number representation class
 * 
 * Fixed-point numbers store values as integers but with an implied 
 * decimal point. This allows for fractional values with consistent 
 * precision without the performance overhead of floating-point.
 * 
 * In our implementation:
 * - We use an integer to store the raw value
 * - We reserve 8 bits for the fractional part
 * - The binary point is implied to be between bits 7 and 8
 * 
 * Example: 
 * 00000001.00000000 = 1.0 in fixed point (256 in raw value)
 * 00000000.10000000 = 0.5 in fixed point (128 in raw value)
 */

class Fixed
{
private:
    int _fixedPointValue;                 // The raw fixed-point value
    static const int _fractionalBits = 8;  // Number of bits for the fractional part

public:
    // ---- Orthodox Canonical Form ----
    Fixed(void);                          // Default constructor
    Fixed(const Fixed &src);              // Copy constructor
    Fixed &operator=(const Fixed &rhs);   // Copy assignment operator
    ~Fixed(void);                         // Destructor

    // ---- Member functions ----
    int getRawBits(void) const;           // Returns the raw value
    void setRawBits(int const raw);       // Sets the raw value
};

#endif