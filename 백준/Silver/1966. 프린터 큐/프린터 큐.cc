#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T, N, M, P, cnt;
    vector<int> v1, v2;
    cin >> T;
    for(int i=0; i<T; i++) {
        cnt = 0;
        v1.clear();
        v2.clear();
        cin >> N >> M;
        for(int j=0; j<N; j++) {
            if(j==M) v1.push_back(1);
            else v1.push_back(0);
            cin >> P;
            v2.push_back(P);
        }
        while(1) {
            if(v2[0] != *max_element(v2.begin(), v2.end())) {
                v2.push_back(v2[0]);
                v2.erase(v2.begin());
                v1.push_back(v1[0]);
                v1.erase(v1.begin());
            }
            else {
                cnt++;
                if(v1[0]==1) {
                    cout << cnt << '\n';
                    break;
                }
                else {
                    v2.erase(v2.begin());
                    v1.erase(v1.begin());
                }
            }
        }
    }
}   