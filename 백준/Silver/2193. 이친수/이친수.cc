#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N;
    vector<long> V(N+1);
    V[1] = 1; V[2] = 1;
    
    for(int i=3; i<=N; i++) {
        V[i] = V[i-1] + V[i-2];
    }

    cout << V[N];
}   