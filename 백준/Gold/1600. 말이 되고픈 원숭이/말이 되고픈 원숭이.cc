#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int K, W, H; cin >> K >> W >> H;
    bool G[H][W], V[H][W][31];
    queue<tuple<int,int,int,int>> Q;
    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            for(int k=0; k<31; k++) {
                V[i][j][k] = 0;
            }
            cin >> G[i][j];
        }
    }

    Q.push({0, 0, 0, 0});
    V[0][0][0] = 1;

    while(!Q.empty()) {
        int x = get<0>(Q.front());
        int y = get<1>(Q.front());
        int c = get<2>(Q.front());
        int k = get<3>(Q.front());
        
        Q.pop();

        if(x==H-1 && y==W-1) {
            cout << c;
            return 0;
        }

            if(x>0 && !G[x-1][y] && !V[x-1][y][k]) {
                Q.push({x-1, y, c+1, k});
                V[x-1][y][k] = 1;
            }

            if(k+1 <= K) {
                for(int i=0; i<8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx>=0 && nx<H && ny>=0 && ny<W && !G[nx][ny] && !V[nx][ny][k+1]) {
                        Q.push({nx, ny, c+1, k+1});
                        V[nx][ny][k+1] = 1;
                    }
                }
            }    

            if(y>0 && !G[x][y-1] && !V[x][y-1][k]) {
                Q.push({x, y-1, c+1, k});
                V[x][y-1][k] = 1;
            }

            if(k+1 <= K) {
                for(int i=0; i<8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx>=0 && nx<H && ny>=0 && ny<W && !G[nx][ny] && !V[nx][ny][k+1]) {
                        Q.push({nx, ny, c+1, k+1});
                        V[nx][ny][k+1] = 1;
                    }
                }
            }   
        
            
            if(x<H-1 && !G[x+1][y] && !V[x+1][y][k]) {
                if(x==0 && y==9) cout << '?' << '\n';
                Q.push({x+1, y, c+1, k});
                V[x+1][y][k] = 1;
            }

            if(k+1 <= K) {
                for(int i=0; i<8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx>=0 && nx<H && ny>=0 && ny<W && !G[nx][ny] && !V[nx][ny][k+1]) {
                        Q.push({nx, ny, c+1, k+1});
                        V[nx][ny][k+1] = 1;
                    }
                }
            }     

            if(y<W-1 && !G[x][y+1] && !V[x][y+1][k]) {
                Q.push({x, y+1, c+1, k});
                V[x][y+1][k] = 1;
            }

            if(k+1 <= K) {
                for(int i=0; i<8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx>=0 && nx<H && ny>=0 && ny<W && !G[nx][ny] && !V[nx][ny][k+1]) {
                        Q.push({nx, ny, c+1, k+1});
                        V[nx][ny][k+1] = 1;
                    }
                }
            }     
    }

    cout << -1;

    return 0;
}