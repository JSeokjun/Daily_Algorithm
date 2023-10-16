#include <iostream>
using namespace std;

int x=0, y=0, z=0;
int arr[3*3*3*3*3*3*3][3*3*3*3*3*3*3];

void div(int n, int r, int c) {
    int tmp = arr[r][c];
    bool check = 0;
    for(int i=r; i<r+n; i++) {
        for(int j=c; j<c+n; j++) { 
            if(tmp!=arr[i][j]) {
                check = 1;
                break;
            }
        }
        if(check) break;
    }
    if(n==1 || !check) {
        if(tmp==-1) x++;
        else if(tmp==0) y++;
        else z++;
    }
    else {
        int d = n/3;
        div(d, r, c);
        div(d, r, c+d);
        div(d, r, c+2*d);
        div(d, r+d, c);
        div(d, r+d, c+d);
        div(d, r+d, c+2*d);
        div(d, r+2*d, c);
        div(d, r+2*d, c+d);
        div(d, r+2*d, c+2*d);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    div(N, 0, 0);
    cout << x << '\n' << y << '\n' << z;
}   