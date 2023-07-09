#include <iostream>
using namespace std;

int main() {
    int N, M, K, cnt=0;
    cin >> N >> M >> K;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(K==cnt) {
                cout << i << ' ' << j;
                return 0;
            }
            cnt++;
        }
    }
    return 0;
}   