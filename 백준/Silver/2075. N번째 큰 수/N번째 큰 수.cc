#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    set<int> S;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int num; cin >> num;

            if (S.size() >= N) {
                if (*S.begin() < num) {
                    S.erase(S.begin());
                    S.insert(num);
                }
            }
            else {
                S.insert(num);
            }
        }
    }

    cout << *S.begin();

    return 0;
}