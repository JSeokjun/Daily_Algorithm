#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, R; cin >> N >> M >> R;
    int board[N+1][M+1];
    char state[N+1][M+1];
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> board[i][j];
            state[i][j] = 'S';
        }
    }

    int score = 0;
    while(R--) {
        int X, Y; cin >> X >> Y;
        char D; cin >> D;

        if(D == 'E' && state[X][Y]=='S') {
            int len = board[X][Y];
            state[X][Y] = 'F';
            score++;
            
            for(int i=1; i<len; i++) {
                if(Y+i > M) break;
                if(state[X][Y+i] == 'S') {
                    score++;
                    state[X][Y+i] = 'F';
                    if(len < board[X][Y+i]+i) {
                        len = board[X][Y+i]+i;
                    }
                }
            }
        }
        else if(D == 'W' && state[X][Y]=='S') {
            int len = board[X][Y];
            state[X][Y] = 'F';
            score++;
            
            for(int i=1; i<len; i++) {
                if(Y-i < 1) break;
                if(state[X][Y-i] == 'S') {
                    score++;
                    state[X][Y-i] = 'F';
                    if(len < board[X][Y-i]+i) {
                        len = board[X][Y-i]+i;
                    }
                }
            }
        }
        else if(D == 'S' && state[X][Y]=='S') {
            int len = board[X][Y];
            state[X][Y] = 'F';
            score++;
            
            for(int i=1; i<len; i++) {
                if(X+i > N) break;
                if(state[X+i][Y] == 'S') {
                    score++;
                    state[X+i][Y] = 'F';
                    if(len < board[X+i][Y]+i) {
                        len = board[X+i][Y]+i;
                    }
                }
            }
        }
        else if(D == 'N' && state[X][Y]=='S') {
            int len = board[X][Y];
            state[X][Y] = 'F';
            score++;
            
            for(int i=1; i<len; i++) {
                if(X+i < 1) break;
                if(state[X-i][Y] == 'S') {
                    score++;
                    state[X-i][Y] = 'F';
                    if(len < board[X-i][Y]+i) {
                        len = board[X-i][Y]+i;
                    }
                }
            }
        }
        cin >> X >> Y;
        state[X][Y] = 'S';
    }
    
    cout << score << '\n';
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cout << state[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}