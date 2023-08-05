#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool vis[25][25];
int cnt = 0;

void dfs(int x, int y) {
    vis[x][y] = 0;

    if(x!=24) if(vis[x+1][y]) dfs(x+1, y);
    if(y!=24) if(vis[x][y+1]) dfs(x, y+1);
    if(x!=0) if(vis[x-1][y]) dfs(x-1, y);
    if(y!=0) if(vis[x][y-1]) dfs(x, y-1);

    cnt++;
}

int main() {
    int N, num=0;
    string str;
    vector<int> vec;
    cin >> N;
    cin.ignore();

    for(int i=0; i<N; i++) {
        getline(cin, str);
        for(int j=0; j<N; j++) {
            vis[i][j] = str[j]-48;
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(vis[i][j]) {
                dfs(i, j);
                vec.push_back(cnt);
                cnt = 0;
                num++;
            }
        }
    }
    sort(vec.begin(), vec.end());

    cout << num << '\n';
    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << '\n';
    }
}