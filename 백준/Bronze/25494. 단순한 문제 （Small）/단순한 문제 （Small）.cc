#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;

    for(int i=0; i<T; i++) {
        int a, b, c; cin >> a >> b >> c;
        int cnt = 0;

        for(int j=1; j<=a; j++) {
            for(int k=1; k<=b; k++) {
                for(int l=1; l<=c; l++) {
                    if(j%k==k%l && k%l==l%j && l%j==j%k) cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}   