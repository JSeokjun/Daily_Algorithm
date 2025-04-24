#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, D; cin >> N >> D;
    vector<tuple<int,int,int>> fastRoad;
    queue<pair<int,int>> currentState;
    int sortestDst = D;

    for (int i=0; i<N; i++) {
        int start, end, len; cin >> start >> end >> len;
        if (end <= D) {
            fastRoad.push_back({start, end, len});
        }
    }

    sort(fastRoad.begin(), fastRoad.end(), [](auto &a, auto &b) {
        return get<0>(a) < get<0>(b);
    });

    currentState.push({0, 0});

    while (!currentState.empty()) {
        int currentLoc = currentState.front().first;
        int currentDst = currentState.front().second;

        currentState.pop();

        for (int i=0; i<fastRoad.size(); i++) {
            if (get<0>(fastRoad[i]) >= currentLoc) {
                currentState.push({get<1>(fastRoad[i]), currentDst + (get<0>(fastRoad[i]) - currentLoc + get<2>(fastRoad[i]))});
            }
        }

        int finalDst = currentDst + (D - currentLoc);

        if (finalDst < sortestDst) {
            sortestDst = finalDst; 
        }
    }

    cout << sortestDst;

    return 0;
}