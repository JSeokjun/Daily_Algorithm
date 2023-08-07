#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int v[n][m], x, y;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> v[i][j];
            if(v[i][j]==2) {
                x = i;
                y = j;
            } 
        }
    }

    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        int dstnc = v[x][y];
        q.pop();

        if(x!=n-1) if(v[x+1][y]==1) {
            q.push(make_pair(x+1,y));
            v[x+1][y] = dstnc+1;
        }
        if(y!=m-1) if(v[x][y+1]==1) {
            q.push(make_pair(x,y+1));
            v[x][y+1] = dstnc+1;
        }
        if(x!=0) if(v[x-1][y]==1) {
            q.push(make_pair(x-1,y));
            v[x-1][y] = dstnc+1;
        }
        if(y!=0) if(v[x][y-1]==1) {
            q.push(make_pair(x,y-1));
            v[x][y-1] = dstnc+1;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(v[i][j]==0) cout << 0 << ' ';
            else if(v[i][j]==1) cout << -1 << ' ';
            else cout << v[i][j]-2 << ' ';
        }
        cout << '\n';
    }
}