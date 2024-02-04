#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N; 
    int arr[N], cj, cnt=0; 
    
    for(int i=0; i<N; i++) {
        string D; cin >> D;
        int C; cin >> C;
        arr[i] = C;
        if(D == "jinju") cj = C; 
    }

    for(int i=0; i<N; i++) {
        if(arr[i] > cj) cnt++; 
    }

    cout << cj << '\n' << cnt;

    return 0;
}   