#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    // ---- Constructors & Destructor ----
    Fixed(void);
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &rhs);
    ~Fixed(void);

    // ---- Conversion Methods ----
    float toFloat(void) const;
    int toInt(void) const;

    // ---- Comparison Operators ----
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    // ---- Arithmetic Operators ----
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    // ---- Increment/Decrement Operators ----
    Fixed &operator++(void);        // Pre-increment
    Fixed operator++(int);          // Post-increment
    Fixed &operator--(void);        // Pre-decrement
    Fixed operator--(int);          // Post-decrement

    // ---- Static Member Functions ----
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    // ---- Member Functions ----
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif