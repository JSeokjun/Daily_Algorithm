#include <iostream>
#include <map>
using namespace std;

long long N, P, Q, X, Y;
map<long long, long long> M;

long long dp(long long x) {
    if(x <= 0) return 1;
    else if(M[x]) return M[x];
    else return M[x] = dp(x/P-X) + dp(x/Q-Y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> P >> Q >> X >> Y;
    cout << dp(N);
    return 0;
}   