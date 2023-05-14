#include <iostream>
#include <string>
using namespace std;

int main() {
    int T, C, Q, D, N, P;
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> C;
        Q = C/25; C -= Q*25; 
        D = C/10; C -= D*10;
        N = C/5; C -= N*5;
        P = C/1;
        printf("%d %d %d %d\n", Q, D, N, P);
    }
}