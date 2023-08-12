#include <iostream>
using namespace std;

int main() {
    int L, A, B, C, D, E, F;
    cin >> L >> A >> B >> C >> D;

    if(A%C==0) E=A/C;
    else E=A/C+1;

    if(B%D==0) F=B/D;
    else F=B/D+1;

    if(E>=F) cout << L-E;
    else cout << L-F;
}