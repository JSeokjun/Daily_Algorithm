#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N;
bool check;
vector<int> G[101];
int visit[101];
int result[101][101];

void dfs(int s, int e) {
    visit[s] = 1;

    for(int now : G[s]) {
        if(now == e) {
            check = 1;
            break;
        }
        if(!visit[now]) dfs(now, e);
    }
}

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            int tmp; cin >> tmp;
            if(tmp) G[i].push_back(j);
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            dfs(i, j);
            if(check) result[i][j] = 1;
            check = 0;
            memset(visit, 0, sizeof(visit));
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
}   