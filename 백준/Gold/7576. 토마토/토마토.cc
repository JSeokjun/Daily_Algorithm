#include <iostream>
#include <queue>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    int v[N][M];
    queue<pair<int,int>> q;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> v[i][j];
            if(v[i][j]==1) q.push(make_pair(i,j));
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x<N-1) if(!v[x+1][y]) {
            q.push(make_pair(x+1,y));
            v[x+1][y] = v[x][y]+1;
        }
        if(y<M-1) if(!v[x][y+1]) {
            q.push(make_pair(x,y+1));
            v[x][y+1] = v[x][y]+1;
        }
        if(x>0) if(!v[x-1][y]) {
            q.push(make_pair(x-1,y));
            v[x-1][y] = v[x][y]+1;
        }
        if(y>0) if(!v[x][y-1]) {
            q.push(make_pair(x,y-1));
            v[x][y-1] = v[x][y]+1;
        }
    }

    int max = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(!v[i][j]) {
                cout << -1;
                return 0;
            }
            if(max<v[i][j]) max=v[i][j];
        }
    }
    cout << max-1;
}