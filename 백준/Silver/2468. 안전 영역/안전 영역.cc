#include <iostream>
#include <string.h>
using namespace std;

int N, H;
int cnt, max_area, max_height;
int ground[100][100];
bool visit[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y) {
    visit[x][y] = 1;

    for(int i=0; i<4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x>=0 && next_y>=0 && next_x<N && next_y<N && 
        ground[next_x][next_y]>H && !visit[next_x][next_y]) {
            dfs(next_x,next_y);
        }
    }
}

int main() {
    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int tmp; cin >> tmp;
            ground[i][j] = tmp;
            if(max_height < tmp) max_height = tmp;
        }
    }
    for(; H<max_height; H++) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(!visit[i][j] && ground[i][j]>H) {
                    dfs(i,j);
                    cnt++;
                }
            }
        }

        if(max_area<cnt) max_area = cnt;
        cnt = 0;
        memset(visit, 0, sizeof(visit));
    }
    
    cout << max_area;

    return 0;
}   