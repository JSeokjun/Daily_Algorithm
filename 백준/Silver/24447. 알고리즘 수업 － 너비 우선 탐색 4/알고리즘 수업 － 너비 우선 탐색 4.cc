#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M, R; cin >> N >> M >> R;
    vector<int> G[N+1];
    queue<pair<int,int>> Q;
    int visit[N+1]{0};
    long long result = 0, t = 0;

    while(M--) {    
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    Q.push({R, 0});
    visit[R] = 1;

    while(!Q.empty()) {
        int n = Q.front().first;
        int d = Q.front().second;

        t++;
        result += d*t;
        Q.pop();

        for(int i : G[n]) {
            if(!visit[i]) {
                Q.push({i, d+1});
                visit[i] = 1;
            }
        }
    }

    cout << result;

    return 0;
}   