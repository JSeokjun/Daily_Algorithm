#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M; cin >> N >> M;
    vector<pair<int,int>> V[N+1];
    queue<pair<int,int>> Q;
    int visit[N+1]{};

    for(int i=1; i<N; i++) {
        int a, b, c; cin >> a >> b >> c;
        V[a].push_back({b,c});
        V[b].push_back({a,c});
    }
    
    for(int i=0; i<M; i++) {
        int x, y; cin >> x >> y;

        Q.push({x,0});

        while(1) {
            int now = Q.front().first;
            int dst = Q.front().second;
            visit[now]++;
            Q.pop();

            if(now==y) {
                cout << dst << '\n';
                break;
            }
            
            for(int j=0; j<V[now].size(); j++) {
                if(!visit[V[now][j].first]) {
                    Q.push({V[now][j].first,dst+V[now][j].second});
                }
            }
        }
        memset(visit,0,sizeof(visit));
        while(!Q.empty()) Q.pop();
    }
}