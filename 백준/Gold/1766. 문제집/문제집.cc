#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M; cin >> N >> M;
    vector<int> V[N+1];
    priority_queue<int, vector<int>, greater<int>> pq;
    int indgree[N+1]{0};

    for(int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        V[a].push_back(b);
        indgree[b]++;
    }
    for(int i=1; i<=N; i++) if(!indgree[i]) pq.push(i);

    while(!pq.empty()) {
        int n = pq.top();
        cout << n << ' ';
        pq.pop();

        for(int i=0; i<V[n].size(); i++) {
            int next_n = V[n][i];
            indgree[next_n]--;
            if(!indgree[next_n]) pq.push(next_n);
        }
    }

    return 0;
}