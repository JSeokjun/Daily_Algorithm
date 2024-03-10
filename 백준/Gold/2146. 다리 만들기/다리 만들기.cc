#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M[100][100], visit[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt = 1, min_len = 1000;
queue<tuple<int,int,int>> Q;

void search_island(int x, int y) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
    
        if(nx>=0 && ny>=0 && nx<N && ny<N && M[nx][ny] && !visit[nx][ny]) {
            visit[nx][ny] = 1;
            M[nx][ny] = cnt;
            search_island(nx, ny);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> M[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(M[i][j] && !visit[i][j]) {
                M[i][j] = cnt;
                search_island(i, j);
                cnt++;
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(M[i][j]) {
                for(int i=0; i<N; i++) {
                    for(int j=0; j<N; j++) {
                        visit[i][j] = 0;
                    }
                }

                Q.push({i, j, 0});
                visit[i][j] = 1;
                int num = M[i][j];
                
                while(!Q.empty()) {
                    int x = get<0>(Q.front());
                    int y = get<1>(Q.front());
                    int len = get<2>(Q.front());

                    Q.pop();

                    if(M[x][y] && M[x][y]!=num && len < min_len) {
                        min_len = len;
                    }

                    for(int i=0; i<4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
    
                        if(nx>=0 && ny>=0 && nx<N && ny<N && M[nx][ny]!=num && !visit[nx][ny]) {
                            visit[nx][ny] = 1;
                            Q.push({nx, ny, len+1});
                        }
                    }  
                }
            }
        }
    }

    cout << min_len - 1;

    return 0;
}