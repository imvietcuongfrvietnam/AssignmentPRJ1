#include <stdio.h>
#include <limits.h>
#include <stack>

using namespace std;

void calDistanceMin(int u, int n, unsigned int distance[][101], int res[][101]) {
    // Kh?i t?o m?ng kho?ng c�ch cho t?ng d?nh
    int d[n + 1];
    bool check[n + 1] = {0};
    
    for (int i = 1; i <= n; i++) {
        d[i] = INT_MAX;
    }
    d[u] = 0;
    
    for (int count = 1; count <= n; count++) {
        int minDist = INT_MAX, ver = -1;
        
        // T�m d?nh v?i kho?ng c�ch ng?n nh?t
        for (int v = 1; v <= n; v++) {
            if (!check[v] && d[v] < minDist) {
                minDist = d[v];
                ver = v;
            }
        }
        
        if (ver == -1) break;  // Kh�ng c� du?ng di
        check[ver] = true;
        
        // C?p nh?t kho?ng c�ch d?n c�c d?nh k?
        for (int v = 1; v <= n; v++) {
            if (distance[ver][v] != INT_MAX && d[ver] != INT_MAX && d[ver] + distance[ver][v] < d[v]) {
                d[v] = d[ver] + distance[ver][v];
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (d[i] == INT_MAX)
            res[u][i] = -1;
        else
            res[u][i] = d[i];
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    unsigned int distance[101][101];
    int res[101][101];
    
    // Kh?i t?o kho?ng c�ch ban d?u
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            distance[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
    
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        distance[u][v] = w;
    }
    
    for (int i = 1; i <= n; i++) {
        calDistanceMin(i, n, distance, res);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
                printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

