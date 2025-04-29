#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, D, K, C; cin >> N >> D >> K >> C;
    vector<int> belt(N+K-1, 0);
    vector<int> eatSushi(D+1, 0);
    int cntEatSushi = 0, maxEatSushi = 0;

    for (int i=0; i<N; i++) {
        cin >> belt[i];
    }
    for (int i=0; i<K-1; i++) {
        belt[i+N] = belt[i];
    }

    for (int i=0; i<K; i++) {
        if (eatSushi[belt[i]] == 0) {
            cntEatSushi++; 
        }
        eatSushi[belt[i]]++;
    }

    if (eatSushi[C] == 0) maxEatSushi = cntEatSushi+1;
    else maxEatSushi = cntEatSushi;

    for (int i=K; i<N+K-1; i++) {
        if (belt[i-K] != belt[i]) {
            eatSushi[belt[i-K]]--;
            eatSushi[belt[i]]++;

            if (eatSushi[belt[i-K]] == 0) {
                cntEatSushi--;
            }
            if (eatSushi[belt[i]] == 1) {
                cntEatSushi++;
            }
        }

        if (eatSushi[C] == 0) {
            if (cntEatSushi+1 > maxEatSushi) maxEatSushi = cntEatSushi+1;
        }
        else {
            if (cntEatSushi > maxEatSushi) maxEatSushi = cntEatSushi;
        }
    }

    cout << maxEatSushi;

    return 0;
}