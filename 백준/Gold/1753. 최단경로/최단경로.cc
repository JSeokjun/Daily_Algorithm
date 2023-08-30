#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E, K, u, v, w;
    cin >> V >> E >> K;
    vector<vector<pair<int,int>>> adj(V+1);
    for(int i=0; i<E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    vector<int> dist(V+1, 2e9);
    vector<bool> vis(V+1, 0);
    priority_queue<pair<int, int>> pq;
    dist[K] = 0;
    pq.push({0, K});

    while(!pq.empty()) {
        int cost=pq.top().first, idx=pq.top().second;
        cost = -cost;
        pq.pop();
        if(vis[idx]) continue;
        vis[idx] = 1;
        for(int i=0; i<adj[idx].size(); i++) {
            int next=adj[idx][i].first, val=adj[idx][i].second;
            if(dist[next] > cost+val) {
                dist[next] = cost+val;
                pq.push({-dist[next], next});
            }
        }
    }
    for(int i=1; i<V+1; i++) {
        if(dist[i]==2e9) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
}