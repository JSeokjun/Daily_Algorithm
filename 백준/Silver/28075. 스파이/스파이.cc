#include <iostream>
using namespace std;

int N, M, P[6], cnt; 

int dfs(int x, int m, int d) {
    if(d == N) {
        if(m >= M) cnt++;
        return 0;
    }

    if(x==0 || x==3) {
        dfs(0, m+P[0]/2, d+1);
        dfs(1, m+P[1], d+1);
        dfs(2, m+P[2], d+1);
        dfs(3, m+P[3]/2, d+1);
        dfs(4, m+P[4], d+1);
        dfs(5, m+P[5], d+1);
    }
    else if(x==1 || x==4) {
        dfs(0, m+P[0], d+1);
        dfs(1, m+P[1]/2, d+1);
        dfs(2, m+P[2], d+1);
        dfs(3, m+P[3], d+1);
        dfs(4, m+P[4]/2, d+1);
        dfs(5, m+P[5], d+1);
    }
    else if(x==2 || x==5) {
        dfs(0, m+P[0], d+1);
        dfs(1, m+P[1], d+1);
        dfs(2, m+P[2]/2, d+1);
        dfs(3, m+P[3], d+1);
        dfs(4, m+P[4], d+1);
        dfs(5, m+P[5]/2, d+1);
    }
    
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> M;
    for(int i=0; i<6; i++) {
        cin >> P[i];
    }

    for(int i=0; i<6; i++) {
        dfs(i, P[i], 1);
    }

    cout << cnt;

    return 0;
}   