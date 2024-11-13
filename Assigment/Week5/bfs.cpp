#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> 
#define MAX 200
using namespace std;

enum Color { WHITE, GRAY, BLACK };
Color color[MAX]; 
vector<int> edges[MAX];

void bfs(int start) {
	queue<int> bqueue;
	bqueue.push(start);
	if(color[start] == WHITE){
	color[start] = GRAY;
}	else return;
	while (!bqueue.empty()) {
		int x = bqueue.front();
		bqueue.pop();
		cout << x << " ";
		color[x] = BLACK;

		for (int i = 0; i < edges[x].size(); i++) {
			int neighbor = edges[x][i];
			if (color[neighbor] == WHITE) {
				bqueue.push(neighbor);
				color[neighbor] = GRAY;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int u, v;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		color[i] = WHITE;
	}
	for (int i = 1; i <= n; i++) {
        sort(edges[i].begin(), edges[i].end());
    }
    for(int i = 1;i<=n;i++){
	bfs(i);
}
	return 0;
}

