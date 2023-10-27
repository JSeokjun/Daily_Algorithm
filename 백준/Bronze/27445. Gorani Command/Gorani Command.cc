#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    int arr[N+M];
    for(int i=1; i<N+M; i++) {
        cin >> arr[i];
    }

    int r = arr[1], rr = 1;
    int c = arr[N], rc = 1;
    for(int i=2; i<=N; i++) {
        if(r>arr[i]) {
            r = arr[i];
            rr = i;
        }    
    }
    for(int i=N; i<N+M; i++) {
        if(c>arr[i]) {
            c = arr[i];
            rc = i-N+1;
        }
    }

    cout << rr << ' ' << rc;

    return 0; 
}   