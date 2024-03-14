#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define BIGNUM 1000000000
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M; cin >> N >> M;
    bool map[N][M], visit[N][M][2];
    queue<tuple<int,int,int,bool>> Q;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int min = BIGNUM;
    
    string tmp;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        for(int j=0; j<M; j++) {
            map[i][j] = tmp[j]-48;
            visit[i][j][0] = 0;
            visit[i][j][1] = 0;
        }
    }
    
    Q.push({0, 0, 1, 0});
    visit[0][0][0] = 1;
    visit[0][0][1] = 1;


    while(!Q.empty()) {
        int x = get<0>(Q.front());
        int y = get<1>(Q.front());
        int d = get<2>(Q.front());
        bool b = get<3>(Q.front());

        if(x==N-1 && y==M-1 && min > d) min = d; 

        Q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny>=0 && nx<N && ny<M) {
                if(map[nx][ny]) {
                    if(!b) {
                        Q.push({nx, ny, d+1, 1});
                        visit[nx][ny][1] = 1;
                    }
                }
                else if(!visit[nx][ny][b]) {
                    Q.push({nx, ny, d+1, b});
                    visit[nx][ny][b] = 1;
                }
            }
        }

    }
    if(min == BIGNUM) cout << -1;
    else cout << min;

    return 0;
}