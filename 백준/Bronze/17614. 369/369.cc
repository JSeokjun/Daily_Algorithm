#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, cnt=0; cin >> N;

    for(int i=1; i<=N; i++) {
        string str = to_string(i);
        int len = str.length();
        for(int j=0; j<len; j++) {
            if(str[j]=='3' || str[j]=='6' || str[j]=='9') cnt++;
        }
    }

    cout << cnt;
    return 0;
}   