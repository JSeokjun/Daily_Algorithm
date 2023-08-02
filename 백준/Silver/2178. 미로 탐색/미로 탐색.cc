#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N, M;
    string str;
    cin >> N >> M;
    cin.ignore();
    int v[N][M];
    queue<pair<int,int>> q;

    for(int i=0; i<N; i++) {
        getline(cin, str);
        for(int j=0; j<M; j++) {
            v[i][j] = str[j]-48;
        }
    }

    int x=0, y=0;
    q.push(make_pair(x, y));
    v[x][y] = 2;

    while(!q.empty()) {
        q.pop();

        if(x!=N-1) if(v[x+1][y]==1) {
            q.push(make_pair(x+1, y));
            v[x+1][y] = v[x][y] + 1;
        }
        if(y!=M-1) if(v[x][y+1]==1) {
            q.push(make_pair(x, y+1));
            v[x][y+1] = v[x][y] + 1;
        }
        if(x!=0) if(v[x-1][y]==1) {
            q.push(make_pair(x-1, y));
            v[x-1][y] = v[x][y] + 1;
        }
        if(y!=0) if(v[x][y-1]==1) {
            q.push(make_pair(x, y-1));
            v[x][y-1] = v[x][y] + 1;
        }

        x = q.front().first;
        y = q.front().second;
        
    }

    cout << v[N-1][M-1] - 1;
}