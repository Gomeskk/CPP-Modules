#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <string>

// Function to print test results
void printResult(bool inside, const char* testName){
    std::cout << "  " << testName << ": ";
    if (inside)
        std::cout << GREEN << "INSIDE ✓" << RESET;
    else
        std::cout << RED << "OUTSIDE ✗" << RESET;
    std::cout << std::endl;
}

// Helper function to convert coordinates (outside drawTriangle)
std::pair<int, int> toGridCoord(int size, Fixed fx, Fixed fy){
    int x = fx.toFloat() * (size - 1) / 10;
    int y = size - 1 - (int)(fy.toFloat() * (size - 1) / 10);
    
    // Clamp coordinates to grid bounds
    if (x < 0)
        x = 0;
    else if (x > size - 1)
        x = size - 1;
        
    if (y < 0)
        y = 0;
    else if (y > size - 1)
        y = size - 1;
    
    return std::pair<int, int>(x, y);
}

// Function to draw a visual representation of the triangle and point
void drawTriangle(Point const &a, Point const &b, Point const &c, Point const &p, bool inside){
    std::cout << "\nTriangle Visualization (approximated):" << std::endl;
    
    const int SIZE = 20;
    char grid[SIZE][SIZE];
    
    // Initialize grid with spaces
    for (int y = 0; y < SIZE; y++){
        for (int x = 0; x < SIZE; x++){
            grid[y][x] = ' ';
        }
    }
    
    // Plot triangle vertices
    std::pair<int, int> aCoord = toGridCoord(SIZE, a.getX(), a.getY());
    std::pair<int, int> bCoord = toGridCoord(SIZE, b.getX(), b.getY());
    std::pair<int, int> cCoord = toGridCoord(SIZE, c.getX(), c.getY());
    std::pair<int, int> pCoord = toGridCoord(SIZE, p.getX(), p.getY());
    
    int ax = aCoord.first;
    int ay = aCoord.second;
    int bx = bCoord.first;
    int by = bCoord.second;
    int cx = cCoord.first;
    int cy = cCoord.second;
    int px = pCoord.first;
    int py = pCoord.second;
    
    grid[ay][ax] = 'A';
    grid[by][bx] = 'B';
    grid[cy][cx] = 'C';
    
    if (inside)
        grid[py][px] = 'P';
    else
        grid[py][px] = 'X';
    
    // Draw the grid
    std::cout << "   ";
    for (int x = 0; x < SIZE; x++){
        if (x % 5 == 0)
            std::cout << '+';
        else
            std::cout << '-';
    }
    std::cout << std::endl;
    
    for (int y = 0; y < SIZE; y++){
        if (y % 5 == 0)
            std::cout << " + ";
        else
            std::cout << "   ";
            
        for (int x = 0; x < SIZE; x++){
            char c = grid[y][x];
            if (c == 'A' || c == 'B' || c == 'C')
                std::cout << YELLOW << c << RESET;
            else if (c == 'P')
                std::cout << GREEN << c << RESET;
            else if (c == 'X')
                std::cout << RED << c << RESET;
            else
                std::cout << c;
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[]){
    if (argc > 1){
        std::cerr << RED << "⚠ ERROR: This program does not accept command line arguments" << RESET << std::endl;
        std::cerr << YELLOW << "Usage: " << argv[0] << RESET << std::endl;
        return 1;
    }

    std::cout << BOLD << "\n===== POINT IN TRIANGLE TESTS =====" << RESET << std::endl;

    // Create triangle vertices
    std::cout << BOLD << "\n1. Creating triangle ABC:" << RESET << std::endl;
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);
    std::cout << "  Triangle vertices: A(0,0), B(10,0), C(5,10)" << std::endl;

    float x = 0.0f, y = 0.0f;
    bool validInput = false;
    std::string line;

    while (!validInput){
        std::cout << "  Enter point coordinates x y (or CTRL+D to skip): ";
        
        if (!std::getline(std::cin, line)){
            std::cout << YELLOW << "\n  EOF detected. Skipping interactive test." << RESET << std::endl;
            std::cout << BOLD << "\n5. Objects going out of scope:" << RESET << std::endl;
            return 0;
        }
        
        std::istringstream iss(line);
        
        // Try to extract exactly two numbers
        if (iss >> x >> y){
            // Check if there's any extra input
            std::string extra;
            if (!(iss >> extra)){
                // We got exactly two numbers, success!
                validInput = true;
            } 
            else{
                std::cout << RED << "  Too many inputs! Please enter exactly two numbers." << RESET << std::endl;
            }
        } 
        else{
            std::cout << RED << "  Invalid input! Please enter two numbers separated by space." << RESET << std::endl;
        }
    }
    
    Point userPoint(x, y);
    bool userTest = bsp(a, b, c, userPoint);
    std::cout << "  Point (" << x << "," << y << ") is ";
    if (userTest)
        std::cout << GREEN << "INSIDE" << RESET;
    else
        std::cout << RED << "OUTSIDE" << RESET;
    std::cout << " the triangle" << std::endl;
              
    drawTriangle(a, b, c, userPoint, userTest);

    std::cout << BOLD << "\n5. Objects going out of scope:" << RESET << std::endl;
    return 0;
}