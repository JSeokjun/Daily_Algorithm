#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, m, x, y;
    cin >> n >> a >> b >> m;
    vector<int> adj[n+1];
    vector<int> dis(n+1,0);
    vector<bool> vis(n+1,0);
    queue<pair<int,int>> q;
    for(int i=0; i<m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    q.push({a,0});
    while(!q.empty()) {
        int idx=q.front().first, val=q.front().second;
        q.pop();
        vis[idx] = 1;
        for(int i=0; i<adj[idx].size(); i++) {
            if(!vis[adj[idx][i]]) {
                q.push({adj[idx][i],val+1});
                dis[adj[idx][i]] = val+1;
            }
        }
    }
    if(dis[b]) cout << dis[b];
    else cout << -1; 
}