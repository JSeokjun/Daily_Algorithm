#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, idx=0, cnt=1;
    cin >> N >> K;
    vector<int> v1, v2;
    
    for(int i=1; i<=N; i++) {
        v1.push_back(i);
    }
    while(!v1.empty()) {
        if(idx>=v1.size()) idx=0;
        
        if(cnt==K) {
            v2.push_back(v1[idx]);
            v1.erase(v1.begin()+idx);
            cnt=1;
        }
        else {  
            idx++;
            cnt++;
        }
    }
    cout << '<';
    for(int i=0; i<N; i++) {
        if(i==N-1) cout << v2[i];
        else cout << v2[i] << ',' << ' ';
    }
    cout << '>';
}