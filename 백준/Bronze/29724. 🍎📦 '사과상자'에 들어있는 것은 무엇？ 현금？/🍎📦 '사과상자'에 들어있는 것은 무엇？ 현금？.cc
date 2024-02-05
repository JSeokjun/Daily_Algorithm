#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N;
    int G = 0, A = 0;
    
    while(N--) {
        char T;
        int W, H, L;
        cin >> T >> W >> H >> L;

        if(T == 'A') {
            G += 1000;
            if(W >= 12 && H >= 12 && L >= 12) {
                int num = (W/12)*(H/12)*(L/12);
                A += num; G += num*500;
            }
        }
        else G += 6000;
    }

    cout << G << '\n' << A*4000;

    return 0;
}   