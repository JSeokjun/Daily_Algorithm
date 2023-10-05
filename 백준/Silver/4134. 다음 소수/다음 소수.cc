#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    long long T, N;
    bool check = 1;
    cin >> T;

    for(int i=0; i<T; i++) {
        cin >> N;
        if(N==0 || N==1) {
            cout << 2 << '\n';
            continue;
        }
        while(1) {
            for(int j=2; j<=sqrt(N); j++) {
                if(N%j==0) {
                    check=0;
                    break;
                }
            }
            if(check) {
                cout << N << '\n';
                break;
            }
            check = 1;
            N++;
        }
    }
}   