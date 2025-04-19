#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<pair<int,int>> V;
    vector<int> answer(N, 0);
    set<int> S;
 
    for (int i=1; i<=N; i++) {
        int num; cin >> num;
        V.push_back({i, num});
        S.insert(i);
    }

    answer[V[0].second] = 1;
    S.erase(1);
    
    while (!S.empty()) {

        for (int i=0; i<N; i++) {
            if (S.find(i+1) == S.end()) continue;

            int possible_cnt = 0;
            int possible_index = 0;
            int height = V[i].first;
            int taller = V[i].second;

            for (int j=taller; j<N; j++) {
                if (answer[j] != 0) continue; 
                int cnt = 0;

                for (int k=0; k<j; k++) {
                    if (answer[k] == 0 || answer[k] > height) cnt++;
                }

                if (cnt == taller) {
                    possible_cnt++;
                    possible_index = j;
                }
            }

            if (possible_cnt == 1) {
                answer[possible_index] = height;
                S.erase(height);
            }
        }
        break;
    }

    for (int i=0; i<N; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}