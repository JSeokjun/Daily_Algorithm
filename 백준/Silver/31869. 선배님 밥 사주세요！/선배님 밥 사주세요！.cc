#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    string S;
    int W, D, P, N, M, C=0, R=0;
    bool B = 0;
    cin >> N;
    if(N == 0) {
        cout << 0;
        return 0;
    }
    vector<tuple<int,int,int,string>> V(N);
    vector<int> V2(N);

    for(int i=0; i<N; i++) {
        cin >> S >> W >> D >> P;
        V[i] = {W, D, P, S};
    }
    sort(V.begin(), V.end());

    for(int i=0; i<N; i++) {
        cin >> S >> M;
        for(int j=0; j<N; j++) {
            if(get<3>(V[j]) == S) {
                V2[j] = M;
                break;
            }
        }
    }
    
    for(int i=1; i<=10; i++) {
        for(int j=0; j<=6; j++) {
            for(int k=0; k<N; k++) {
                if(get<0>(V[k])==i && get<1>(V[k])==j && get<2>(V[k])<=V2[k]) {
                    C++; B = 1;
                    break;
                }
            }
            if(C > R) R = C;
            if(!B) C = 0;
            else B = 0;
        }
    }

    cout << R;
    return 0;
}