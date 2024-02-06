#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M, K; cin >> N >> M >> K;
    int tmp_M = M, tmp_K = K;
    int board[N][N];
    queue<pair<int,int>> Q;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }

    if(!M) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!board[i][j]) {
                Q.push({i, j});
                board[i][j] = 1;
                if(K != 1) {
                    M--;
                    tmp_K = K;
                }

                while(!Q.empty()) {
                    int x = Q.front().first;
                    int y = Q.front().second;

                    Q.pop();
                    if(K == 1) M--;
                    else if(!tmp_K--) {
                        M--;
                        tmp_K = K;
                    }
                    if(!M) break;
 
                    if(x > 0 && !board[x-1][y]) {
                        board[x-1][y] = 1;
                        Q.push({x-1, y});
                    }
                    if(y > 0 && !board[x][y-1]) {
                        board[x][y-1] = 1;
                        Q.push({x, y-1});
                    }
                    if(x < N-1 && !board[x+1][y]) {
                        board[x+1][y] = 1;
                        Q.push({x+1, y});
                    }
                    if(y < N-1 && !board[x][y+1]) {
                        board[x][y+1] = 1;
                        Q.push({x, y+1});
                    }
                }
            }
            if(!M) break;
        }
        if(!M) break;
    }

    if(tmp_M == M) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(!board[i][j]) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    cout << "POSSIBLE" << '\n' << M;
    return 0;
}   