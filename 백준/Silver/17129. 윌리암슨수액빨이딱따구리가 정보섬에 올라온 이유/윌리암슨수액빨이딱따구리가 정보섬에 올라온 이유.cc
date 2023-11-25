#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    int A[n+1][m+1];
    queue<tuple<int,int,int>> Q;
    int x, y;
    int visit[n+1][m+1]{};
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    for(int i=0; i<n; i++) {
        string tmp; cin >> tmp;
        for(int j=0; j<m; j++) {
            if(tmp[j]=='2') {
                x = i; y = j;
            }
            A[i][j] = (int)tmp[j]-'0';
        }
    }

    Q.push({x,y,0});
    visit[x][y]++;

    while(!Q.empty()) {
        x = get<0>(Q.front());
        y = get<1>(Q.front());
        int cnt = get<2>(Q.front());
        Q.pop();

        if(A[x][y]==3 || A[x][y]==4 || A[x][y]==5) {
            cout << "TAK" << '\n' << cnt;
            return 0;
        }

        cnt++;
        
        for(int i=0; i<4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
            if(!visit[next_x][next_y]
            && A[next_x][next_y]!=1
            && next_x>=0 && next_y>=0
            && next_x<n && next_y<m) {
                Q.push({next_x,next_y,cnt});
                visit[next_x][next_y]++;
            }
        }
    }

    cout << "NIE";
    return 0;
}   