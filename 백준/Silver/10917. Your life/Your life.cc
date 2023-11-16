#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    vector<int> V[N+1];

    if(N==1) {
        cout << 0;
        return 0;
    }

    for(int i=0; i<M; i++) {
        int x, y; cin >> x >> y;
        V[x].push_back(y);
    }

    int visit[N+1]{};
    int cnt = 0;
    queue<pair<int,int>> Q;

    Q.push({1,0});
    visit[1]++;

    while(!Q.empty()) {
        int now = Q.front().first;
        int time = Q.front().second+1;
        Q.pop();

        for(int next : V[now]) {
            if(next==N) {
                cout << time;
                return 0;
            }
            
            if(visit[next]==0) {
                Q.push({next,time});
                visit[next]++;    
            }
        }
    }

    cout << -1;
    
    return 0;
}   