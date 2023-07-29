#include <iostream>
#include <vector>
using namespace std;

vector<int> g[1001];
bool visited[1001] = {false};

void dfs(int x) {
    visited[x] = true;

    for(int i=0; i<g[x].size(); i++) {
        int y = g[x][i];
        if(!visited[y]) dfs(y);
    }
}

int main() {
    int N, M, u, v, cnt=0;
    cin >> N >> M;

    for(int i=0; i<M; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=N; i++) {
        if(!visited[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt;
}