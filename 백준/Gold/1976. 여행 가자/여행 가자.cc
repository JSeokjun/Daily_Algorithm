#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> V(201);
vector<bool> P(1001, false);
vector<int> C(1001, 0); 

void dfs(int loc) {
    P[loc] = false;
    C[loc]--;

    for (int i=0; i<V[loc].size(); i++) {
        if (C[V[loc][i]] != 0) {
            dfs(V[loc][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            bool is_connect; cin >> is_connect;
            if (is_connect) {
                V[i].push_back(j);
            }
        }
    }

    for (int i=1; i<=N; i++) {
        C[i] = V[i].size();
    }

    int country;
    
    for (int i=0; i<M; i++) {
        cin >> country;
        P[country] = true;
    }

    dfs(country);

    bool visited_all = true;
    for (int i=1; i<=1000; i++) {
        if (P[i]) {
            visited_all = false;
            break;
        }
    }

    if (visited_all) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    
    return 0;
}