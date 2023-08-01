#include <iostream>
using namespace std;

bool v[50][50];

void dfs(int x, int y) {
    v[x][y] = false;
    
    if(x!=49 && y!=49) if(v[x+1][y+1]) dfs(x+1, y+1);
    if(x!=0 && y!=0) if(v[x-1][y-1]) dfs(x-1, y-1);
    if(x!=49 && y!=0) if(v[x+1][y-1]) dfs(x+1, y-1);
    if(x!=0 && y!=49) if(v[x-1][y+1]) dfs(x-1, y+1);
    if(x!=49) if(v[x+1][y]) dfs(x+1, y);
    if(x!=0) if(v[x-1][y]) dfs(x-1, y);
    if(y!=49) if(v[x][y+1]) dfs(x, y+1);
    if(y!=0) if(v[x][y-1]) dfs(x, y-1);
}

int main() {
    int w, h, cnt;
    while(1) {
        cnt = 0;
        for(int i=0; i<50; i++) {
            for(int j=0; j<50; j++) {
                v[i][j] = false;
            }
        }

        cin >> w >> h;
        if(w==0 && h==0) break;

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin >> v[i][j];
            }
        }

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(v[i][j]) {
                    cnt++;
                    dfs(i,j);
                }
            }
        }

        cout << cnt << '\n';
    }
}