#include "FileReplacer.hpp"

int main(int argc, char* argv[]) {
    std::cout << BOLD << CYAN << "===== SED IS FOR LOSERS PROGRAM =====" << RESET << std::endl;
    std::cout << "This program replaces strings in a file (like sed)" << std::endl << std::endl;
    
    if (argc != 4) {
        std::cerr << RED << "Error: Wrong number of arguments" << RESET << std::endl;
        std::cout << YELLOW << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement>" << RESET << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    if (filename.empty()) {
        std::cerr << RED << "Error: Empty filename" << RESET << std::endl;
        return 1;
    }
    
    if (s1.empty()) {
        std::cerr << RED << "Error: Empty string to replace" << RESET << std::endl;
        return 1;
    }
    
    std::cout << BOLD << GREEN << "----- File Replacement Parameters -----" << RESET << std::endl;
    std::cout << "Input file: " << CYAN << filename << RESET << std::endl;
    std::cout << "String to replace: " << MAGENTA << s1 << RESET << std::endl;
    std::cout << "Replacement string: " << MAGENTA << s2 << RESET << std::endl << std::endl;
    
    // create FileReplacer object and perform the replacement
    FileReplacer replacer(filename, s1, s2);
    bool success = replacer.replace();
    
    if (success) {
        std::cout << std::endl << BOLD << GREEN << "File successfully processed. Output written to " << filename << ".replace" << RESET << std::endl;
        return 0;
    } 
    else {
        std::cerr << std::endl << BOLD << RED << "Error occurred during file processing" << RESET << std::endl;
        return 1;
    }
}