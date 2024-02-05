#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T; cin >> T;

    while(T--) {
        int n; cin >> n;
        if(n<3) cout << 1 << '\n';
        else cout << 3 << '\n';
    }

    return 0;
}   