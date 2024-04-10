#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(pair<int, int>&a, pair<int, int>&b) {
        return a.second > b.second;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N;
    int T[N+1]{0}, maxT[N+1]{0}, indgree[N+1]{0}, min_time=0;
    vector<int> V[N+1];
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> PQ;
    for(int i=1; i<=N; i++) {
        int n; cin >> T[i] >> n;
        if(!n) PQ.push({i,T[i]});
        indgree[i] = n;
        while(n--) {
            int t; cin >> t;
            V[t].push_back(i);
        }
    }

    while(!PQ.empty()) {
        int n = PQ.top().first;
        min_time = PQ.top().second;
        PQ.pop();

        for(int i=0; i<V[n].size(); i++) {
            int next_n = V[n][i];
            indgree[next_n]--;
            if(!indgree[next_n]) PQ.push({next_n, min_time+T[next_n]});
        }
    }

    cout << min_time;

    return 0;
}