#include <iostream>
#include <queue>
using namespace std;

int main() {
    long long int A, B, x, y, cnt;
    bool v = false;
    cin >> A >> B;

    queue<pair<long long int,long long int>> q;
    q.push(make_pair(A, 0));

    while(!q.empty()) {
        A = q.front().first;
        cnt = q.front().second;
        q.pop();
        if(A==B) {
            v = true;
            break;
        }
        else if(A<B) {
            x = A*2;
            y = A*10+1;

            q.push(make_pair(x,cnt+1));
            q.push(make_pair(y,cnt+1));
        }
    }

    if(v) cout << cnt+1;
    else cout << -1;
}