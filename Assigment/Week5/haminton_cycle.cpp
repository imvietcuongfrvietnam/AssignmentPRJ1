#include<iostream>
#define MAX 100

using namespace std;

int check[MAX];
int edges[MAX][MAX];

void init(){
    for(int i = 1; i < MAX; i++){
        check[i] = 0;
    }
    for(int j = 1; j < MAX; j++){
        for(int i = 1; i < MAX; i++){
            edges[i][j] = 0;
        }
    }
}

int Try(int start, int number, int vertex, int ed){
    if(ed == number){
        if(edges[vertex][start]) return 1;
        return 0;
    }
    for(int i = 1; i <= number; i++){
        if(edges[vertex][i] && check[i] == 0){
            check[i] = 1;
            if(Try(start, number, i, ed + 1)){
                return 1;
            }
            check[i] = 0;
        }
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    int u, v;
    int k;
    
    while(t--){
        k = 0;
        int n, m;
        cin >> n >> m;
        
        init();
        
        for(int i = 1; i <= m; i++){
            cin >> u >> v;
            edges[u][v] = 1;
            edges[v][u] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            check[i] = 1;
            if(Try(i, n, i, 1)){
                k = 1;
                break;
            }
            check[i] = 0;
        }
        
        cout << k << endl;
    }
    
    return 0;
}

