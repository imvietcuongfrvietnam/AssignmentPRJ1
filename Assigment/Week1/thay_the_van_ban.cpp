#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string source; // The string to replace with
    string rep;    // The word to be replaced
    string line;   // The line of words

    // Read the source string, the word to replace, and the line of words
    getline(cin, source); 
    getline(cin, rep);
    getline(cin, line);
    
    // Create a stringstream to break the line into words
    stringstream ss(line);
    string word;

    // Split the line into words
    while (ss >> word) {
        // If the current word matches the word to be replaced, replace it
        if(word == source) cout << rep << " "; // Replace 'rep' with 'source'
        else cout << word << " "; // Otherwise, print the word as it is
    }
    
    cout << endl; // Optional: Add a newline at the end

    return 0;
}

