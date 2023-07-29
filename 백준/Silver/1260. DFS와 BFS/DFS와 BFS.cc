#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> g[1001];
queue<int> q;
bool v[1001];

void dfs(int x) {
    v[x] = true;
    cout << x << ' ';

    for(int i=0; i<g[x].size(); i++) {
        int y = g[x][i];
        if(!v[y]) dfs(y);
    }
}

void bfs(int x) {
    q.push(x);
    v[x] = true;
    cout << x << ' ';

    while(!q.empty()) {
        q.pop();
        for(int i=0; i<g[x].size(); i++) {
            int y = g[x][i];
            if(!v[y]) {
                q.push(y);
                v[y] = true;
                cout << y << ' ';
            }
        }
        x = q.front();
    }
}

int main() {
    int N, M, V, a, b;    
    cin >> N >> M >> V;

    for(int i=0; i<M; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1; i<=N; i++) {
        sort(g[i].begin(), g[i].end());
    }

    dfs(V);

    for(int i=1; i<=N; i++) {
        v[i] = false;
    }
    cout << '\n';

    bfs(V);
}