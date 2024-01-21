#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    long long len[N+2];
    len[1] = 1, len[2] = 1;;

    for(int i=3; i<=N+1; i++) {
        len[i] = len[i-1] + len[i-2];
    }

    cout << len[N]*2 + len[N+1]*2;

    return 0;
}   