#include <iostream>
#include <string>
#include <sstream>
#include<ctype.h>
int main() {
    std::string text;
    std::string word;
    int wordCount = 0;

    // Read the whole input text until end-of-file (EOF)
    while (std::getline(std::cin, text)) {
        for(int i = 0;i<text.length();i++){
        	if(text[i]>='a' && text[i]<='z'){
        		text[i] = toupper(text[i]);
			}
		
		}
		std::cout<<text<<std::endl;
        }
        

    return 0;
}

