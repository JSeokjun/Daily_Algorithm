#include <iostream>
#include <string.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    string tmp; cin >> tmp;
    
    bool maze[101][101]{0};
    int x = 50, y = 50;
    int dx = 1, dy = 0;
    maze[50][50] = 1;
    
    for(int i=0; i<N; i++) {
        char M = tmp[i];

        if(M == 'F') {
            x = x + dx;
            y = y + dy;
            maze[x][y] = 1;
            continue;
        }
        
        if(dx==0 && dy==1) {
            if(M == 'R') {
                dx = 1; dy = 0;
            }
            else if(M == 'L') {
                dx = -1; dy = 0;
            }
        }
        else if(dx==0 && dy==-1) {
            if(M == 'R') {
                dx = -1; dy = 0;
            }
            else if(M == 'L') {
                dx = 1; dy = 0;
            }
        }
        else if(dx==1 && dy==0) {
            if(M == 'R') {
                dx = 0; dy = -1;
            }
            else if(M == 'L') {
                dx = 0; dy = 1;
            }
        }
        else if(dx==-1 && dy==0) {
            if(M == 'R') {
                dx = 0; dy = 1;
            }
            else if(M == 'L') {
                dx = 0; dy = -1;
            }
        }
    }

    int T, B, L, R;
    bool check = 0;

    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) {
            if(maze[i][j] == 1) {
                T = i;
                check = 1;
                break;
            }
        }
        if(check) break;
    }
    check = 0;
    for(int i=100; i>=0; i--) {
        for(int j=0; j<100; j++) {
            if(maze[i][j] == 1) {
                B = i;
                check = 1;
                break;
            }
        }
        if(check) break;
    }
    check = 0;
    for(int i=0; i<101; i++) {
        for(int j=0; j<101; j++) {
            if(maze[j][i] == 1) {
                L = i;
                check = 1;
                break;
            }
        }
        if(check) break;
    }
    check = 0;
    for(int i=100; i>=0; i--) {
        for(int j=0; j<100; j++) {
            if(maze[j][i] == 1) {
                R = i;
                check = 1;
                break;
            }
        }
        if(check) break;
    }
    
    for(int i=T; i<=B; i++) {
        for(int j=L; j<=R; j++) {
            if(maze[i][j] == 1) cout << '.';
            else cout << '#'; 
        }
        cout << '\n';
    }

    return 0;
}