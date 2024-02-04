#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N;
    bool F = 1;
    int S = 0, cntF = 0, maxS=0;
    
    for(int i=1; i<=N; i++) {
        int P; cin >> P;

        if(F == 0) cntF++;
        if(cntF == 2) {
            F = 1;
            cntF = 0;
        }
        
        if(P==0 && F==0) S = 0;
        else if(P==0 && F==1) F = 0;
        else S++;

        if(S > maxS) maxS = S; 
    }

    cout << maxS;

    return 0;
}   