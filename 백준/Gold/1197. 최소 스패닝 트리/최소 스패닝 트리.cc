#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;

    UnionFind(int x) {
        parent.resize(x);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        parent[y] = x;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int v, e;
    cin >> v >> e;
    vector<tuple<int,int,int>> edge;

    for(int i=0; i<e; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }

    sort(edge.begin(), edge.end());

    UnionFind uf(v + 1);
    int cnt = 0, tot =0;
    for(int i=0; i<edge.size(); i++) {
        int cost=get<0>(edge[i]), x=get<1>(edge[i]), y=get<2>(edge[i]); 
        if(uf.find(x) != uf.find(y)) {
            tot += cost;
            uf.merge(x, y);
            if(++cnt == v-1) break;
        }
    }
    cout << tot;
    return 0;
}