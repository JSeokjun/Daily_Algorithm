#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int problem_num = 1;

    while(1) {
        int N; cin >> N;
        if (N == 0) break;
        
        vector<vector<int>> V(N);
        vector<vector<int>> D(N);
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> Q;

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                int num; cin >> num;
                V[i].push_back(num);
                D[i].push_back(9999);
            }
        }

        Q.push({V[0][0], 0, 0});
        D[0][0] = V[0][0];

        while (!Q.empty()) {
            int rupee = get<0>(Q.top());
            int x = get<1>(Q.top());
            int y = get<2>(Q.top());

            Q.pop();

            if (D[x][y] < rupee) continue;

            for (int i=0; i<4; i++) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];

                if ((next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) && (D[next_x][next_y] > V[next_x][next_y] + rupee)) {
                    D[next_x][next_y] = V[next_x][next_y] + rupee;
                    Q.push({V[next_x][next_y] + rupee, next_x, next_y});
                }
            }
        }

        cout << "Problem " << problem_num << ": " << D[N-1][N-1] << '\n';  
        
        problem_num++;
    }    
    
    return 0;
}