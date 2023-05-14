#include <iostream>
using namespace std;

int main() {
    int T, s, n, q, p, tq;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> s;
        cin >> n;
        tq = 0;
        for(int j=0; j<n; j++) {
            cin >> q;
            cin >> p;
            tq += q*p;
        }
        cout << s+tq;
        cout << '\n';
    }
}