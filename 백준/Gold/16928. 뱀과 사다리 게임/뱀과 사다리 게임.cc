#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M; cin >> N >> M;
    int L[101]{0};

    for(int i=0; i<N+M; i++) {
        int x, y; cin >> x >> y;
        L[x] = y;
    }

    queue<pair<int,int>> Q;
    bool visit[101]{0};
    Q.push({1,0});
    visit[1] = 1;

    while(1) {
        int num = Q.front().first;
        int cnt = Q.front().second;
        
        Q.pop();

        for(int i=1; i<=6; i++) {
            if(!visit[num+i] && num+i < 100) {
                if(L[num+i] != 0) Q.push({L[num+i],cnt+1});
                else Q.push({num+i,cnt+1});
                visit[num+i] = 1;
            }
            else if(num+i == 100) {
                cout << cnt+1;
                return 0;
            }
        }
    }

    return 0;
}   