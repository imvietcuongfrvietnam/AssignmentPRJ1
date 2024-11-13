#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    // Check if the length of the string is exactly 8
    if(s.length() != 8) {
        printf("INCORRECT");
        return 0;
    }
    
    // Check if the format is hh:mm:ss (colon at correct positions)
    if(s[2] != ':' || s[5] != ':') {
        printf("INCORRECT");
        return 0;
    }
    
    // Extract hours, minutes, and seconds from the string
    int hours = (s[0] - '0') * 10 + (s[1] - '0');
    int minutes = (s[3] - '0') * 10 + (s[4] - '0');
    int seconds = (s[6] - '0') * 10 + (s[7] - '0');
    
    // Validate hours, minutes, and seconds range
    if(hours >= 24 || minutes >= 60 || seconds >= 60) {
        printf("INCORRECT");
        return 0;
    }
    
    // Calculate the total seconds
    long count = hours * 3600 + minutes * 60 + seconds;
    
    // Output the result
    printf("%ld", count); // %ld is used for long integers in printf
    
    return 0;
}

