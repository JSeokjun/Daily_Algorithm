#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, a, idx=0, cnt=0;
    cin >> N >> K;
    vector<int> v;
    bool b = true;
    for(int i=0; i<N; i++) {
        cin >> a;
        v.push_back(a);
    }
    for(int i=0; i<N; i++) {
        if(idx==K) {
            cout << cnt;
            b = false;
            break;
        }
        else {
            idx = v[idx];
            cnt++;
        }
    }
    if(b) cout << -1;
}   