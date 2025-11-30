#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed _x;  // x-coordinate
    const Fixed _y;  // y-coordinate

public:
    // ---- Constructors & Destructor ----
    Point(void);                         // Default constructor
    Point(const float x, const float y); // Float constructor
    Point(const Point &src);             // Copy constructor
    Point &operator=(const Point &rhs);  // Copy assignment operator
    ~Point(void);                        // Destructor
    
    // ---- Getters ----
    Fixed getX(void) const;
    Fixed getY(void) const;
};

// ---- BSP Function Declaration ----
bool bsp(Point const &a, Point const &b, Point const &c, Point const &point);

#endif