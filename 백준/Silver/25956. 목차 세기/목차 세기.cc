#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int level[1000000], num[1000000], n;
    
    cin >> n >> level[0];

    if (level[0] != 1) {
        cout << -1;
        return 0;
    }
    
    for (int i = 1; i < n; i++) {
        cin >> level[i];

        if (level[i - 1] + 1 < level[i]) {
            cout << -1;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i + 1; j < n; j++) {
            if (level[j] == level[i] + 1) cnt++;
            if (level[j] == level[i]) break;
        }
        num[i] = cnt;
    }

    for (int i = 0; i < n; i++) cout << num[i] << '\n';
    
    return 0;
}