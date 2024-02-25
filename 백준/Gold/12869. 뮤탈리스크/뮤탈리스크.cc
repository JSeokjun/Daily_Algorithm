#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin >> N;
    int H[N], cnt;

    if(N == 1) {
        cin >> H[0];
        H[0] % 9 == 0 ? cout << H[0] / 9 : cout << H[0] / 9 + 1;
    }
    else if(N == 2) {
        queue<tuple<int,int,int>> Q;
        cin >> H[0] >> H[1];
        Q.push({H[0], H[1], 0});

        while(1) {
            H[0] = get<0>(Q.front());
            H[1] = get<1>(Q.front());
            cnt = get<2>(Q.front());
            Q.pop();

            if(H[0] <= 0 && H[1] <= 0) {
                cout << cnt;
                break;
            }
            else {
                Q.push({H[0]-9, H[1]-3, cnt+1});
                Q.push({H[0]-3, H[1]-9, cnt+1});
            }
        }
    }
    else {
        queue<tuple<int,int,int,int>> Q;
        cin >> H[0] >> H[1] >> H[2];
        Q.push({H[0], H[1], H[2], 0});

        while(1) {
            H[0] = get<0>(Q.front());
            H[1] = get<1>(Q.front());
            H[2] = get<2>(Q.front());
            cnt = get<3>(Q.front());
            Q.pop();

            if(H[0] <= 0 && H[1] <= 0 && H[2] <= 0) {
                cout << cnt;
                break;
            }
            else if(H[0]-9 > 9 && H[1]-9 > 9 && H[2]-9 > 9) {
                if(H[0]>=H[1] && H[0]>=H[2] && H[1]>=H[2]) {
                    Q.push({H[0]-9, H[1]-3, H[2]-1, cnt+1});
                }
                else if(H[0]>=H[1] && H[0]>=H[2] && H[2]>=H[1]) {
                    Q.push({H[0]-9, H[1]-1, H[2]-3, cnt+1});
                }
                else if(H[1]>=H[0] && H[1]>=H[2] && H[1]>=H[2]) {
                    Q.push({H[0]-3, H[1]-9, H[2]-1, cnt+1});
                }
                else if(H[1]>=H[0] && H[1]>=H[2] && H[2]>=H[1]) {
                    Q.push({H[0]-1, H[1]-9, H[2]-3, cnt+1});
                }
                else if(H[2]>=H[0] && H[2]>=H[1] && H[0]>=H[1]) {
                    Q.push({H[0]-3, H[1]-1, H[2]-9, cnt+1});
                }
                else {
                    Q.push({H[0]-1, H[1]-3, H[2]-9, cnt+1});
                }
            }
            else {
                if(H[0] <= 0 && H[1] <= 0) {
                    Q.push({0, 0, H[2]-9, cnt+1});
                }
                else if(H[0] <= 0 && H[2] <= 0) {
                    Q.push({0, H[1]-9, 0, cnt+1});    
                }
                else if(H[1] <= 0 && H[2] <= 0) {
                    Q.push({H[0]-9, 0, 0, cnt+1});  
                }
                else if(H[0] <= 0) {
                    Q.push({0, H[1]-9, H[2]-3, cnt+1});
                    Q.push({0, H[1]-3, H[2]-9, cnt+1});
                }
                else if(H[1] <= 0) {
                    Q.push({H[0]-9, 0, H[2]-3, cnt+1});
                    Q.push({H[0]-3, 0, H[2]-9, cnt+1});
                }
                else if(H[2] <= 0) {
                    Q.push({H[0]-9, H[1]-3, 0, cnt+1});
                    Q.push({H[0]-3, H[1]-9, 0, cnt+1});
                }
                else {
                    Q.push({H[0]-9, H[1]-3, H[2]-1, cnt+1});
                    Q.push({H[0]-9, H[1]-1, H[2]-3, cnt+1});
                    Q.push({H[0]-3, H[1]-9, H[2]-1, cnt+1});
                    Q.push({H[0]-3, H[1]-1, H[2]-9, cnt+1});
                    Q.push({H[0]-1, H[1]-9, H[2]-3, cnt+1});
                    Q.push({H[0]-1, H[1]-3, H[2]-9, cnt+1});
                }
            }
        }
    }

    return 0;
}   