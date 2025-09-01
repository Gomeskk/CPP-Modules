 #include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {
    std::cout << BLUE << "FileReplacer created for " << filename << RESET << std::endl;
}

FileReplacer::~FileReplacer() {
    if (inputFile.is_open())
        inputFile.close();
    if (outputFile.is_open())
        outputFile.close();
    std::cout << BLUE << "FileReplacer destroyed" << RESET << std::endl;
}

bool FileReplacer::openFiles() {
    inputFile.open(filename.c_str()); // open input file
    if (!inputFile.is_open()) {
        std::cerr << RED << "Error: Cannot open input file " << filename << RESET << std::endl;
        return false;
    }
    
    std::string outputFilename = filename + ".replace";
    outputFile.open(outputFilename.c_str()); // open output file
    if (!outputFile.is_open()) {
        std::cerr << RED << "Error: Cannot create output file " << outputFilename << RESET << std::endl;
        inputFile.close();
        return false;
    }
    
    return true;
}

std::string FileReplacer::replaceInLine(const std::string& line) {
    if (s1.empty())
        return line;
        
    std::string result;
    size_t startPos = 0;
    size_t foundPos;
    
    // find all occurrences of s1 in the line
    while ((foundPos = line.find(s1, startPos)) != std::string::npos) {
        result += line.substr(startPos, foundPos - startPos); // add the part before the found string
        result += s2; // add the replacement string
        startPos = foundPos + s1.length(); // move past the found string
    }
    result += line.substr(startPos); // add the rest of the line
    return result;
}

bool FileReplacer::replace() {
    if (!openFiles())
        return false;
    
    std::string line;
    size_t lineCount = 0;
    size_t replacementCount = 0;
    
    std::cout << YELLOW << "Replacing all occurrences of '" << s1 << "' with '" << s2 << "' in " << filename << RESET << std::endl;
    while (std::getline(inputFile, line)) {
        lineCount++;
        
        // count occurrences in this line
        size_t count = 0;
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            count++;
            pos += s1.length();
        }
        replacementCount += count;
        
        // replace occurrences and write to output file
        std::string modifiedLine = replaceInLine(line);
        outputFile << modifiedLine;
        
        // add newline if not at the end of file
        if (!inputFile.eof())
            outputFile << std::endl;
    }
    
    std::cout << GREEN << "Replacement complete: " << replacementCount << " occurrences replaced in " << lineCount << " lines" << RESET << std::endl;
    inputFile.close();
    outputFile.close();
    
    return true;
}