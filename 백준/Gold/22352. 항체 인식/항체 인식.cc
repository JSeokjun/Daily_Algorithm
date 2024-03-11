#include <iostream>
#include <vector>
using namespace std;

int N, M, a, b, change;
int og_before[30][30], before[30][30], after[30][30];
int visit[30][30];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && ny>=0 && nx<N && ny<M && !visit[nx][ny] && before[nx][ny]==b) {
            visit[nx][ny] = 1;
            before[nx][ny] = change;
            dfs(nx, ny);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> og_before[i][j];
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> after[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(!visit[i][j]) {
                for(int k=0; k<N; k++) {
                    for(int l=0; l<M; l++) {
                        before[k][l] = og_before[k][l];
                    }
                }

                b = before[i][j];
                change = after[i][j];
                before[i][j] = change;
                visit[i][j] = 1;
                dfs(i, j);

                bool same = 1;
                for(int k=0; k<N; k++) {
                    for(int l=0; l<M; l++) {
                        if(before[k][l] != after[k][l]) {
                            same = 0;
                            break;
                        }
                    }
                    if(!same) break;
                }
             
                if(same) {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }

    cout << "NO";
    return 0;
}