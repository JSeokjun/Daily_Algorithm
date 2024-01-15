#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int,int,int>> T[1023];
int order[1023];
int idx = 0;

void dfs(int x) {
    int left = get<0>(T[x][0]);
    int right = get<1>(T[x][0]);

    if(left != 0) dfs(left);

    get<2>(T[x][0]) = order[idx];
    idx++;

    if(right != 0) dfs(right);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int K; cin >> K;
    if(K==1) {
        int tmp; cin >> tmp;
        cout << tmp;
        return 0;
    }

    int not_leaf = 1;
    for(int i=0; i<K-1; i++) {
        not_leaf *= 2;
    }
    
    int num_node = not_leaf*2 - 1;
    not_leaf -= 1;
    int cnt = 1;

    for(int i=0; i<not_leaf; i++) {
        cin >> order[i];
        T[i].push_back({cnt, cnt+1, 0});
        cnt += 2;
    }
    
    for(int i=not_leaf; i<num_node; i++) {
        cin >> order[i];
        T[i].push_back({0, 0, 0});
    }

    dfs(0);

    int tree[K], idx=0;
    tree[0] = 2;
    for(int i=1; i<K; i++) {
        tree[i] = tree[i-1]*2;
    }

    for(int i=0; i<num_node; i++) {
        if(i == tree[idx]-1) {
            cout << '\n';
            idx++;
        }
        cout << get<2>(T[i][0]) << ' ';
    }
    
    return 0;
}