#include <iostream>
using namespace std;

int v[100][100];
int v2[100][100];

void dfs(int x, int y) {
    int color = v[x][y];
    v[x][y] = 0;

    if(x<99) if(v[x+1][y] && color==v[x+1][y]) dfs(x+1, y);
    if(y<99) if(v[x][y+1] && color==v[x][y+1]) dfs(x, y+1);
    if(x>0) if(v[x-1][y] && color==v[x-1][y]) dfs(x-1, y);
    if(y>0) if(v[x][y-1] && color==v[x][y-1]) dfs(x, y-1); 
}
void dfs2(int x, int y) {
    int color = v2[x][y];
    v2[x][y] = 0;

    if(x<99) if(v2[x+1][y] && color==v2[x+1][y]) dfs2(x+1, y);
    if(y<99) if(v2[x][y+1] && color==v2[x][y+1]) dfs2(x, y+1);
    if(x>0) if(v2[x-1][y] && color==v2[x-1][y]) dfs2(x-1, y);
    if(y>0) if(v2[x][y-1] && color==v2[x][y-1]) dfs2(x, y-1); 
}

int main() {
    int N, cnt=0;
    cin >> N;

    char chr;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> chr;
            if(chr=='R') v[i][j] = 1;
            else if(chr=='G') v[i][j] = 2;
            else if(chr=='B') v[i][j] = 3;
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(v[i][j]==1) v2[i][j] = 2;
            else if(v[i][j]==2) v2[i][j] = 2;
            else if(v[i][j]==3) v2[i][j] = 3;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(v[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << ' ';
    cnt = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(v2[i][j]) {
                cnt++;
                dfs2(i, j);
            }
        }
    }
    cout << cnt;    
}