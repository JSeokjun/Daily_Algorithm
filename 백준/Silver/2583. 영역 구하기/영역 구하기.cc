#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool paper[100][100];
int M, N, K, cnt;
vector<int> V;

void dfs(int x, int y) {
    paper[x][y] = 1;
    cnt++;

    if(x>0 && !paper[x-1][y]) dfs(x-1, y);
    if(y>0 && !paper[x][y-1]) dfs(x, y-1);
    if(x<M-1 && !paper[x+1][y]) dfs(x+1, y);
    if(y<N-1 && !paper[x][y+1]) dfs(x, y+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> M >> N >> K;

    while(K--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for(int i=y1; i<y2; i++) {
            for(int j=x1; j<x2; j++) {
                paper[i][j] = 1;
            }
        }
    }

    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(!paper[i][j]) {
                dfs(i, j);
                V.push_back(cnt);
                cnt = 0;
            }
        }
    }

    cout << V.size() << '\n';
    
    sort(V.begin(), V.end());
    for(int i=0; i<V.size(); i++) {
        cout << V[i] << ' ';
    }
    
    return 0;
}