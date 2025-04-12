#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int N, M; cin >> N >> M;
    vector<pair<string, int>> V;
    vector<tuple<int,int,string>> V2;

    for (int i=0; i<N; i++) {
        string name; cin >> name;
        int power; cin >> power;

        V.push_back({name, power});
    }

    for (int i=0; i<M; i++) {
        int power; cin >> power;
        V2.push_back({power, i, ""});
    }

    sort(V2.begin(), V2.end(), [](auto &a, auto &b){
        return get<0>(a) < get<0>(b);
    });

    int i = 0;

    for (int j=0; j<M; j++) {
        while (1) {
            if (get<0>(V2[j]) <= V[i].second) {
                get<2>(V2[j]) = V[i].first;
                break;
            }
            else {
                i++;
            }
        }
    }

    sort(V2.begin(), V2.end(), [](auto &a, auto &b){
        return get<1>(a) < get<1>(b);
    });

    for (int i=0; i<M; i++) {
        cout << get<2>(V2[i]) << '\n';
    }

    return 0;
}