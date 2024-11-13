#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int calDistanceMin(int u, int v, int n, vector<vector<pii>>& adj) {
    vector<int> d(n + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    d[u] = 0;
    pq.push({0, u});
    
    while (!pq.empty()) {
        int dist = pq.top().first;
        int ver = pq.top().second;
        pq.pop();

        if (ver == v) return d[v];  // Ðã tìm th?y kho?ng cách d?n d?nh dích

        for (auto &edge : adj[ver]) {
            int next = edge.first;
            int weight = edge.second;

            if (d[ver] != INT_MAX && d[ver] + weight < d[next]) {
                d[next] = d[ver] + weight;
                pq.push({d[next], next});
            }
        }
    }
    
    return d[v] == INT_MAX ? -1 : d[v];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<pii>> adj(n + 1);

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
    }

    int start, end;
    scanf("%d %d", &start, &end);
    int result = calDistanceMin(start, end, n, adj);

    printf("%d\n", result);

    return 0;
}

