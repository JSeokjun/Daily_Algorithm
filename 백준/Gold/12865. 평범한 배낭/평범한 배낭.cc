#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K; cin >> N >> K;
    int dp[K+1]{0};

    for(int i=1; i<=N; i++) {
        int w, v; cin >> w >> v;
        for(int j=K; j>=w; j--) {
            dp[j] = max(dp[j], dp[j-w]+v);
        }
    }

    cout << *max_element(dp, dp+(K+1));

    return 0;
}