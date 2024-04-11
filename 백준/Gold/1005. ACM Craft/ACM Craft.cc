#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp
{
    bool operator()(pair<int,int> &a, pair<int,int> &b) {
        return a.second > b.second;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T; cin >> T;
    int time[1001]{0};
    vector<int> V[1001];
    int indgree[1001]{0};
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    while(T--) {
        int N, K, W; cin >> N >> K;
        for(int i=1; i<=N; i++) cin >> time[i];
        for(int i=1; i<=K; i++) {
            int a, b; cin >> a >> b;
            V[a].push_back(b);
            indgree[b]++;
        }
        cin >> W;

        for(int i=1; i<=N; i++) if(!indgree[i]) pq.push({i, time[i]});

        while(1) {
            int n = pq.top().first;
            int t = pq.top().second;
            if(n == W) {
                cout << t << '\n';
                break;
            }
            pq.pop();

            for(int i=0; i<V[n].size(); i++) {
                int next_n = V[n][i];
                indgree[next_n]--;
                if(!indgree[next_n]) pq.push({next_n, t+time[next_n]});
            }
        }
        while(!pq.empty()) pq.pop();
        for(int i=1; i<=N; i++) {
            while(!V[i].empty()) V[i].pop_back();
            indgree[i] = 0;
        }
    }

    return 0;
}