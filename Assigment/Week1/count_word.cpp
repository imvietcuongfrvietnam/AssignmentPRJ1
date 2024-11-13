#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string text;
    std::string word;
    int wordCount = 0;

    // Read the whole input text until end-of-file (EOF)
    while (std::getline(std::cin, text)) {
        std::stringstream ss(text);
        // Count words in the current line
        while (ss >> word) {
            ++wordCount;
        }
    }

    // Output the word count
    std::cout << wordCount << std::endl;

    return 0;
}

