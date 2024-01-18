#include <iostream>
using namespace std;

int arr[501][501];
int save[501][501];

int dp(int x, int y) {
    if(x==1 && y==1) return arr[1][1];
    else {
        if(y == 1) {
            if(save[x-1][y]) return save[x-1][y] + arr[x][y]; 
            else {
                save[x-1][y] = dp(x-1, y); 
                return save[x-1][y] + arr[x][y];
            }
        }
        else if(arr[x-1][y] == 0) {
            if(save[x-1][y-1]) return save[x-1][y-1] + arr[x][y];
            else {
                save[x-1][y-1] = dp(x-1, y-1);
                return save[x-1][y-1] + arr[x][y];
            }
        }
        else {
            if(save[x-1][y] && save[x-1][y-1]) return max(save[x-1][y], save[x-1][y-1]) + arr[x][y];
            else if(save[x-1][y]) {
                save[x-1][y-1] = dp(x-1, y-1);
                return max(save[x-1][y], save[x-1][y-1]) + arr[x][y];
            }
            else if(save[x-1][y-1]) {
                save[x-1][y] = dp(x-1, y);
                return max(save[x-1][y], save[x-1][y-1]) + arr[x][y];
            }
            else {
                save[x-1][y-1] = dp(x-1, y-1);
                save[x-1][y] = dp(x-1, y);
                return max(save[x-1][y], save[x-1][y-1]) + arr[x][y];
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<i+1; j++) {
            cin >> arr[i][j];
        }
    }
    
    int max_num = 0;
    
    for(int i=1; i<=n; i++) {
        int tmp = dp(n, i);
        if(tmp > max_num) max_num = tmp;
    }

    cout << max_num;

    return 0;
}