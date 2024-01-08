#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    bool** M = new bool*[R];
    for (int i = 0; i < R; i++) {
        M[i] = new bool[C];
    }

    for(int i=0; i<R; i++) {
        string tmp; cin >> tmp;
        for(int j=0; j<C; j++) {
            if(tmp[j] == 'L') M[i][j] = 1;
            else M[i][j] = 0;
        }
    }

    int result = 0;

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(M[i][j]) {

                bool** visit = new bool*[R];
                for (int k = 0; k < R; k++) {
                    visit[k] = new bool[C]{0};
                }

                queue<tuple<int,int,int>> Q;
                Q.push({i, j, 0});
                visit[i][j] = 1;

                while(!Q.empty()) {
                    int x = get<0>(Q.front()), y = get<1>(Q.front());
                    int cnt = get<2>(Q.front());
                    result = max(result, cnt);
                    Q.pop();
                    
                    if(x>0 && M[x-1][y] && !visit[x-1][y]) {
                        Q.push({x-1, y, cnt+1});
                        visit[x-1][y] = 1;
                    }
                    if(y>0 && M[x][y-1] && !visit[x][y-1]) {
                        Q.push({x, y-1, cnt+1});
                        visit[x][y-1] = 1;
                    }
                    if(x+1<R && M[x+1][y] && !visit[x+1][y]) {
                        Q.push({x+1, y, cnt+1});
                        visit[x+1][y] = 1;
                    }
                    if(y+1<C && M[x][y+1] && !visit[x][y+1]) {
                        Q.push({x, y+1, cnt+1});
                        visit[x][y+1] = 1;
                    }
                }

                for (int k = 0; k < R; k++) {
                    delete[] visit[k];
                }
                delete[] visit;
            }
        }
    }

    for (int i = 0; i < R; i++) {
        delete[] M[i];
    }
    delete[] M;

    cout << result;

    return 0;
}
