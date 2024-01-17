#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W; cin >> H >> W;
    stack<int> S;
    int max = 0, cnt = 0;

    while(W--) {
        int h; cin >> h;
        S.push(h);

        if(S.top()!=0 && S.top()>=max) {
            int tmp = S.top();
            S.pop();

            while(!S.empty()) {
                cnt += max - S.top();
                S.pop();
            }
            S.push(tmp);
            max = tmp;
        }
    }

    int size = S.size();
    stack<int> S2;

    if(size > 2) {
        max = 0;
        while(size--) {
            int h = S.top();
            S.pop();
            S2.push(h);

            if(S2.top()!=0 && S2.top()>=max) {
                int tmp = S2.top();
                S2.pop();
                
                while(!S2.empty()) {
                    cnt += max - S2.top();
                    S2.pop();
                }
                S2.push(tmp);
                max = tmp;
            }
        }
    }

    cout << cnt;

    return 0;
}