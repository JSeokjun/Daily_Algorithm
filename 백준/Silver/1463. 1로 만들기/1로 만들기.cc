#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    queue<pair<int,int>> Q;
    int num, cnt;
    Q.push({N,0});

    while(1) {
        num = Q.front().first;
        cnt = Q.front().second;
        if(num == 1) break;
        Q.pop();

        if(num%3 == 0) Q.push({num/3, cnt+1});
        if(num%2 == 0) Q.push({num/2, cnt+1});
        Q.push({num-1, cnt+1});
    }

    cout << cnt;

    return 0; 
}