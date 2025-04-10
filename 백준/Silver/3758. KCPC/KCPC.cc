#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int T; cin >> T;

    while(T--) {
        int n, k, t, m; cin >> n >> k >> t >> m;
        vector<tuple<int,int,int,int>> teamLog(n);
        int scoreBoard[n][k];

        for (int i=0; i<n; i++) {
            teamLog[i] = {0, 0, 0, 0};
            for (int j=0; j<k; j++) {
                scoreBoard[i][j] = 0;
            }
        }

        for (int time=0; time<m; time++) {
            int i, j, s; cin >> i >> j >> s;
            
            if (scoreBoard[i-1][j-1] < s) {
                teamLog[i-1] = {i, get<1>(teamLog[i-1])-scoreBoard[i-1][j-1]+s, get<2>(teamLog[i-1])+1, time};
                scoreBoard[i-1][j-1] = s;
            }
            else {
                teamLog[i-1] = {i, get<1>(teamLog[i-1]), get<2>(teamLog[i-1])+1, time};
            }
        }

        sort(teamLog.begin(), teamLog.end(), [](auto &a, auto &b){
            if (get<1>(a) != get<1>(b)) {
                return get<1>(a) > get<1>(b);
            }
            if (get<2>(a) != get<2>(b)) {
                return get<2>(a) < get<2>(b);
            }
            return get<3>(a) < get<3>(b);
        });

        int rank = 1;

        for (int i=0; i<n; i++) {
            if (get<0>(teamLog[i]) == t) {
                cout << rank << '\n';
                break;
            }

            if (get<1>(teamLog[i]) != get<1>(teamLog[i+1]) || 
                get<2>(teamLog[i]) != get<2>(teamLog[i+1]) || 
                get<3>(teamLog[i]) != get<3>(teamLog[i+1])) {
                    rank = i+2;
                }
        }    
    }
    
    return 0;
}