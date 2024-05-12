#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;
vector<int> V, R;

void lotto(int cnt, int start) {
    if(cnt == 6) {
        for(int i=0; i<6; i++) cout << R[i] << ' ';
        cout << '\n';
    }
    else {
        for(int i=start; i<K; i++) {
            R.push_back(V[i]);
            lotto(cnt+1, i+1);
            R.pop_back();
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    while(1) {
        cin >> K;
        if(!K) break;

        for(int i=0; i<K; i++) {
            int n; cin >> n;
            V.push_back(n);
        }
        sort(V.begin(), V.end());
        lotto(0, 0);

        cout << '\n';
        while(!R.empty()) R.pop_back();
        while(!V.empty()) V.pop_back();
    }

    return 0;
}