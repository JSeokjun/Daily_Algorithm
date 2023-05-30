#include <iostream>
using namespace std;

int main() {
    int N, S, C, L, mS, mC, mL, W;
    cin >> N;

    for (int i=1; i<=N; i++) {
        cin >> S >> C >> L;
        if (i==1) {
            mS = S;
            mC = C;
            mL = L;
            W = 1;
        }
        else {
            if (S>mS) W=i;
            else if (S==mS) {
                if (C<mC) W=i;
                else if (C==mC) {
                    if (L<mL) W=i;
                }
            }
        }
        if (W==i) {
            mS = S;
            mC = C;
            mL = L;
        }
    }
    cout << W;
}