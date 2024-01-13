#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K; cin >> N >> K;
    queue<pair<int,int>> Q;
    int num, cnt;
    
    int time[100001];
    for(int i=0; i<100001; i++) {
        time[i] = 100001;
    }
    
    Q.push({N, 0});

    while(1) {
        num = Q.front().first;
        cnt = Q.front().second;
        time[num] = cnt;

        if(num == K) break;
        Q.pop();

        if(num*2 <= 100000 && cnt < time[num*2]) {
            Q.push({num*2, cnt});
            time[num*2] = cnt;
        }
        if(num-1 >= 0 && cnt+1 < time[num-1]) {
            Q.push({num-1, cnt+1});
            time[num-1] = cnt+1;
        }
        if(num+1 <= 100000 && cnt+1 < time[num+1]) {
            Q.push({num+1, cnt+1});
            time[num+1] = cnt+1;
        }
    }

    cout << cnt;

    return 0; 
}