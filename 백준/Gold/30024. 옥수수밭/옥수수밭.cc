#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K; cin >> N >> M;
    int value[N+1][M+1], visit[N+1][M+1];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1}; 
    priority_queue<tuple<int,int,int>> pq;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            int v; cin >> v;
            
            if(i==1 || i==N || j==1 || j==M) {
                pq.push({v, i, j});
                visit[i][j] = 1;
            }
            else visit[i][j] = 0; 
            
            value[i][j] = v;
        }
    }

    cin >> K;

    while(K--) {
        int v = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        cout << x << ' ' << y << '\n';
        
        for(int i=0; i<4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
            if(!visit[next_x][next_y] && next_x>=1 && next_x<=N && next_y>=1 && next_y<=M) {
                pq.push({value[next_x][next_y], next_x, next_y});
                visit[next_x][next_y] = 1;
            }
        } 
    }

    return 0;
}