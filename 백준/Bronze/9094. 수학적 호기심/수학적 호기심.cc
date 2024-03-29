#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;

    while(T--) {
        int n, m; cin >> n >> m;
        int cnt = 0;

        for(int a=1; a<n-1; a++) {
            for(int b=a+1; b<n; b++) {
                double e = (double)(a*a+b*b+m)/(a*b);
                if(e == (int)e) cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}   