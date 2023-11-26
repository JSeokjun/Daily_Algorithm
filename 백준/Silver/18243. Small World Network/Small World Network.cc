#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K; cin >> N >> K;
    vector<int> V[N+1];
    queue<pair<int,int>> Q;
    int visit[N+1]{};

    for(int i=1; i<=K; i++) {
        int A, B; cin >> A >> B;
        V[A].push_back(B);
        V[B].push_back(A);
    }
            
    for(int i=1; i<=N; i++) {

        Q.push({i,0});

        while(!Q.empty()) {
            int now = Q.front().first;
            int cnt = Q.front().second;
            Q.pop();
            visit[now]++;

            if(cnt>6) {
                cout << "Big World!";
                return 0;
            }
            cnt++;

            for(int n : V[now]) {
                if(!visit[n]) {
                    Q.push({n,cnt});
                }
            }
        }
        
        for(int i=1; i<=N; i++) {
            if(visit[i]==0) {
                cout << "Big World!";
                return 0;
            }
        }
        memset(visit, 0, sizeof(visit));
    }

    cout << "Small World!";
    return 0;
}   