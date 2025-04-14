#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int P, M; cin >> P >> M;
    vector<vector<pair<int,string>>> V(P);
    vector<int> H;
    int level = 0;
    string id = "";

    cin >> level >> id;
    V[0].push_back({level, id});
    H.push_back(level);

    for (int i=1; i<P; i++) {
        cin >> level >> id;
        bool new_room = true;

        for (int j=0; j<H.size(); j++) {
            if (V[j].size() < M && H[j] - 10 <= level && H[j] + 10 >= level) {
                V[j].push_back({level, id});
                new_room = false;
                break;
            }
        }

        if (new_room) {
            V[H.size()].push_back({level, id});
            H.push_back(level);
        }
    }

    for (int i=0; i<H.size(); i++) {
        sort(V[i].begin(), V[i].end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
    }

    for (int i=0; i<H.size(); i++) {
        if (V[i].size() == M) cout << "Started!" << '\n';
        else cout << "Waiting!" << '\n';

        for (int j=0; j<V[i].size(); j++) {
            cout << V[i][j].first << ' ' << V[i][j].second << '\n'; 
        }
    }

    return 0;
}
