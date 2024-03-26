#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int visit[N+1]{0}, max_len = 0, max_node = 0;
    vector<pair<int,int>> V[N+1];
    queue<pair<int,int>> Q;

    for(int i=0; i<N; i++) {
        int a, b, c; cin >> a;
        while(1) {
            cin >> b;
            if(b == -1) break;
            cin >> c;
            V[a].push_back({b,c});
            V[b].push_back({a,c});    
        }
    }

    Q.push({1, 0});
    visit[1] = 1;

    while(!Q.empty()) {
        int n = Q.front().first;
        int len = Q.front().second;
        if(len > max_len) {
            max_len = len;
            max_node = n;
        }
    
        Q.pop();

        for(int j=0; j<V[n].size(); j++) {
            int node = V[n][j].first;
            if(!visit[node]) {
                Q.push({node, len+V[n][j].second});
                visit[node] = 1;
            }
        }
    }

    for(int j=1; j<=N; j++) visit[j] = 0;
    Q.push({max_node, 0});
    visit[max_node] = 1;

    while(!Q.empty()) {
        int n = Q.front().first;
        int len = Q.front().second;
        if(len > max_len) {
            max_len = len;
            max_node = n;
        }
    
        Q.pop();

        for(int j=0; j<V[n].size(); j++) {
            int node = V[n][j].first;
            if(!visit[node]) {
                Q.push({node, len+V[n][j].second});
                visit[node] = 1;
            }
        }
    }

    cout << max_len;
    
    return 0;
}