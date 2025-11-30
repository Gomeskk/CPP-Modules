#include "Point.hpp"

/* 
 * Area calculation function
 * Uses the formula: Area = 1/2 * |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)|
 */
static Fixed calculateArea(Point const &p1, Point const &p2, Point const &p3){
    Fixed area = ((p1.getX() * (p2.getY() - p3.getY())) +
                  (p2.getX() * (p3.getY() - p1.getY())) +
                  (p3.getX() * (p1.getY() - p2.getY()))) / 2;
                  
    // Take absolute value of the area
    if (area < 0)
        return area * -1;
    else
        return area;
}

/*
 * BSP - Binary Space Partitioning
 * Determines if a point is inside a triangle using the area method
 * 
 * If the point is inside the triangle, then:
 * - The sum of the areas of three triangles formed by the point and each pair of 
 *   vertices should equal the area of the original triangle
 * - If the point is on an edge or vertex, at least one of those areas will be 0
 */
bool bsp(Point const &a, Point const &b, Point const &c, Point const &point){
    std::cout << MAGENTA << "⚙ BSP function called" << RESET << std::endl;
    
    // Calculate the area of the original triangle
    Fixed areaOriginal = calculateArea(a, b, c);
    
    // Calculate areas of triangles formed by the point and each pair of vertices
    Fixed area1 = calculateArea(point, a, b);
    Fixed area2 = calculateArea(point, b, c);
    Fixed area3 = calculateArea(point, c, a);
    
    // Check if any of the areas are zero (meaning point is on edge or vertex)
    if (area1 == 0 || area2 == 0 || area3 == 0){
        return false;
    }
    
    // Check if the sum of the three areas equals the original area
    // with a small epsilon for floating-point precision issues
    Fixed totalArea = area1 + area2 + area3;
    
    return (totalArea == areaOriginal);
}