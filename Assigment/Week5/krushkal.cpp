#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int findSet(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = findSet(parent[u], parent);
    }
    return parent[u];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findSet(u, parent);
    v = findSet(v, parent);
    if (u != v) {
        if (rank[u] < rank[v]) {
            swap(u, v);
        }
        parent[v] = u;
        if (rank[u] == rank[v]) {
            rank[u]++;
        }
    }
}

long long kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    vector<int> parent(V + 1);
    vector<int> rank(V + 1, 0);
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    long long mst_weight = 0;
    int edges_used = 0;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        
        if (findSet(u, parent) != findSet(v, parent)) {
            mst_weight += weight;
            unionSets(u, v, parent, rank);
            edges_used++;
            if (edges_used == V - 1) {
                break;
            }
        }
    }

    if (edges_used < V - 1) {
        return -1; // Không th? t?o cây khung nh? nh?t (d? th? không liên thông)
    }
    return mst_weight;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    long long mst_weight = kruskal(N, edges);

    if (mst_weight == -1) {
        cout << "No MST exists" << endl;
    } else {
        cout << mst_weight << endl;
    }

    return 0;
}

