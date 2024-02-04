#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T, N; cin >> T >> N;
    int sum = 0;

    for(int i=0; i<N; i++) {
        int F; cin >> F;
        sum += F;
    }

    if(sum >= T) cout << "Padaeng_i Happy";
    else cout << "Padaeng_i Cry";

    return 0;
}   