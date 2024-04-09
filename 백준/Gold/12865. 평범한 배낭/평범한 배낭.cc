#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K; cin >> N >> K;
    int dp[N+1][K+1];
    for(int i=0; i<=K; i++) dp[0][i] = 0;

    for(int i=1; i<=N; i++) {
        int w, v; cin >> w >> v;
        for(int j=0; j<=K; j++) {
            if(w>j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v);
        }
    }

    cout << dp[N][K];

    return 0;
}