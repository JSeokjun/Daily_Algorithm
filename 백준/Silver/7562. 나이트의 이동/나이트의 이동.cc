#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;
    int row[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int col[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
    
    for(int i=0; i<T; i++) {
        int len, now[2], end[2];
        cin >> len >> now[0] >> now[1] >> end[0] >> end[1];

        if(now[0]==end[0] && now[1]==end[1]) {
            cout << 0 << '\n';
            continue;
        }
        
        int visit[len][len]{};
        int time = 0;
        bool E = 0;

        queue<tuple<int,int,int>> Q;
        Q.push({now[0],now[1],0});
        visit[now[0]][now[1]]++;

        while(1) {
            now[0] = get<0>(Q.front());
            now[1] = get<1>(Q.front());
            time = get<2>(Q.front())+1;
            Q.pop();
            
            for(int j=0; j<8; j++) {
                int next_r = now[0] + row[j];
                int next_c = now[1] + col[j];

                if(next_r==end[0] && next_c==end[1]) {
                    E = 1;
                    break;
                }
                
                if(visit[next_r][next_c]==0 
                && next_r>=0 && next_r<len
                && next_c>=0 && next_c<len) {
                    Q.push({next_r,next_c,time});
                    visit[next_r][next_c]++;
                }
            }

            if(E) break;
        }

        cout << time << '\n';
    }

    return 0;
}   