#include <iostream>
using namespace std;

int main() {
    int N, W, H, L;
    cin >> N;
    cin >> W;
    cin >> H;
    for (int i=0; i<N; i++) {
        cin >> L;
        if (L <= W || L <= H || L*L <= W*W+H*H) cout << "DA";
        else cout << "NE";
        cout << '\n';
    }
}