#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main() {
    queue<int> q;
    string get;
    int x;

    while (cin >> get) {
        if (get == "PUSH") {
            cin >> x;
            q.push(x);
        }
        else if (get == "POP") {
            if (!q.empty()) {
                // Lấy giá trị phần tử đầu tiên
                cout << q.front() << endl;
                // Xóa phần tử đầu tiên
                q.pop();
            } else {
                cout << "NULL\n";
            }
        }
        else {
            break;
        }
    }

    return 0;
}
