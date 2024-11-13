#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    sort(input.begin(), input.end());
    
    int cnt = 0;
    int start = 0;
    int end = n - 1;
    
    while (start < end) {
        int sum = input[start] + input[end];
        
        if (sum == m) {
            cnt++;
            start++;
            end--;
        } else if (sum < m) {
            start++;
        } else {
            end--;
        }
    }

    cout << cnt << endl;
    return 0;
}

