#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    unordered_set<string> database; // C?u trúc d? li?u d? luu tr? các khóa
    string key;

    // Ð?c các khóa vào database
    while (true) {
        getline(cin, key);
        if (key == "*") break; // K?t thúc khi g?p d?u '*'
        database.insert(key); // Chèn khóa vào database
    }

    // Ð?c các hành d?ng và x? lý
    string command;
    while (true) {
        getline(cin, key);
        if (key == "***") break; // K?t thúc khi g?p d?u '***'
        
        // Tách command và key
        size_t pos = key.find(' ');
        command = key.substr(0, pos);
        string k = key.substr(pos + 1);

        if (command == "find") {
            // Th?c hi?n tìm ki?m
            cout << (database.count(k) > 0 ? 1 : 0) << endl;
        } else if (command == "insert") {
            // Th?c hi?n chèn
            auto result = database.insert(k);
            cout << (result.second ? 1 : 0) << endl; // K?t qu? chèn
        }
    }

    return 0;
}

