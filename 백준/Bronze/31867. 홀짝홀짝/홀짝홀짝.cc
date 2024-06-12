#include <iostream>
using namespace std;

int main() {
    int N, cnt[2]{0}; string K;
    cin >> N >> K;

    for(int i=0; i<N; i++) {
        if(K[i]==0) cnt[0]++;
        else if(K[i]%2==0) cnt[0]++;
        else cnt[1]++;
    }

    if(cnt[0]>cnt[1]) cout << 0;
    else if(cnt[0]<cnt[1]) cout << 1;
    else cout << -1;

    return 0;
}