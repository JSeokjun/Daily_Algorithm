#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M; cin >> N >> M;
    long long int A[M+1]{}, B[N+1]{};
    for(int i=1; i<=M; i++) cin >> A[i];
    for(int i=1; i<=N; i++) cin >> B[i];

    long long int S[M+1]{}, sum=0; 
    for(int i=1; i<=M; i++) {
        sum += A[i];
        S[i] = sum;
    }

    for(int i=1; i<=N; i++) {
        if(B[i]>S[M]) {
            cout << "Go away!" << '\n';
            continue;
        }
        int pos = lower_bound(S, S+M, B[i]) - S;
        cout << pos << '\n';
    }

    return 0;
}