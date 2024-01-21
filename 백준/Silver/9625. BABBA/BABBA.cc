#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int K; cin >> K;
    
    if(K == 1) {
        cout << 0 << ' ' << 1;
        return 0;
    }

    vector<pair<int,int>> V(K+1);
    
    V[1].first = 0;
    V[1].second = 1;
    V[2].first = 1;
    V[2].second = 1;

    for(int i=3; i<=K; i++) {
        V[i].first = V[i-1].first + V[i-2].first;
        V[i].second = V[i-1].second + V[i-2].second;
    }

    cout << V[K].first << ' ' << V[K].second;

    return 0;
}   