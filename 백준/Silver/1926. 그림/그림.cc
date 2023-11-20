#include <iostream>
using namespace std;

int N, M;
int cnt, total_cnt, max_area;
bool paper[500][500];
bool visit[500][500];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y) {
    visit[x][y] = 1;
    bool now = paper[x][y];
    if(now) cnt++;

    for(int i=0; i<4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x>=0 && next_y>=0 && next_x<N && next_y<M && 
        paper[next_x][next_y] && !visit[next_x][next_y]) {
            dfs(next_x,next_y);
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> paper[i][j];
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(!visit[i][j] && paper[i][j]) {
                dfs(i,j);
                if(cnt > max_area) max_area = cnt;
                total_cnt++;
                cnt = 0;
            }
        }
    }

    cout << total_cnt << '\n' << max_area;

    return 0;
}   