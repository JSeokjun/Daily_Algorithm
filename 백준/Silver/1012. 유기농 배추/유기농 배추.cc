#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g[50];
bool v[50][50];

void dfs(int x, int y) {
    v[x][y] = false;

    for(int i=0; i<g[x].size(); i++) {
        int z = g[x][i];
        if(v[x][z] && (z==y+1 || z==y-1)) dfs(x, z);
    }
    for(int i=0; i<g[y].size(); i++) {
        int z = g[y][i];
        if(v[z][y] && (z==x+1 || z==x-1)) dfs(z, y);
    }
}

int main() {
    int T, M, N, K, X, Y, cnt;
    cin >> T;
    for(int i=0; i<T; i++) {
        cnt = 0;
        cin >> M >> N >> K;
        for(int j=0; j<M; j++) {
            for(int k=0; k<N; k++) {
                v[j][k] = false;
            }
        }
        for(int j=0; j<50; j++) {
            g[j].clear();
        }
        for(int j=0; j<K; j++) {
            cin >> X >> Y;
            if(X==Y) g[X].push_back(Y);
            else {
                g[X].push_back(Y);
                g[Y].push_back(X);
            }
            v[X][Y] = true;
        }
        for(int j=0; j<50; j++) {
            sort(g[j].begin(), g[j].end());
        }
        for(int j=0; j<M; j++) {
            for(int k=0; k<N; k++) {
                if(v[j][k]) {
                    cnt++;
                    dfs(j, k);
                }
            }
        }
        cout << cnt << '\n';
    }
}