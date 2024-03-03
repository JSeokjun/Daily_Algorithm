#include <iostream>
#include <vector>
using namespace std;

int N, M, og_map[8][8], map[8][8], loc[64];

void dfs(int x, int y) {
    map[x][y] = 2;
    if(x>0 && !map[x-1][y]) dfs(x-1, y);
    if(y>0 && !map[x][y-1]) dfs(x, y-1);
    if(x<N-1 && !map[x+1][y]) dfs(x+1, y);
    if(y<M-1 && !map[x][y+1]) dfs(x, y+1);
}

int main() {
    cin >> N >> M;
    int idx = 0, max_cnt = 0;
    vector<pair<int,int>> V;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int tmp; cin >> tmp;
            og_map[i][j] = tmp;
            map[i][j] = tmp;
            loc[idx++] = tmp;
            if(tmp==2) V.push_back({i,j});
        }
    }

    for(int i=0; i<N*M-2; i++) {
        for(int j=i+1; j<N*M-1; j++) {
            for(int k=j+1; k<N*M; k++) {
                if(!loc[i] && !loc[j] && !loc[k]) {
                    int cnt = 0;
                    map[i/M][i - i/M*M] = 1;
                    map[j/M][j - j/M*M] = 1;
                    map[k/M][k - k/M*M] = 1;

                    for(int l=0; l<V.size(); l++) {
                        dfs(V[l].first, V[l].second);
                    }
                    for(int l=0; l<N; l++) {
                        for(int m=0; m<M; m++) {
                            if(!map[l][m]) cnt++;
                        }
                    }
                    if(cnt > max_cnt) max_cnt = cnt;
                    for(int l=0; l<N; l++) {
                        for(int m=0; m<M; m++) {
                            map[l][m] = og_map[l][m];
                        }
                    }
                }
            }
        }
    }
    cout << max_cnt;

    return 0;
}