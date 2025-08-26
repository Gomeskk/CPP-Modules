#ifndef FILE_REPLACER_HPP
#define FILE_REPLACER_HPP

#include <string>
#include <fstream>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class FileReplacer {
private:
    std::string filename;
    std::string s1;
    std::string s2;
    std::ifstream inputFile;
    std::ofstream outputFile;
    
    bool openFiles();
    std::string replaceInLine(const std::string& line);

public:
    FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
    ~FileReplacer();
    
    bool replace();
};

#endif