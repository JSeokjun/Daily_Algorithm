#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    vector<int> V[N+1];
    queue<pair<int,int>> Q;

    for(int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a); 
    }

    int bacon = 10000;
    int result = 0;
    bool visit[N+1];
    memset(visit, 0, sizeof(visit));

    for(int i=N; i>=1; i--) {
        int n=0, cnt=0, sum=0;        
        Q.push({i, 0});
        visit[i] = 1;

        while(!Q.empty()) {
            n = Q.front().first;
            cnt = Q.front().second;
            sum += cnt;
            
            Q.pop();

            for(int j=0; j<V[n].size(); j++) {
                if(!visit[V[n][j]]) {
                    Q.push({V[n][j], cnt+1});
                    visit[V[n][j]] = 1;
                }
            }
        }

        if(bacon >= sum) {
            result = i;
            bacon = sum;
        }
        memset(visit, 0, sizeof(visit));
    }
    
    cout << result;

    return 0;
}