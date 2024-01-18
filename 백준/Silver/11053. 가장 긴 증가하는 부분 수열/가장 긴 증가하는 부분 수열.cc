#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int S[1001];
vector<int> D(1001, 0);

int dp(int x) {
    if(x == 1) return 1;
    else {
        int max = 0, n = 0;

        for(int i=1; i<x; i++) {
            if(D[i]) n = D[i]; 
            else {
                n = dp(i);
                D[i] = n;
            }

            if(S[i] < S[x] && max < n+1) max = n+1;
            else if(S[i] >= S[x] && max < 1) max = 1;
        }
        D[x] = max;
        return max;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int A; cin >> A;
    if(A == 1) {
        cout << 1;
        return 0;
    }

    for(int i=1; i<=A; i++) cin >> S[i];

    dp(A);
    sort(D.begin(), D.end());
    cout << D.back();

    return 0;
}