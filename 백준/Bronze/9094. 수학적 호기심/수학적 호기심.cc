#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;

    while(T--) {
        double n, m; cin >> n >> m;
        int cnt = 0;

        for(double a=1; a<n-1; a++) {
            for(double b=a+1; b<n; b++) {
                double e = (a*a+b*b+m)/(a*b);
                if(e == (int)e) cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}   