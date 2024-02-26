#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M; cin >> N >> M;
    int arr[N][M], visit[N][M];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int sx, sy, size = 0, min_year = 0;
    queue<tuple<int,int,int>> Q;
 
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int tmp; cin >> tmp;
            if(tmp) {
                sx = i; sy = j;
                size++;
            }  
            arr[i][j] = tmp;
            visit[i][j] = 0;
        }
    }

    while(1) {
        int size_tmp = size, cnt = 0;

        if(!arr[sx-1][sy]) cnt++;
        if(!arr[sx+1][sy]) cnt++;
        if(!arr[sx][sy-1]) cnt++;
        if(!arr[sx][sy+1]) cnt++;
    
        Q.push({sx, sy, cnt});
        visit[sx][sy] = 1;
        
        while(!Q.empty()) {
            int x = get<0>(Q.front());
            int y = get<1>(Q.front());
            int cnt2 = get<2>(Q.front());

            Q.pop();
            size_tmp--;

            for(int i=0; i<4; i++) {
                int r = x + dx[i];
                int c = y + dy[i];

                if(arr[r][c] && !visit[r][c]) {
                    cnt = 0;
                    if(!arr[r-1][c]) cnt++;
                    if(!arr[r+1][c]) cnt++;
                    if(!arr[r][c-1]) cnt++;
                    if(!arr[r][c+1]) cnt++;
                    Q.push({r, c, cnt});
                    visit[r][c] = 1;
                }
            }

            if(arr[x][y]-cnt2 <= 0) {
                arr[x][y] = 0;
                size--;
            }
            else {
                sx = x; sy = y;
                arr[x][y] -= cnt2;
            }
        }

        int check = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(arr[i][j]) check = 1;  
                visit[i][j] = 0;
            }
        }

        if(!check) {
            cout << 0;
            break;
        }

        if(size_tmp) {
            cout << min_year;
            break;
        }

        min_year++;
    }

    return 0;
}   