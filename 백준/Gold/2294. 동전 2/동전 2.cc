#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K; cin >> N >> K;
    int dp[K+1]{0};
    for(int i=1; i<=K; i++) dp[i] = K+1;

    vector<int> V(N+1);
    for(int i=1; i<=N; i++) cin >> V[i];
    sort(V.begin(), V.end());

    for(int i=1; i<=N; i++) {
        int v = V[i];
        for(int j=v; j<=K; j++) {
            dp[j] = min(dp[j], dp[j-v]+1);
        }
    }
    if(dp[K] == K+1) cout << -1;
    else cout << dp[K];

    return 0;
}