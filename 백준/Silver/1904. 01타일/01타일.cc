#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N;
    int R = 15746;
    vector<int> V(N+1);
    V[1] = 1; V[2] = 2;
    
    for(int i=3; i<=N; i++) {
        V[i] = V[i-1]%R + V[i-2]%R;
    }

    cout << V[N]%R;
}   