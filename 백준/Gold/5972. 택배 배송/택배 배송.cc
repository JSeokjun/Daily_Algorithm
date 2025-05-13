#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int,int>>> graph(N+1);
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    vector<int> dist(N+1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (cost > dist[node]) continue;
        
        for (auto& next : graph[node]) {
            int next_node = next.first;
            int next_cost = next.second;
            
            if (dist[next_node] > dist[node] + next_cost) {
                dist[next_node] = dist[node] + next_cost;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    
    cout << dist[N];
    
    return 0;
}