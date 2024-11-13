#include <iostream>
#include <stack>

using namespace std;

int main() {
    char c;
    stack<char> res;
    int flags = 1;
    
    while (cin >> c) {
        if (c == '(' || c == '[' || c == '{') {
            res.push(c);
        } else {
            if (res.empty()) {
                flags = 0;
                break;
            }
            char x = res.top();
            res.pop();
            if ((x == '{' && c != '}') || (x == '(' && c != ')') || (x == '[' && c != ']')) {
                flags = 0;
                break;
            }
        }
    }

    if (!res.empty()) flags = 0;

    cout << flags;
    return 0;
}

