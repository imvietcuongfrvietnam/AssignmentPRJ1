#include <iostream>
#include <stack>
#include <vector>
#include <algorithm> 
#define MAX 200
using namespace std;

int n, m;
enum Color { WHITE, GRAY, BLACK }; 
Color color[MAX]; 
vector<int> edges[MAX]; 

void dfs(int start) {
    stack<int> s;
    s.push(start);
    color[start] = GRAY; 

    while (!s.empty()) {
        int x = s.top();
        s.pop();
        
        if (color[x] == GRAY) {
            cout << x << " "; 
            color[x] = BLACK; // ��nh d?u d?nh n�y l� d� ho�n th�nh
        }

        // Duy?t qua c�c d?nh k? c?a x theo th? t? gi?m d?n d? uu ti�n d?nh nh? tru?c
        for (int i = 0; i < edges[x].size(); i++) {  
            int neighbor = edges[x][i];
            if (color[neighbor] == WHITE) { 
                s.push(neighbor); 
                color[neighbor] = GRAY; // ��nh d?u d?nh k? l� x�m
                break;
            }
        }
    }
    printf("%d", 7);
}

int main() {
    cin >> n >> m;
    int u, v;

    // Kh?i t?o t?t c? c�c d?nh v?i m�u tr?ng
    for (int i = 1; i <= n; i++) {
        color[i] = WHITE;
    }

    // �?c c�c c?nh v� x�y d?ng danh s�ch k?
    for (int i = 0; i < m; i++) {  
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    // S?p x?p c�c d?nh k? d? d?m b?o th? t? tang d?n
    for (int i = 1; i <= n; i++) {
        sort(edges[i].begin(), edges[i].end());
    }

    dfs(1); // B?t d?u DFS t? d?nh 1
    
    cout << endl;  // In ra d�ng m?i sau khi ho�n th�nh DFS
    
    return 0;
}

