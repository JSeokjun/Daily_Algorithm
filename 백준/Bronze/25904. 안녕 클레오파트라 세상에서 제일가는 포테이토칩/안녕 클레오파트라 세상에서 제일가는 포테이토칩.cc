#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, X; cin >> N >> X;
    vector<int> T(N);

    for (int i=0; i<N; i++) {
        cin >> T[i];
    }

    while (1) {
        for (int i=0; i<N; i++) {
            if (T[i] < X) {
                cout << i+1;
                return 0;
            }

            X++;
        }
    }
    
    return 0;
}