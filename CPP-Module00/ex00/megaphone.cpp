#include <iostream>
#include <cctype>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        char* arg = argv[i];
        for (int j = 0; arg[j] != '\0'; ++j) {
            char upperChar = static_cast<char>(std::toupper(static_cast<unsigned char>(arg[j]))); //convert to upper case
            std::cout << upperChar;
        }
        if (i < argc - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}
