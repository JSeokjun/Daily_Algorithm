#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, tmp; cin >> N;
    vector<int> A;

    for(int i=1; i<=N; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    sort(A.begin(),A.end());

    int M; cin >> M;

    for(int i=1; i<=M; i++) {
        cin >> tmp;
        int pos = lower_bound(A.begin(), A.end(), tmp) - A.begin();
        
        if(pos==A.size()) cout << 0 << '\n';
        else if(A[pos]==tmp) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}