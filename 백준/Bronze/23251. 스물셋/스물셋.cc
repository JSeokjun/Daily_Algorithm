#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, k;
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> k;
        cout << k*23 << '\n';
    }
}   