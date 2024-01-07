#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<int> G[N+1];
    queue<int> Q;
    bool visit[N+1]{0};
    int parent[N+1];

    for(int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }  
    
    Q.push(1);

    while(!Q.empty()) {
        int node = Q.front();
        visit[node] = 1;
        Q.pop();

        for(int i=0; i<G[node].size(); i++) {
            int tmp = G[node][i]; 
            if(!visit[tmp]) {
                Q.push(tmp);
                parent[tmp] = node;
            }  
        }
    }

    for(int i=2; i<=N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}