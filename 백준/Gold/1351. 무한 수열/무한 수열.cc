#include <iostream>
#include <map>
using namespace std;

map<long long, long long> m;

long long infinite(long long N, long long P, long long Q) {
    if(m[N] != 0) return m[N];
    return m[N] = infinite(N/P, P, Q) + infinite(N/Q, P, Q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long N, P, Q;
    cin >> N >> P >> Q;
    m[0] = 1;
    cout << infinite(N,P,Q);
}