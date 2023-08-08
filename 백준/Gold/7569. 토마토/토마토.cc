#include <iostream>
#include <queue>
using namespace std;

int main() {
    int M, N, H;
    cin >> M >> N >> H;

    int v[H][N][M];
    queue<pair<int,pair<int,int>>> q;

    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                cin >> v[i][j][k];
                if(v[i][j][k]==1) q.push(make_pair(i,make_pair(j,k)));
            }
        }
    }    
    
    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int z = q.front().first;

        q.pop();

        if(x<N-1) if(!v[z][x+1][y]) {
            q.push(make_pair(z,make_pair(x+1,y)));
            v[z][x+1][y] = v[z][x][y]+1;
        }
        if(y<M-1) if(!v[z][x][y+1]) {
            q.push(make_pair(z,make_pair(x,y+1)));
            v[z][x][y+1] = v[z][x][y]+1;
        }
        if(x>0) if(!v[z][x-1][y]) {
            q.push(make_pair(z,make_pair(x-1,y)));
            v[z][x-1][y] = v[z][x][y]+1;
        }
        if(y>0) if(!v[z][x][y-1]) {
            q.push(make_pair(z,make_pair(x,y-1)));
            v[z][x][y-1] = v[z][x][y]+1;
        }
        if(z<H-1) if(!v[z+1][x][y]) {
            q.push(make_pair(z+1,make_pair(x,y)));
            v[z+1][x][y] = v[z][x][y]+1;
        }
        if(z>0) if(!v[z-1][x][y]) {
            q.push(make_pair(z-1,make_pair(x,y)));
            v[z-1][x][y] = v[z][x][y]+1;
        }   
    }

    int max = 0;
    for(int i=0; i<H; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<M; k++) {
                if(!v[i][j][k]) {
                    cout << -1;
                    return 0;
                }
                if(max<v[i][j][k]) max=v[i][j][k];
            }
        }
    }

    cout << max-1;
}