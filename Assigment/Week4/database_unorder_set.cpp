#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    unordered_set<string> database; // C?u tr�c d? li?u d? luu tr? c�c kh�a
    string key;

    // �?c c�c kh�a v�o database
    while (true) {
        getline(cin, key);
        if (key == "*") break; // K?t th�c khi g?p d?u '*'
        database.insert(key); // Ch�n kh�a v�o database
    }

    // �?c c�c h�nh d?ng v� x? l�
    string command;
    while (true) {
        getline(cin, key);
        if (key == "***") break; // K?t th�c khi g?p d?u '***'
        
        // T�ch command v� key
        size_t pos = key.find(' ');
        command = key.substr(0, pos);
        string k = key.substr(pos + 1);

        if (command == "find") {
            // Th?c hi?n t�m ki?m
            cout << (database.count(k) > 0 ? 1 : 0) << endl;
        } else if (command == "insert") {
            // Th?c hi?n ch�n
            auto result = database.insert(k);
            cout << (result.second ? 1 : 0) << endl; // K?t qu? ch�n
        }
    }

    return 0;
}

