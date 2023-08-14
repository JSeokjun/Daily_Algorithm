#include <iostream>
using namespace std;

int main() {
    int T, A, B, C, D, E;
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> A >> B >> C >> D >> E;
        cout << fixed;
        cout.precision(2);
        cout << '$' << A*350.34 + B*230.9 + C*190.55 + D*125.3 + E*180.9 << '\n';
    }
}