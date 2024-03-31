#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M, cnt=0; cin >> N >> M;
    vector<int> V[N+1], R;
    queue<int> Q;
    int indegree[N+1]{0};

    for(int i=0; i<M; i++) {
        int n; cin >> n;
        int tmp[n]{0};

        for(int j=0; j<n; j++) {
            cin >> tmp[j];
        }
        for(int j=0; j<n-1; j++) {
            V[tmp[j]].push_back(tmp[j+1]);
            indegree[tmp[j+1]]++;
        }
    }

    for(int i=1; i<=N; i++) {
        if(!indegree[i]) Q.push(i);
    }

    while(!Q.empty()) {
        int node = Q.front(); 
        R.push_back(node);
        Q.pop();
        cnt++;

        for(int i=0; i<V[node].size(); i++) {
            int n = V[node][i];
            indegree[n]--;
            if(!indegree[n]) Q.push(n);
        }
    }
    if(cnt != N) cout << 0;
    else {
        for(int i=0; i<N; i++) cout << R[i] << '\n';
    }

    return 0;
}