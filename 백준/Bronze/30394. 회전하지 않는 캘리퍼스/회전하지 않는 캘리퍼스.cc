#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N;
    int x, y; cin >> x >> y;
    int max = y, min = y;

    for(int i=0; i<N-1; i++) {
        cin >> x >> y;
        if(y>max) max = y;
        if(y<min) min = y;
    }

    cout << max - min;

    return 0;
}   