#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    stack<pair<int,int>> S;

    for(int i=1; i<=N; i++) {
        int H; cin >> H;
        
        if(S.empty()) cout << 0 << ' ';
        else if(S.top().first < H) {
            while(1) {
                S.pop();
                if(S.empty()) {
                    cout << 0 << ' ';
                    break;
                }
                if(S.top().first >= H) {
                    cout << S.top().second << ' ';
                    break;
                } 
            }
        }
        else cout << S.top().second << ' ';

        S.push({H,i});
    }

    return 0;
}