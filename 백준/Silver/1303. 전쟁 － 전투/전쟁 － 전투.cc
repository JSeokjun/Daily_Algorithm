#include <iostream>
using namespace std;

int N, M;
int W, B, total_W, total_B;
char bg[100][100];
bool visit[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y) {
    visit[x][y] = 1;
    char now = bg[x][y];
    if(now=='W') W++;
    else B++; 

    for(int i=0; i<4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x>=0 && next_y>=0 && next_x<M && next_y<N && 
        bg[next_x][next_y]==now && !visit[next_x][next_y]) {
            dfs(next_x,next_y);
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin >> bg[i][j];
        }
    }
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(!visit[i][j]) {
                dfs(i,j);
                total_W += W*W;
                total_B += B*B;
                W=0; B=0;
            }
        }
    }

    cout << total_W << ' ' << total_B;

    return 0;
}   