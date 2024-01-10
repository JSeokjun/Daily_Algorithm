#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int yen; cin >> yen; yen = 1000-yen;
    int cnt = 0, idx = 0;
    int change[6] = {500, 100, 50, 10, 5, 1};

    while(yen) {
        while(yen < change[idx]) idx++;
        cnt += yen / change[idx];
        yen %= change[idx];
    }

    cout << cnt;

    return 0;
}
