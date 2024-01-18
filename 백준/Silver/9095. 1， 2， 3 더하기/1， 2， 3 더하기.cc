#include <iostream>
using namespace std;

int dp(int x) {
    if(x == 1) return 1;
    else if(x == 2) return 2;
    else if(x == 3) return 4;
    else return dp(x-1) + dp(x-2) + dp(x-3); 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;

    while(T--) {
        int n; cin >> n;

        cout << dp(n) << '\n';
    }

    return 0;
}