#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M; cin >> N >> M;
    vector<long long> T;
    long long tmp;

    for(int i=0; i<N; i++) {
        cin >> tmp;
        T.push_back(tmp);
    }
    
    long long low = 0, high = 2000000000, mid = (low + high + 1) / 2;

    while(low < high) {
        long long cnt = 0;
        for(int i=0; i<N; i++) {
            if(T[i] >= mid) cnt += T[i]-mid;
        }

        if(cnt < M) high = mid - 1;
        else low = mid;

        mid = (low + high + 1) / 2;
    }

    cout << mid; 
}