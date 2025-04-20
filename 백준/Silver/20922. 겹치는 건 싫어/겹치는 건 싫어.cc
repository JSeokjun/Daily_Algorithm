#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;
    int cnt = 0, maxLen = 0;
    vector<int> arr(N, 0);
    vector<int> freq(100001, 0);

    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<N; i++) {
        while (freq[arr[i]] >= K) {
            if (cnt + N-1-i <= maxLen) {
                cout << maxLen;
                return 0;
            }
            freq[arr[i-cnt]]--;
            cnt--;
        }

        freq[arr[i]]++;
        cnt++;

        if (cnt > maxLen) maxLen = cnt;
    }

    cout << maxLen;

    return 0;
}