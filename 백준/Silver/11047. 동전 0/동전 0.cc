#include <iostream>
using namespace std;

int main() {
    int N, K, M=0, cnt=0;
    cin >> N >> K;
    int arr[N];

    for(int i=N-1; i>=0; i--) {
        cin >> arr[i];
    }
    for(int i=0; i<N; i++) {
        while(1) {
            if(M<K) {
                if(K-M<arr[i]) break;
                else {
                    M+=arr[i];
                    cnt++;
                }
            }
            else if(M==K) {
                cout << cnt;
                break;
            }
        }
        if(M==K) break;
    }
}