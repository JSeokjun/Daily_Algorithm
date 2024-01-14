#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K; cin >> N >> K;
    queue<pair<int,int>> Q;
    int num, cnt;
    
    bool visit[100001]{0};
    int parent[100001];
    
    Q.push({N, 0});
    visit[N] = 1;

    while(1) {
        num = Q.front().first;
        cnt = Q.front().second;

        if(num == K) break;
        Q.pop();

        if(num-1 >= 0 && !visit[num-1]) {
            Q.push({num-1, cnt+1});
            visit[num-1] = 1;
            parent[num-1] = num;
        }
        if(num+1 <= 100000 && !visit[num+1]) {
            Q.push({num+1, cnt+1});
            visit[num+1] = 1;
            parent[num+1] = num;
        }
        if(num*2 <= 100000 && !visit[num*2]) {
            Q.push({num*2, cnt+1});
            visit[num*2] = 1;
            parent[num*2] = num;
        }
    }

    cout << cnt << '\n';

    int now = K;
    stack<int> route;
    route.push(now);

    while(now != N) {
        route.push(parent[now]);
        now = parent[now];
    }
    
    while(!route.empty()) {
        cout << route.top() << ' ';
        route.pop();
    }

    return 0; 
}