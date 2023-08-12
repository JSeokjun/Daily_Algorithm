#include <iostream>
using namespace std;

int main() {
    int L, P, N;
    cin >> L >> P;
    int S = L*P;
    for(int i=0; i<5; i++) {
        cin >> N;
        cout << N-S << ' ';
    }
}