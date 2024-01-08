#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    vector<int> T[N];
    queue<int> Q;
    bool visit[N]{0};
    bool empty[N]{0};
    int leaf = 0;

    for(int i=0; i<N; i++) {
        int parent; cin >> parent;
        if(parent != -1) T[parent].push_back(i);
    }

    for(int i=0; i<N; i++) {
        if(T[i].empty()) {
            empty[i] = 1;
            leaf++;
        }
    }

    int erase; cin >> erase;

    Q.push(erase);

    while(!Q.empty()) {
        int node = Q.front();
        visit[node] = 1;
        Q.pop();

        for(int i=0; i<T[node].size(); i++) {
            int tmp = T[node][i]; 
            if(!visit[tmp]) Q.push(tmp);
        }
    }

    vector<int> NT[N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<T[i].size(); j++) {
            if(T[i][j] != erase) NT[i].push_back(T[i][j]);
        }
    }

    for(int i=0; i<N; i++) {
        if(visit[i]==1 && NT[i].empty()) leaf--;
        else if(empty[i]!=1 && NT[i].empty()) leaf++;
    }

    cout << leaf;

    return 0;
}