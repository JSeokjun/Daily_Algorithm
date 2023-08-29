#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;

    UnionFind(int x) {
        parent.resize(x);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        parent[y] = x;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    UnionFind uf(n + 1);
    while (m--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 0) uf.merge(a, b);
        else cout << (uf.find(a) == uf.find(b) ? "YES\n" : "NO\n");
    }
    return 0;
}